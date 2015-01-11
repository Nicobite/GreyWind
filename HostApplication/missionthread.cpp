#include "missionthread.h"

MissionThread::MissionThread(QObject *parent) :
    QThread(parent)
{

}


MissionThread::~MissionThread(){

}


void MissionThread::run(){
    DEBUG("> DetectThread::run()");

}




//Mission::Mission(QObject *parent) :
//    QThread(parent)
//{



//}


//Mission::~Mission(){

//}



//void Mission::run(){
//    DEBUG("> Mission::run()");

//    switch (mission_status) {

//    case MISSION_NOT_STARTED:

//        break;

//    case DETECTION:

//        break;

//    case WAIT_USER_VALIDATION_DETECTION:

//        break;

//    case TRACKING:

//        break;

//    case MEASUREMENT:

//        break;

//    case MISSION_FINISHED:

//        break;

//    default:
//        break;
//    }
//}
