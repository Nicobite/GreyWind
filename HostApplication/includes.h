#ifndef INCLUDES_H
#define INCLUDES_H

#include <stdio.h>
#include <QDebug>
#include <QTime>

#define SRC_DEFAULT 0
#define SRC_TCP "tcp://@192.168.1.1:5555"

#define DBG 1
#define COLORFULC 0

#if DBG
    #if COLORFULC
        #define DEBUG(arg) printf("%s[DEBUG] %s%s\n","\033[1;36m",arg,"\033[0m")
        #define ERROR(arg) printf("%s[ERROR] %s%s\n","\033[1;31m",arg,"\033[0m")
    #else
        #define DEBUG(arg) qDebug() << "[DEBUG"<< QTime::currentTime().toString("hh:mm:ss.zzz") << "] " << arg;
        #define ERROR(arg) qDebug() << "[ERROR] " << arg;
    #endif
#else
    #define DEBUG(arg)
    #define ERROR(arg)
#endif

//#define FRAMES_B4_DETECT 40
extern int framesB4Detect;

/* S+: pour integration, temp */
#define NBM 0
/* S- */

#endif // INCLUDES_H
