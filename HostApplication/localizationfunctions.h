#ifndef LOCALIZATIONFUNCTIONS_H
#define LOCALIZATIONFUNCTIONS_H

#include <QtGlobal>
#include <QtCore/qmath.h>
#include "includes.h"

#define FRAME_X     640
#define FRAME_Y     360
#define CENTER_X    320
#define CENTER_Y    180
#define PIXDIFF_THRESHOLD 20

class LocalizationFunctions
{
private:
    float m_drone_x,m_drone_y;
public:
    LocalizationFunctions();
    //Get coordinates of object depending on yaw and distance
    struct square_coord straightFwdXYZ(int altitude,int distance,float yaw);
    struct cylinder_coord straightFwdPol(int altitude,int distance,float yaw);
    //Get command recommandation depending on camera's angle of view
    int diffCommand(QPoint pixel);

    void updatePosition(float vx, float vy);

    float get_x();
    float get_y();
};

#endif // LOCALIZATIONFUNCTIONS_H
