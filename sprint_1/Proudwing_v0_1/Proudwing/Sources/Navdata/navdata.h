#ifndef _NAVDATA_H_
#define _NAVDATA_H_

#include <errno.h>
#include <fcntl.h>
#include <string.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <semaphore.h>
#include <sys/stat.h>

#include <ardrone_tool/Navdata/ardrone_navdata_client.h>

#define NAVD_BUFFER_PATH "/tmp/proudwing_navdata"
#define NAVD_SEM_E_PATH "/proudwing_nd_empty"
#define NAVD_SEM_F_PATH  "/proudwing_nd_full"

int mkfifo(const char *pfadname, mode_t mode);

#endif // _NAVDATA_H_
