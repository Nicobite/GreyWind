#ifndef _VIDEO_H
#define _VIDEO_H

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

#include <ctype.h>
#include <time.h>
#include <sys/time.h>
#include <termios.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <semaphore.h>
#include <sys/stat.h>

#include <gtk/gtk.h>
#include <gtk/gtkcontainer.h>

#include <VP_Api/vp_api.h>
#include <VP_Api/vp_api_error.h>
#include <VP_Api/vp_api_stage.h>
#include <VP_Api/vp_api_picture.h>
#include <VP_Api/vp_api_thread_helper.h>

#include <VP_Stages/vp_stages_io_file.h>
#include <VP_Stages/vp_stages_i_camif.h>
#include <VP_Stages/vp_stages_yuv2rgb.h>
#include <VP_Stages/vp_stages_buffer_to_picture.h>
#include <VLIB/Stages/vlib_stage_decode.h>

#include <config.h>
#include <VP_Os/vp_os_print.h>
#include <VP_Os/vp_os_malloc.h>
#include <VP_Os/vp_os_delay.h>


#include <ardrone_tool/ardrone_tool.h>
#include <ardrone_tool/Com/config_com.h>
#include <ardrone_tool/Video/video_stage.h>
#include <ardrone_tool/Video/video_recorder_pipeline.h>
#include <ardrone_tool/Video/video_stage_decoder.h>
#include <ardrone_tool/Video/video_com_stage.h>

#ifndef STREAM_WIDTH
#define STREAM_WIDTH 320
#endif
#ifndef STREAM_HEIGHT
#define STREAM_HEIGHT 240
#endif

#define VID_BUFFER_PATH "/tmp/proudwing_vid_frame"
#define VID_SEM_E_PATH "/proudwing_vid_empty"
#define VID_SEM_F_PATH  "/proudwing_vid_complete"

typedef struct _vp_stages_gtk_config_ {
    //  int max_width;
    //  int max_height;
    int rowstride;
    void * last_decoded_frame_info;
    int desired_display_width;
    int desired_display_height;
    int gdk_interpolation_mode;
} vp_stages_gtk_config_t;


C_RESULT output_gtk_stage_open(vp_stages_gtk_config_t *cfg, vp_api_io_data_t *in, vp_api_io_data_t *out);
C_RESULT output_gtk_stage_transform( vp_stages_gtk_config_t*cfg, vp_api_io_data_t *in, vp_api_io_data_t *out);
C_RESULT output_gtk_stage_close( vp_stages_gtk_config_t *cfg, vp_api_io_data_t *in, vp_api_io_data_t *out);

extern const vp_api_stage_funcs_t vp_stages_output_gtk_funcs;
extern video_decoder_config_t vec;
vp_stages_gtk_config_t gtkconf;

void start_video_thread();
void stop_video_thread();
void video_stages_config(specific_parameters_t * params);


#endif // _VIDEO_H
