#include "localizationfunctions.h"

LocalizationFunctions::LocalizationFunctions()
{
    m_vx = 0.0;
    m_vy = 0.0;
    m_px = 0.0;
    m_py = 0.0;
    m_px_prv = 0.0;
    m_py_prv = 0.0;
    m_vx_prv = 0.0;
    m_vy_prv = 0.0;
    m_stateCnt = 0;
    m_logFile.open("log_file.txt");
}


LocalizationFunctions::~LocalizationFunctions(){
    m_logFile.close();
}


// Coords are centered around starting point of drone
struct square_coord LocalizationFunctions::straightFwdXYZ(int altitude,int distance,float yaw){
    yaw = yaw/180*M_PI;
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

void LocalizationFunctions::updatePosition(float vx, float vy, float yaw){
    m_yaw = yaw;
#define ROUND_FACTOR 1
    //Deg to radians
    yaw = yaw*M_PI/180;

    //From local space to a Galilean space defined by the north (yaw=0)
    m_vx += ROUND_FACTOR*(round(vx/ROUND_FACTOR)*qCos(yaw)-round(vy/ROUND_FACTOR)*qSin(yaw));
    m_vy += ROUND_FACTOR*(round(vx/ROUND_FACTOR)*qSin(yaw)+round(vy/ROUND_FACTOR)*qCos(yaw));

    //Trapezoidal integration
    m_px = m_px_prv + 0.5*(m_vx+m_vx_prv)*0.005;
    m_py = m_py_prv + 0.5*(m_vy+m_vy_prv)*0.005;

    //State transition
    m_px_prv = m_px;
    m_py_prv = m_py;
    m_vx_prv = m_vx;
    m_vy_prv = m_vy;
}

void LocalizationFunctions::updateAltitude(float altitude){
    m_pz = altitude;
}


void LocalizationFunctions::resetPosition(){
    m_vx = 0.0;
    m_vy = 0.0;
    m_px = 0.0;
    m_py = 0.0;
    m_px_prv = 0.0;
    m_py_prv = 0.0;
    m_vx_prv = 0.0;
    m_vy_prv = 0.0;
}


float LocalizationFunctions::get_x(){
    return m_px;
}

float LocalizationFunctions::get_y(){
    return m_py;
}

float LocalizationFunctions::get_z(){
    return m_pz;
}

float LocalizationFunctions::get_yaw(){
    return m_yaw;
}
