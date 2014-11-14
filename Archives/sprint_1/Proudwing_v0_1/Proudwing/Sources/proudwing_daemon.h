#ifndef _MYKONOS_TESTING_TOOL_H_
#define _MYKONOS_TESTING_TOOL_H_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#include <errno.h>
#include <fcntl.h>
#include <stddef.h>
#include <unistd.h>
#include <semaphore.h>
#include <sys/stat.h>

#include <sys/time.h>
#include <time.h>

#include <VP_Os/vp_os_signal.h>
#include <VP_Api/vp_api_picture.h>

#include <ardrone_api.h>

#include <ardrone_tool/ardrone_version.h>
#include <ardrone_tool/ardrone_tool.h>
#include <ardrone_tool/ardrone_tool_configuration.h>
#include <ardrone_tool/Control/ardrone_control.h>
#include <ardrone_tool/Navdata/ardrone_navdata_client.h>
#include <ardrone_tool/UI/ardrone_input.h>
#include <ardrone_tool/Com/config_com.h>
#include <ardrone_tool/Video/video_stage.h>
#include <ardrone_tool/Video/video_recorder_pipeline.h>

#ifndef STREAM_WIDTH
#define STREAM_WIDTH QVGA_WIDTH
#endif
#ifndef STREAM_HEIGHT
#define STREAM_HEIGHT QVGA_HEIGHT
#endif

C_RESULT signal_exit();

void video_stages_config(specific_parameters_t * params);

#endif // _MYKONOS_TESTING_TOOL_H_
