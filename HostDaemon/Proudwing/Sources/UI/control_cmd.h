#ifndef _CONTROL_CMD_H_
#define _CONTROL_CMD_H_

#include <errno.h>
#include <fcntl.h>
#include <string.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <semaphore.h>
#include <sys/stat.h>
#include <linux/joystick.h>

#include <ardrone_api.h>
#include <ardrone_tool/UI/ardrone_input.h>

#include <VP_Os/vp_os_print.h>

#define CMD_BUFFER_PATH "/tmp/proudwing_control"
#define CMD_SEM_E_PATH "/proudwing_ctrl_empty"
#define CMD_SEM_F_PATH  "/proudwing_ctrl_full"

int mkfifo(const char *pfadname, mode_t mode);

extern input_device_t autonom;

C_RESULT open_autonom(void);
C_RESULT update_autonom(void);
C_RESULT close_autonom(void);


#endif // _CONTROL_CMD_H_
