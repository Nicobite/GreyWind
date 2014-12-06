/*
 * @video_stage.c
 * @author Grey Wind
 * @date 2014
 *
 *  Video pipeline thread
 *
 */

#include "Video/video.h"

#define BUFFERER_ENABLED 1

//PIPELINE_HANDLE pipeline_handle;

static int32_t pixbuf_width = 0;
static int32_t pixbuf_height = 0;
static int32_t pixbuf_rowstride = 0;
static uint8_t* pixbuf_data = NULL;
static vp_os_mutex_t  video_update_lock = PTHREAD_MUTEX_INITIALIZER;

#if BUFFERER_ENABLED
sem_t *sem_v_empty;
sem_t *sem_v_complete;
#endif


C_RESULT output_gtk_stage_open( vp_stages_gtk_config_t *cfg, vp_api_io_data_t *in, vp_api_io_data_t *out)
{
#if BUFFERER_ENABLED
    sem_v_empty = sem_open(VID_SEM_E_PATH, O_CREAT, 0666, 0);
    sem_v_complete = sem_open(VID_SEM_F_PATH, O_CREAT, 0666, 0);

  #if 0
    printf("[Debug] Video pipe has been created.\n");
  #endif
#endif

  return (SUCCESS);
}

C_RESULT output_gtk_stage_transform( vp_stages_gtk_config_t *cfg, vp_api_io_data_t *in, vp_api_io_data_t *out)
{
    vp_os_mutex_lock(&video_update_lock);
        // Get a reference to the last decoded picture
        video_decoder_config_t * dec_config;
        dec_config = (video_decoder_config_t *) cfg->last_decoded_frame_info;

        pixbuf_width = dec_config->src_picture->width;
        pixbuf_height = dec_config->src_picture->height;
        pixbuf_rowstride = dec_config->rowstride;

        pixbuf_data = (uint8_t*) in->buffers[in->indexBuffer];
    vp_os_mutex_unlock(&video_update_lock);

    gdk_threads_enter();

    // GdkPixbuf structure to store the displayed picture
    static GdkPixbuf *pixbuf = NULL;

    if(pixbuf!=NULL)
    {
        g_object_unref(pixbuf);
        pixbuf=NULL;
    }

    pixbuf = gdk_pixbuf_new_from_data(pixbuf_data,
        GDK_COLORSPACE_RGB,
        FALSE,              // No alpha channel
        8,                  // 8 bits per pixel
        pixbuf_width,       // Image width
        pixbuf_height,      // Image width
        pixbuf_rowstride,   // New pixel every 3 bytes (3channel per pixel)
        NULL,               // Function pointers
        NULL);

    //Video frames are written into temporary files in the system and synchronisation is
    //established with a consumer thread.

    if(sem_trywait(sem_v_empty)==0){

        GError *error = NULL;
        gdk_pixbuf_save(pixbuf, VID_BUFFER_PATH,"bmp", &error, NULL);

        sem_post(sem_v_complete);
    }


    gdk_threads_leave();

    return (SUCCESS);
}

C_RESULT output_gtk_stage_close( vp_stages_gtk_config_t *cfg, vp_api_io_data_t *in, vp_api_io_data_t *out)
{
#if BUFFERER_ENABLED
    sem_close(sem_v_empty);
    sem_close(sem_v_complete);
    sem_destroy(sem_v_empty);
    sem_destroy(sem_v_complete);
    sem_unlink(VID_SEM_E_PATH);
    sem_unlink(VID_SEM_F_PATH);
    unlink(VID_BUFFER_PATH);
  return (SUCCESS);
#endif
}

//Pipeline stage definition
const vp_api_stage_funcs_t vp_stages_output_gtk_funcs = {
    NULL,
    (vp_api_stage_open_t) output_gtk_stage_open,
    (vp_api_stage_transform_t) output_gtk_stage_transform,
    (vp_api_stage_close_t) output_gtk_stage_close
};


void start_video_thread(){
    //Video pipeline
    #define NB_POST_STAGES 1
    specific_parameters_t * params = (specific_parameters_t *)vp_os_calloc(1,sizeof(specific_parameters_t));
    video_stages_config(params);
    START_THREAD(video_stage, params);
    video_stage_init();
    video_stage_resume_thread();
}

void stop_video_thread(){
    video_stage_resume_thread(); //Resume thread to kill it !
    video_stage_resume_thread();
    video_stage_resume_thread();
    video_stage_resume_thread();
    video_stage_resume_thread();
    video_stage_resume_thread();
    video_stage_resume_thread();
    video_stage_resume_thread();

    JOIN_THREAD(video_stage);

}

/* Function to wrap video stages configuration */
void video_stages_config(specific_parameters_t * params){

    uint8_t post_stages_index = 0;

    // alloc the intermediate vars
    specific_stages_t * pre_stages  = (specific_stages_t*)vp_os_calloc(1, sizeof(specific_stages_t));
    specific_stages_t * post_stages = (specific_stages_t*)vp_os_calloc(1, sizeof(specific_stages_t));
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
    pre_stages->stages_list  = NULL;
    post_stages->stages_list = (vp_api_io_stage_t*)vp_os_calloc(NB_POST_STAGES,sizeof(vp_api_io_stage_t));

    // pre-stages (empty)
    // post-stages
    vp_os_memset(&gtkconf,         0, sizeof( gtkconf ));
    gtkconf.rowstride               = out_picture->width * 3;
    gtkconf.last_decoded_frame_info = (void*)&vec;
    gtkconf.desired_display_width   = 0;  /* auto */
    gtkconf.desired_display_height  = 0;  /* auto */
    gtkconf.gdk_interpolation_mode  = 0;  /* fastest */
    post_stages->stages_list[post_stages_index].name    = "(Gtk display)";
    post_stages->stages_list[post_stages_index].type    = VP_API_OUTPUT_SDL;
    post_stages->stages_list[post_stages_index].cfg     = (void*)&gtkconf;
    post_stages->stages_list[post_stages_index++].funcs = vp_stages_output_gtk_funcs;

    // lists sizes
    pre_stages->length  = 0;
    post_stages->length = post_stages_index;

    // passing values to param
    params->in_pic = in_picture;
    params->out_pic = out_picture;
    params->pre_processing_stages_list  = pre_stages;
    params->post_processing_stages_list = post_stages;
    params->needSetPriority = 0;
    params->priority = 0;
}
