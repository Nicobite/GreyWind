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
    trackStatus="none";
    m_gotNewSonarData=false;
    m_latestSonarData=0;
}


MissionThread::~MissionThread(){

}


void MissionThread::run(){
    switch (mission_status) {

        case MISSION_NOT_STARTED:
        DEBUG("> MissionThread::run()::MissionNotStarted");
        emit sendStatusMission("NOT STARTED");

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
                emit sigMessageToConsole("Mission has started.");
                mission_status=DETECTION;
                emit missionStatusChanged();
                startMissionOrder=false; // in case of mission aborded
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
        emit sendStatusMission("DETECTION");

        // We stay in detection until a detection is done
        // We will skip 5 detection times by default
        emit skip5order();
        emit sendDetectionToDo();
        mission_status=WAIT_USER_VALIDATION_DETECTION;
        //emit missionStatusChanged();

            break;

        case WAIT_USER_VALIDATION_DETECTION:
        DEBUG("> MissionThread::run():: WAIT_USER_VALIDATION_DETECTION");
        if(detectionIsValid==true)
        {
            emit sendStatusMission("TRACKING");
            // The user valids the detection
            mission_status=TRACKING;
            // The algorithm choosen for tracking is implemented
            emit setLaserState(Qt::Checked);
            emit sendTrackAlgoChoosen(trackingAlgo);
            /*
             * We dont run again the thread here because a runMission
             *  will be launched from control handleFrame when objectDetected=true
             * */

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
        emit sendStatusMission("TRACKING");
        // Tracking can start now
        emit sendStartTracking();
        mission_status=MEASUREMENT;
        emit missionStatusChanged();

            break;

        case MEASUREMENT:
        DEBUG("> MissionThread::run()::MEASUREMENT");      
        // When red dot is in the rectangle we can launch a measure
        if (trackStatus=="OK")
        {
            emit sendStatusMission("MEASUREMENT");
            // Make the measure
            //emit makeOneMeasure();

            //Serdar: mean-filtered measurement
            double dist = filteredMeasurement();
            char mess[30];
            sprintf(mess, "Distance: %f", dist);
            emit sendStatusMission(mess);

            //Serdar: sending localized objects to Control
            sendLocalizedObject(objectToDetect, dist);
            //fin Serdar

            mission_status=MISSION_FINISHED;
            emit missionStatusChanged();
            emit setLaserState(Qt::Unchecked);
        }

            break;

        case MISSION_FINISHED:
        DEBUG("> MissionThread::run()::MISSION_FINISHED");
        emit sigMessageToConsole("Mission is completed.");
        reInitMission();
        emit sendStatusMission("FINISHED");

            break;

         case MISSION_ABORDED:
        DEBUG("> MissionThread::run()::MISSION_ABORDED");
        emit sigMessageToConsole("Mission is aborted.");
        reInitMission();
        emit sendStatusMission("ABORTED");

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

void MissionThread::updateTrackStatus(std::string st)
{
   trackStatus=st;
   if (mission_status==MEASUREMENT)
   {
   emit missionStatusChanged();
   }
}

void MissionThread::acquireSonarData(int distance){
    m_latestSonarData=distance;
    m_gotNewSonarData=true;
}

void MissionThread::reInitMission()
{
    mission_status=MISSION_NOT_STARTED;
    startMissionOrder=false;
    detectionIsValid=false;
    detectionAlgo="none";
    trackingAlgo="none";
    objectToDetect="none";
    trackStatus="none";
    emit reInitDetection(detectionAlgo);
    emit sendTrackAlgoChoosen(trackingAlgo);
    emit reInitTracking();
    emit reInitWidgets();
    emit reInitObjectChoice();
    emit missionStatusChanged();
}

double MissionThread::filteredMeasurement(){
    double res = 0.0;
    for(int i=0; i<10; i++){
        emit makeOneMeasure();
        int  j = 0;
        while(!m_gotNewSonarData && j<100000){
            j++;
        }
        if(j<100000){
            m_gotNewSonarData = false;
            res += m_latestSonarData;
            usleep(100000);
        } else{
            res = -10;
            break;
        }
    }
    res /= 10;
    return res;
}
