#include "localizationfunctions.h"

LocalizationFunctions::LocalizationFunctions()
{
    m_drone_x = 0.0;
    m_drone_y = 0.0;
}

// Coords are centered around starting point of drone
struct square_coord LocalizationFunctions::straightFwdXYZ(int altitude,int distance,float yaw){
    return {    distance*qCos(yaw)  ,
                distance*qSin(yaw)  ,
                altitude            };
}

struct cylinder_coord LocalizationFunctions::straightFwdPol(int altitude,int distance,float yaw){
    return {yaw,distance,altitude};
}

int LocalizationFunctions::diffCommand(QPoint pixel){
    int dX = pixel.x()-CENTER_X;
    int dY = pixel.y()-CENTER_Y;
    if( qAbs(dX) > PIXDIFF_THRESHOLD ){
        return dX/qAbs(dX);
    } else if (qAbs(dY) > PIXDIFF_THRESHOLD) {
        return dY/qAbs(dY);
    } else {
        return 0;
    }
}

void LocalizationFunctions::updatePosition(float vx, float vy){
    m_drone_x += vx*0.02;
    m_drone_y += vy*0.02;
}


float LocalizationFunctions::get_x(){
    return m_drone_x;
}

float LocalizationFunctions::get_y(){
    return m_drone_y;
}
