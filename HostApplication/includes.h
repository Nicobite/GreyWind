#ifndef INCLUDES_H
#define INCLUDES_H

#include <stdio.h>
#include <QDebug>>

#define SRC_DEFAULT 0
#define SRC_TCP "tcp://@192.168.1.1:5555"

#define DBG 1
#define COLORFUL 0

#if DBG
    #if COLORFUL
        #define DEBUG(arg) printf("%s[DEBUG] %s%s\n","\033[1;36m",arg,"\033[0m")
        #define ERROR(arg) printf("%s[ERROR] %s%s\n","\033[1;31m",arg,"\033[0m")
    #else
        #define DEBUG(arg) printf("[DEBUG] %s\n",arg)
        #define ERROR(arg) printf("[ERROR] %s\n",arg)
    #endif
#else
    #define DEBUG(arg)
    #define ERROR(arg)
#endif

//#define FRAMES_B4_DETECT 40
extern int framesB4Detect;

#endif // INCLUDES_H
