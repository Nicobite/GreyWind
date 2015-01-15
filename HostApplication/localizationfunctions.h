#ifndef LOCALIZATIONFUNCTIONS_H
#define LOCALIZATIONFUNCTIONS_H

#include <QtGlobal>
#include <QtCore/qmath.h>
#include "includes.h"
#include <iostream>
#include <fstream>

#define FRAME_X     640
#define FRAME_Y     360
#define CENTER_X    320
#define CENTER_Y    180
#define PIXDIFF_THRESHOLD 20

class LocalizationFunctions
{
private:
    float m_px,m_py, m_pz, m_yaw, m_vx, m_vy;
    float m_px_prv, m_py_prv, m_vx_prv, m_vy_prv;
    int m_stateCnt;
    std::ofstream m_logFile;
public:
    LocalizationFunctions();
    ~LocalizationFunctions();

    //Get coordinates of object depending on yaw and distance
    static struct square_coord straightFwdXYZ(int altitude,int distance,float yaw);
    static struct cylinder_coord straightFwdPol(int altitude,int distance,float yaw);
    //Get command recommandation depending on camera's angle of view
    int diffCommand(QPoint pixel);

    void updatePosition(float vx, float vy, float yaw);
    void updateAltitude(float altitude);
    void resetPosition();

    float get_x();
    float get_y();
    float get_z();
    float get_yaw();

};

#endif // LOCALIZATIONFUNCTIONS_H
