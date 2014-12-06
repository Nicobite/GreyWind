#ifndef INCLUDES_H
#define INCLUDES_H

#include <stdio.h>
#include <QDebug>
#include <QTime>
#include <QPoint>


/* Actual values */
// * Sources
#define SRC_DEFAULT     0
#define SRC_TCP         "tcp://@192.168.1.1:5555"

// * Nice macros
#define CURRENT_TIME    QTime::currentTime().toString("hh:mm:ss.zzz")

// * Constants
#define CAMERA_ANGLE_H  (35.6) // °
#define CAMERA_ANGLE_V  (18.6) // °
#define DIST_COM_CAM    (20.7) // cm

/* Custom types */
struct cylinder_coord {
    float   angle;
    int     distance;
    int     height;
};
struct square_coord {
    int x,y,z;
};

/* Debug macros */
#define DBG 1
#define COLORFULC 0
#if DBG
    #if COLORFULC
        #define DEBUG(arg) printf("%s[DEBUG] %s%s\n","\033[1;36m",arg,"\033[0m")
        #define ERROR(arg) printf("%s[ERROR] %s%s\n","\033[1;31m",arg,"\033[0m")
    #else
        #define DEBUG(arg) qDebug() << "[DEBUG] " << arg;
        #define ERROR(arg) qDebug() << "[ERROR] " << arg;
    #endif
#else
    #define DEBUG(arg)
    #define ERROR(arg)
#endif

#endif // INCLUDES_H
