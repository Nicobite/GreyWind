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

    yaw = yaw*M_PI/180;

    //if(m_stateCnt < 10){
        m_vx += round(vx/10)*qCos(yaw)+round(vy/10)*qSin(yaw);
        m_vy += round(vx/10)*qSin(yaw)-round(vy/10)*qCos(yaw);

    //    m_stateCnt ++;

    //} else{
    //    m_vx /= 10;
    //    m_vy /= 10;

        m_px = m_px_prv + 0.5*(m_vx+m_vx_prv)*0.005;
        m_py = m_py_prv + 0.5*(m_vy+m_vy_prv)*0.005;

        m_px_prv = m_px;
        m_py_prv = m_py;
        m_vx_prv = m_vx;
        m_vy_prv = m_vy;

        m_vx = 0.0;
        m_vy = 0.0;

    //    m_stateCnt = 0;
    //}


    /*
    m_vx = round(vx/10);
    m_vy = round(vy/10);

        m_px = m_px_prv + 0.5*(m_vx+m_vx_prv)*0.5;
        m_py = m_py_prv + 0.5*(m_vy+m_vy_prv)*0.5;

        m_px_prv = m_px;
        m_py_prv = m_py;
        m_vx_prv = m_vx;
        m_vy_prv = m_vy;

    m_logFile << m_vx << " " << m_vy << " " << m_px << " "  << m_py << std::endl;
    *//*
     For estimating bias...
     *
    m_vx += 10*round(vx/10);
    m_vy += 10*round(vy/10);
    m_vx_prv ++;
    m_vy_prv ++;
    m_px = m_vx/m_vx_prv;
    m_py = m_vy/m_vy_prv;*/
}


void LocalizationFunctions::resetPosition(){
    m_vx = 0.0;
    m_vy = 0.0;
    m_px = 0.0;
    m_py = 0.0;
    m_px_prv = 0.0;
    m_py_prv = 0.0;
    m_vx_prv = 1.0;
    m_vy_prv = 1.0;
}


float LocalizationFunctions::get_x(){
    return m_px;
}

float LocalizationFunctions::get_y(){
    return m_py;
}
