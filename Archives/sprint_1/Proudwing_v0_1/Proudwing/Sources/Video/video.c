/*
 * @video_stage.c
 * @author Grey Wind
 * @date 2014
 *
 *  Video pipeline thread
 *
 */

#include "Video/video.h"
#include "UI/gui.h"

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

#if BUFFERER_ENABLED
    //Video frames are written into temporary files in the system and synchronisation is
    //established with a consumer thread.

    //while(transferred < pixbuf_size){
#if DEBUG
    printf("Waiting...\n");
#endif
    if(sem_trywait(sem_v_empty)==0){

        GError *error = NULL;
#if DEBUG
        printf("Saving...\n");
#endif
        gdk_pixbuf_save(pixbuf, VID_BUFFER_PATH,"bmp", &error, NULL);
#if DEBUG
        printf("Saved.\n");
#endif
        sem_post(sem_v_complete);
    }
#else
    //Video frames are shown on a local GTK window
    gui_t *gui = get_gui();
    if (gui && gui->cam) // Displaying the image
        gtk_image_set_from_pixbuf(GTK_IMAGE(gui->cam), pixbuf);
#endif

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

