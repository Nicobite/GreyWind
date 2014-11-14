/**
 *
 * @author GreyWind
 * @date 2014/11/7
 * Main file of Proudwing Communication Daemon
 */
 
#include <ATcodec/ATcodec_api.h>

#include <proudwing_daemon.h>
#include "UI/gui.h"
#include "UI/control_cmd.h"
#include "Video/video.h"
#include "Navdata/navdata.h"

//Compilaton parameters
#define VIDEO_ENABLED 1
#define CONTROL_C_HANDLER_USES_ARDRONE_TOOL_EXIT (1)
#define DEBUG (1)

vp_stages_gtk_config_t gtkconf;
extern video_decoder_config_t vec;

static int32_t exit_ihm_program = 1;

C_RESULT signal_exit()
{
  exit_ihm_program = 0;

  return C_OK;
}

/**
 *
 */
void controlCHandler (int signal)
{
	static int callCounter=0;

	callCounter++;

	/* In case GTK in unresponsive, force killing the application */
	if(callCounter>3){
		printf("Ctrl-C pressed several times. Killing the application ...\n");

        sem_unlink(NAVD_SEM_F_PATH);
        sem_unlink(NAVD_SEM_E_PATH);
        unlink(NAVD_BUFFER_PATH);
        sem_unlink(CMD_SEM_F_PATH);
        sem_unlink(CMD_SEM_E_PATH);
        unlink(CMD_BUFFER_PATH);
        sem_unlink(VID_SEM_F_PATH);
        sem_unlink(VID_SEM_E_PATH);
        unlink(VID_BUFFER_PATH);
        exit(-1);
    }

#if CONTROL_C_HANDLER_USES_ARDRONE_TOOL_EXIT
    gtk_main_quit ();
    signal_exit ();
#else
    // Flush all streams before terminating
    fflush (NULL);
    usleep (200000); // Wait 200 msec to be sure that flush occured
    printf ("\nAll files were flushed\n");
    exit (0);
#endif
}

/* Implementing Custom methods for the main function of an ARDrone application */
int main(int argc, char** argv)
{
    printf("Proudwing - build %s %s\n\n",__DATE__,__TIME__);

    init_gui(argc,argv);
    signal (SIGABRT, &controlCHandler);
    signal (SIGTERM, &controlCHandler);
    signal (SIGINT, &controlCHandler);

    return ardrone_tool_main(argc, argv);
}

/* The delegate object calls this method during initialization of an ARDrone application */
C_RESULT ardrone_tool_init_custom(void)
{    
    /** Configure navdata handler    **/
    //Navdata format configuration
    ardrone_application_default_config.navdata_options = NAVDATA_DEMO_TAG &
            ~(NAVDATA_OPTION_MASK(NAVDATA_TRACKERS_SEND_TAG)
            | NAVDATA_OPTION_MASK(NAVDATA_VISION_OF_TAG)
            | NAVDATA_OPTION_MASK(NAVDATA_VISION_PERF_TAG)
            | NAVDATA_OPTION_MASK(NAVDATA_VISION_TAG));//NAVDATA_OPTION_FULL_MASK;
    //Nothing to do here, all is done in Navdata/navdata

    /** Input devices **/
    // Drone movement buffer device
    ardrone_tool_input_add(&autonom);

    // Start all threads of your application, except video (for now)  (ardrone control and navdata handlers are handled by the SDK)
  	START_THREAD( gui, NULL );

#if VIDEO_ENABLED
    //Video format configration
    ardrone_application_default_config.video_codec = H264_360P_CODEC;
    ardrone_application_default_config.bitrate_ctrl_mode = 1;

    //Video pipeline
    #define NB_NAVIGATION_POST_STAGES 10

    specific_parameters_t * params = (specific_parameters_t *)vp_os_calloc(1,sizeof(specific_parameters_t));
    video_stages_config(params);
    START_THREAD(video_stage, params);
    video_stage_init();
    video_stage_resume_thread();
#endif
  return C_OK;
}

/* The delegate object calls this method when the event loop exit */
C_RESULT ardrone_tool_shutdown_custom(void)
{
  /* Relinquish all threads of your application */
	JOIN_THREAD( gui );
#if VIDEO_ENABLED
    video_stage_resume_thread(); //Resume thread to kill it !
    JOIN_THREAD(video_stage);
#endif

  /* Unregistering for the current device */
  ardrone_tool_input_remove( &autonom );

  return C_OK;
}

/* The event loop calls this method for the exit condition */
bool_t ardrone_tool_exit(){
  return exit_ihm_program == 0;
}


#if VIDEO_ENABLED
/* Function to wrap video stages configuration */
void video_stages_config(specific_parameters_t * params){

    uint8_t post_stages_index = 0;

    // alloc the intermediate vars
    specific_stages_t * navigation_pre_stages  = (specific_stages_t*)vp_os_calloc(1, sizeof(specific_stages_t));
    specific_stages_t * navigation_post_stages = (specific_stages_t*)vp_os_calloc(1, sizeof(specific_stages_t));
    vp_api_picture_t  * in_picture             = (vp_api_picture_t*) vp_os_calloc(1, sizeof(vp_api_picture_t));
    vp_api_picture_t  * out_picture            = (vp_api_picture_t*) vp_os_calloc(1, sizeof(vp_api_picture_t));

    // put some constants in in/out_picture
    //TODO check the defines
    in_picture->width          = STREAM_WIDTH;
    in_picture->height         = STREAM_HEIGHT;

    out_picture->framerate     = 20;
    out_picture->format        = PIX_FMT_RGB24;
    out_picture->width         = STREAM_WIDTH;
    out_picture->height        = STREAM_HEIGHT;

    out_picture->y_buf         = vp_os_malloc( STREAM_WIDTH * STREAM_HEIGHT * 3 );
    out_picture->cr_buf        = NULL;
    out_picture->cb_buf        = NULL;

    out_picture->y_line_size   = STREAM_WIDTH * 3;
    out_picture->cb_line_size  = 0;
    out_picture->cr_line_size  = 0;

    // alloc the lists
    navigation_pre_stages->stages_list  = NULL;
    navigation_post_stages->stages_list = (vp_api_io_stage_t*)vp_os_calloc(NB_NAVIGATION_POST_STAGES,sizeof(vp_api_io_stage_t));

    // pre-stages (empty)

    // post-stages
    vp_os_memset(&gtkconf,         0, sizeof( gtkconf ));
    gtkconf.rowstride               = out_picture->width * 3;
    gtkconf.last_decoded_frame_info = (void*)&vec;
    gtkconf.desired_display_width   = 0;  /* auto */
    gtkconf.desired_display_height  = 0;  /* auto */
    gtkconf.gdk_interpolation_mode  = 0;  /* fastest */
    navigation_post_stages->stages_list[post_stages_index].name    = "(Gtk display)";
    navigation_post_stages->stages_list[post_stages_index].type    = VP_API_OUTPUT_SDL;
    navigation_post_stages->stages_list[post_stages_index].cfg     = (void*)&gtkconf;
    navigation_post_stages->stages_list[post_stages_index++].funcs = vp_stages_output_gtk_funcs;

    // lists sizes
    navigation_pre_stages->length  = 0;
    navigation_post_stages->length = post_stages_index;

    // passing values to param
    params->in_pic = in_picture;
    params->out_pic = out_picture;
    params->pre_processing_stages_list  = navigation_pre_stages;
    params->post_processing_stages_list = navigation_post_stages;
    params->needSetPriority = 0;
    params->priority = 0;

}
#endif


/* Implementing thread table in which you add routines of your application and those provided by the SDK */
#if VIDEO_ENABLED
BEGIN_THREAD_TABLE
  	THREAD_TABLE_ENTRY( ardrone_control			, 20 )
    THREAD_TABLE_ENTRY( navdata_update			, 20 )
    THREAD_TABLE_ENTRY( video_stage				, 20 )
    THREAD_TABLE_ENTRY( gui						, 20 )
    THREAD_TABLE_ENTRY( ATcodec_Commands_Client	, 20)
END_THREAD_TABLE
#else
BEGIN_THREAD_TABLE
    THREAD_TABLE_ENTRY( ardrone_control			, 20 )
    THREAD_TABLE_ENTRY( navdata_update			, 20 )
    THREAD_TABLE_ENTRY( gui						, 20 )
    THREAD_TABLE_ENTRY( ATcodec_Commands_Client	, 20)
END_THREAD_TABLE
#endif

