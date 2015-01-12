#include "missionthread.h"

MissionThread::MissionThread(QObject *parent) :
    QThread(parent)
{
    mission_status=MISSION_NOT_STARTED;
    startMissionOrder=false;
    detectionIsDone=false;
    detectionAlgo="none";
    trackingAlgo="none";
    objectToDetect="none";

}


MissionThread::~MissionThread(){

}


void MissionThread::run(){
    switch (mission_status) {

        case MISSION_NOT_STARTED:
        //DEBUG("> MissionThread::run()::MissionNotStarted");

        /* For Starting the mission we need 4 elements:
         * - detection algorithm choosen
         * - tracking algorithm choosen
         * - object choosen
         * - start command clicked  */
        if (detectionAlgo!="none" && trackingAlgo!="none" && objectToDetect!="none")
        {
            DEBUG("> MissionThread::run()::BEFORE");
            if (startMissionOrder==true)
            {
                // We start the mission
                mission_status=DETECTION;
            }
        }
        else
        {
           // We do not have all the option for the automatic mission
           if (startMissionOrder==true)
           {
               // we will wait a new start mission order to begin the mission
               startMissionOrder=false;
           }
        }

            break;

        case DETECTION:
        DEBUG("> MissionThread::run()::DETECTION");

        // We stay in detection until a detection is done
        // Check the flag detectionIsDone
        emit sendDetectionToDo();

            break;

        case WAIT_USER_VALIDATION_DETECTION:
        DEBUG("> MissionThread::run():: WAIT_USER_VALIDATION_DETECTION");

            break;

        case TRACKING:
        DEBUG("> MissionThread::run()::TRACKING");

            break;

        case MEASUREMENT:
        DEBUG("> MissionThread::run()::MEASUREMENT");

            break;

        case MISSION_FINISHED:
        DEBUG("> MissionThread::run()::MISSION_FINISHED");

            break;

         case MISSION_ABORDED:
        DEBUG("> MissionThread::run()::MISSION_ABORDED");

            break;

        default:
            break;
        }

}

void MissionThread::abortMission(){
    mission_status=MISSION_ABORDED;
}
void MissionThread::startMission(){
    DEBUG("> MissionThread::run()::START ORDER");
    startMissionOrder=true;
}

void MissionThread::detectAlgoChoosen(string algoname)
{
    DEBUG("> MissionThread::run()::ALGO DETECT");
    detectionAlgo=algoname;
}

void MissionThread::trackingAlgoChoosen(string algoname)
{
    DEBUG("> MissionThread::run()::ALGO TRACKED");
    trackingAlgo=algoname;
}

void MissionThread::objectToDetectChoosen(std::string objectname)
{
    DEBUG("> MissionThread::run()::OBJECT CHOOSEN");
    objectToDetect=objectname;
}


