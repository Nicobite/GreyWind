#include "localizationfunctions.h"

LocalizationFunctions::LocalizationFunctions()
{
}

// Coords are centered around starting point of drone
struct square_coord LocalizationFunctions::straightFwdXYZ(int altitude,int distance,float yaw){
    return {    qCos(yaw)   ,
                qSin(yaw)   ,
                altitude    };
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
