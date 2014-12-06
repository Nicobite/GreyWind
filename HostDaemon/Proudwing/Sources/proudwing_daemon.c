/**
 *
 * @author GreyWind
 * @date 2014/11/7
 * Main file of Proudwing Communication Daemon
 */
 
#include <ATcodec/ATcodec_api.h>

#include <proudwing_daemon.h>
#include "UI/control_cmd.h"
#include "Video/video.h"
#include "Navdata/navdata.h"

//Compilaton parameters
#define VIDEO_ENABLED 1
#define CONTROL_C_HANDLER_USES_ARDRONE_TOOL_EXIT (1)gui
#define DEBUG (1)

static int32_t exit_ihm_program = 1;
static int video_enabled = 0;
static int video_quality = 0;

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
    printf("Ctrl-C pressed. Killing the application ...\n");

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

    gtk_main_quit ();
    signal_exit ();
    // Flush all streams before terminating
    fflush (NULL);
    usleep (200000); // Wait 200 msec to be sure that flush occured
    printf ("\nAll files were flushed\n");
    exit (0);
}


/* Implementing Custom methods for the main function of an ARDrone application */
int main(int argc, char** argv)
{
    printf("Proudwing - build %s %s\n\n",__DATE__,__TIME__);

    signal (SIGABRT, &controlCHandler);
    signal (SIGTERM, &controlCHandler);
    signal (SIGINT, &controlCHandler);
    int i;
    if(argc > 1){
        printf("[Proudwing] Arguments detected!\n");
        for(i=1; i<argc; i++)
        {
            if(argv[i][0]=='-' && argv[i][1]=='v' && argv[i][2]=='\0'){
                video_enabled = 1;
                printf("[Proudwing] Video stage enabled: %s\n", argv[i]);
            }else if(argv[i][0]=='-' && argv[i][1]=='q' && argv[i][2]=='\0'){
                video_quality = 1;
                printf("[Proudwing] Video codec changed: %s\n", argv[i]);
            }else{
                printf("[Proudwing] Argument not recognised: %s\n", argv[i]);
            }
        }
    }

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

    //Video format configration
    if(video_quality){
        ardrone_application_default_config.video_codec = MP4_360P_CODEC;//H264_360P_CODEC;
    }else{
        ardrone_application_default_config.video_codec = H264_360P_CODEC;
    }

    ardrone_application_default_config.bitrate_ctrl_mode = 1;

    if(video_enabled)
    {
        start_video_thread();
    }

    return C_OK;
}

/* The delegate object calls this method when the event loop exit */
C_RESULT ardrone_tool_shutdown_custom(void)
{
    /* Relinquish all threads of your application */
    if(video_enabled)
    {
        stop_video_thread();
    }

    /* Unregistering for the current device */
    ardrone_tool_input_remove( &autonom );

    return C_OK;
}

/* The event loop calls this method for the exit condition */
bool_t ardrone_tool_exit(){
    return exit_ihm_program == 0;
}


/* Implementing thread table in which you add routines of your application and those provided by the SDK */
BEGIN_THREAD_TABLE
    THREAD_TABLE_ENTRY( ardrone_control			, 20 )
    THREAD_TABLE_ENTRY( navdata_update			, 20 )
    THREAD_TABLE_ENTRY( video_stage				, 20 )
//THREAD_TABLE_ENTRY( ATcodec_Commands_Client	, 20)
END_THREAD_TABLE


