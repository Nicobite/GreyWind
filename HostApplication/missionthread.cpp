#include "missionthread.h"

MissionThread::MissionThread(QObject *parent) :
    QThread(parent)
{
    mission_status=MISSION_NOT_STARTED;
    startMissionOrder=false;
    detectionIsValid=false;
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
            if (startMissionOrder==true)
            {
                // We start the mission
                mission_status=DETECTION;
                emit missionStatusChanged();
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
        // We will skip 5 detection times by default
        emit updateMissionListWidget("                DETECTION                       ");
        emit skip5order();
        emit sendDetectionToDo();
        mission_status=WAIT_USER_VALIDATION_DETECTION;
        //emit missionStatusChanged();

            break;

        case WAIT_USER_VALIDATION_DETECTION:
        DEBUG("> MissionThread::run():: WAIT_USER_VALIDATION_DETECTION");
        emit updateMissionListWidget("      WAIT USER VALIDATION        ");
        if(detectionIsValid==true)
        {
            // The user valids the detection
            mission_status=TRACKING;
            emit sendTrackAlgoChoosen(trackingAlgo);
            emit missionStatusChanged();
        }
        else
        {
            // The user adds the detection to the blackList
            mission_status=DETECTION;
            emit missionStatusChanged();
        }

            break;

        case TRACKING:
        DEBUG("> MissionThread::run()::TRACKING");
        emit updateMissionListWidget("                 TRACKING                    ");
        emit sendStartTracking();
        mission_status=MEASUREMENT;
        emit missionStatusChanged();

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

void MissionThread::trackingAlgoChoosen(QString algoname)
{
    DEBUG("> MissionThread::run()::ALGO TRACKED");
    trackingAlgo=algoname;
}

void MissionThread::objectToDetectChoosen(std::string objectname)
{
    DEBUG("> MissionThread::run()::OBJECT CHOOSEN");
    objectToDetect=objectname;
}

void MissionThread::userDetectionValidation(bool res)
{
   detectionIsValid=res;
}


