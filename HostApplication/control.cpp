#include "control.h"
#include <QTime>

Control::Control(int childPID, char * childSemFD, int childPipeWrFD,QObject *parent) :
    QObject(parent)
{

    qRegisterMetaType<std::string> ("std::string");
    qRegisterMetaType<Mat> ("Mat");
    qRegisterMetaType<Point> ("Point");
    qRegisterMetaType<Size> ("Size");


    m_appState = AppTestMode;
    m_missionState = MissionIdle;
    m_objDetected = false;
    m_videoDestination = 1;
    m_frameSaved = false;

    //************************************************/
    //***********SIGNAL/SLOT CONNECTIONS *************/
    //************************************************/
    // Drone interface
    m_connected = false;
    m_interface = new DroneInterface(childPID, childSemFD, childPipeWrFD);

    QObject::connect(this,              SIGNAL(sendConnectionStatus(bool)),
                     &m_mainWindow,     SLOT(updateConnectionStatus(bool)));
    QObject::connect(&m_mainWindow,     SIGNAL(connectButtonClicked()),
                     this,              SLOT(connectDrone()));
    QObject::connect(&m_mainWindow,     SIGNAL(rstPosButtonClicked()),
                     this,              SLOT(resetPosition()));
    QObject::connect(this,              SIGNAL(sendSizeBlackList(int)),
                     &m_mainWindow,     SLOT(updateSizeBlackList(int)));
    QObject::connect(&m_mainWindow,     SIGNAL(sigValidatedObject(Point,Size)),
                     this,              SLOT(handleValidatedObject(Point,Size)));

    //************************************************/
    // Video management with source selection and detection rate settings
    m_vidThread = new VideoThread();
    // * Displaying the video frame
    QObject::connect(m_vidThread,       SIGNAL(sendVideoFrame(QImage)),
                     &m_mainWindow,     SLOT(setFrame(QImage)));
    // * Updating FramesB4Detect
    QObject::connect(&m_mainWindow,     SIGNAL(detectFrameRateChanged(int)),
                     m_vidThread,       SLOT(setDetectionPeriod(int)));
    // * Updating source
    QObject::connect(&m_mainWindow,     SIGNAL(vidSourceChanged(std::string)),
                     this,              SLOT(changeVideoSource(std::string)));
    // * Couldn't change source
    QObject::connect(m_vidThread,       SIGNAL(cannotChangeSource(std::string,int)),
                     this,              SLOT(changeVideoSource(std::string,int)));
    // Take picture
    QObject::connect(&m_mainWindow,     SIGNAL(sigTakePicture()),
                     m_vidThread,       SLOT(savePicture()));
    // Starting videoThread
    m_currentVidSource  = "None";
    m_vidThread->start();

    //************************************************/
    // Detection signals
    m_detectThread = new DetectThread;
    QObject::connect(m_detectThread,    SIGNAL(sigDetectedToControl(Point,Size)),
                     this,              SLOT(handleDetectedObject(Point,Size)));
    m_detectThread->start();

    // Detectin config
    QObject::connect(&m_mainWindow,     SIGNAL(detectAlgoChanged(std::string)),
                     m_detectThread,    SLOT(changeDetectionAlgo(std::string)));
    QObject::connect(&m_mainWindow,     SIGNAL(detectObjectChanged(std::string)),
                     m_detectThread,    SLOT(changeObject2Detect(std::string)));
    QObject::connect(m_detectThread,   SIGNAL(sigMessageToConsole(std::string)),
                     this,             SLOT(handleDetectThreadMessages(std::string)));
    // Detection related handlers:
    QObject::connect(m_vidThread,       SIGNAL(sendDetectionFrame(Mat)),
                     this,              SLOT(handleFrame(Mat)));
    QObject::connect(this,              SIGNAL(sendDetectedObject(Point,Size)),
                     &m_mainWindow,     SLOT(drawDetectedEllipse(Point,Size)));
    QObject::connect(&m_mainWindow,     SIGNAL(sendObjectToBlackList(Point,Size)),
                     this,              SLOT(addObjectToBlacklist(Point,Size)));
    QObject::connect(&m_mainWindow,     SIGNAL(sendClearBlackList()),
                     this,              SLOT(clearAllBlackList()));

    //************************************************/
    // Collimator  signals
    QObject::connect(&m_mainWindow,     SIGNAL(detectTrackerChanged(std::string)),
                     &m_collimator,     SLOT(changeAlgo(std::string)));
    QObject::connect(&m_mainWindow,     SIGNAL(initialiseTracker()),
                     this,              SLOT(handleTrackerInitialisation()));
    QObject::connect(&m_collimator,     SIGNAL(sigMessageToConsole(std::string)),
                     this,              SLOT(handleCollimatorThreadMessages(std::string)));
    QObject::connect(&m_collimator,     SIGNAL(detectedObject(Point,Size)),
                     &m_mainWindow,     SLOT(drawTrackedRect(Point,Size)));
    QObject::connect(&m_collimator,     SIGNAL(detectedLaser(Point,Size)),
                     &m_mainWindow,     SLOT(drawLaserDot(Point,Size)));
    QObject::connect(&m_collimator,     SIGNAL(sigDirections(std::string)),
                     &m_mainWindow,     SLOT(updateTrackState(std::string)));

    //************************************************/
    //************************************************/
    // Mission signals
    m_missionThread = new MissionThread;
    QObject::connect(&m_mainWindow,     SIGNAL(newMissionObject(QString,QString)),
                     this,              SLOT(addNewMission(QString,QString)));
    QObject::connect(&m_mainWindow,     SIGNAL(delMissionObject()),
                     this,              SLOT(subMission()));
    QObject::connect(&m_mainWindow,     SIGNAL(missionStatusChanged()),
                     this,              SLOT(runMission()));
    QObject::connect(&m_mainWindow,     SIGNAL(disconnectSonarViewMission()),
                     this,              SLOT(disconnectSonarMission()));

    QObject::connect(&m_mainWindow,     SIGNAL(stopMissionSignal()),
                     m_missionThread,              SLOT(abortMission()));
    QObject::connect(&m_mainWindow,     SIGNAL(startMissionSignal()),
                     m_missionThread,              SLOT(startMission()));
    QObject::connect(&m_mainWindow,     SIGNAL(detectAlgoChanged(std::string)),
                     m_missionThread,    SLOT(detectAlgoChoosen(std::string)));
    QObject::connect(&m_mainWindow,     SIGNAL(trackingAlgoMissionChoosen(QString)),
                     m_missionThread,    SLOT(trackingAlgoChoosen(QString)));
    QObject::connect(&m_mainWindow,     SIGNAL(detectObjectMissionChoosen(std::string)),
                     m_missionThread,    SLOT(objectToDetectChoosen(std::string)));
    QObject::connect(&m_mainWindow,     SIGNAL(sendUserResponseDetection(bool)),
                     m_missionThread,    SLOT(userDetectionValidation(bool)));
    QObject::connect(&m_mainWindow,     SIGNAL(sendTrackStatus(std::string)),
                     m_missionThread,    SLOT(updateTrackStatus(std::string)));

    QObject::connect(m_missionThread,     SIGNAL(sendDetectionToDo()),
                     &m_mainWindow,    SLOT(displayDetection()));
    QObject::connect(m_missionThread,     SIGNAL(skip5order()),
                     &m_mainWindow,    SLOT(skip5Detections()));
    QObject::connect(m_missionThread,     SIGNAL(missionStatusChanged()),
                     this,    SLOT(runMission()));
    QObject::connect(m_missionThread,     SIGNAL(reInitTracking()),
                     this,    SLOT(collimatorDeinit()));

    QObject::connect(m_missionThread,     SIGNAL(updateMissionListWidget(QString)),
                     &m_mainWindow,    SLOT(updateListWidget(QString)));
    QObject::connect(m_missionThread,     SIGNAL(sendStartTracking()),
                     &m_mainWindow,    SLOT(emitTrackerInit()));
    QObject::connect(m_missionThread,     SIGNAL(sendTrackAlgoChoosen(QString)),
                     &m_mainWindow,    SLOT(emitTrackerChoice(QString)));
    QObject::connect(m_missionThread,      SIGNAL(makeOneMeasure()),
                     &m_mainWindow,                SLOT(emitSonarRequest()));
    QObject::connect(m_missionThread,      SIGNAL(currentIndexChanged(QString)),
                     &m_mainWindow,    SLOT(emitAlgoDetectionMissionChoice(QString)));
    QObject::connect(m_missionThread,      SIGNAL(reInitWidgets()),
                     &m_mainWindow,    SLOT(reInitWidgetsMission()));
    QObject::connect(m_missionThread,      SIGNAL(reInitObjectChoice()),
                     &m_mainWindow,    SLOT(emitObjectChoiceMission()));


    m_missionThread->start();
    m_mainWindow.show();

    m_collimator.start();

}

Control::~Control(){


    m_interface->get_daemon()->kill_daemon();
    delete m_interface;
    delete m_vidThread;
    delete m_detectThread;
}

/* é
void Control::state_machine(){
    while(m_running){
       switch(m_appState){
       case AppTestMode:
           if(!m_objDetected){
               //Detector enbled
               if(m_frameSaved){
                   m_videoDestination = 2;

                   m_objDetected = true;
               }
           } else{
               //Tracker enabled
               if(m_videoDestination == 1 && !m_frameSaved){
                   m_objDetected = false;
               }
           }


           break;
       case AppMissionMode:



           break;
       }
       usleep(5000);
    }
}*/


void Control::changeVideoSource(std::string src, int err){
    if(err==0){
        if(src=="TCP" && m_connected==false){
            m_mainWindow.dispToCuteConsole(QString::fromStdString(
            "[Control]: Cannot change source to "+src+", drone is not connected!"
            ));
        }else{
            m_currentVidSource = src;
            m_vidThread->setSource(src);
        }
    }else if(err==1){
        m_currentVidSource = "None";
        m_mainWindow.dispToCuteConsole(QString::fromStdString(
        "[Control]: Cannot change source to "+src+", device cannot be opened!"
        ));
    }
}

void Control::handleFrame(Mat frame){
    if(m_videoDestination==1){
        m_detectThread->pushMatToFIFO(frame);
        m_frameSaved = false;

    } else if(m_videoDestination==2){
        m_collimator.handleFrame(frame);
        m_frameSaved = false;

    } else if(m_videoDestination==3){
        m_imgDetected = frame;
        m_frameSaved = true;

        m_videoDestination = 2;
        m_objDetected = true;
        runMission();


    }else{
        m_frameSaved = false;
    }
}

void Control::handleTrackerInitialisation(){
    while(!m_frameSaved&& !m_objDetected);
    m_collimator.init(m_imgDetected, m_centerDetected, m_sizeDetected);
}

void Control::handleValidatedObject(Point point, Size size){
    m_centerDetected = point;
    m_sizeDetected = size;

    m_videoDestination = 3;
}

void Control::addObjectToBlacklist(Point point, Size size)
{
    m_blackListCenterFIFO.push(point);
    m_blackListSizeFIFO.push(size);
    emit sendSizeBlackList((int)m_blackListCenterFIFO.size());
}

void Control::clearAllBlackList()
{
    // we clear the blacklist which contains the centers
    while(!m_blackListCenterFIFO.empty())
    {
        m_blackListCenterFIFO.pop();
    }

    // we clear the blacklist which contains the sizes
    while(!m_blackListSizeFIFO.empty())
    {
        m_blackListSizeFIFO.pop();
    }
    emit sendSizeBlackList((int)m_blackListCenterFIFO.size());


    m_videoDestination = 1;
    m_objDetected = false;

    m_collimator.deinit();
}

void Control::collimatorDeinit()
{
    m_collimator.deinit();
}

void Control::handleNavdata(navdata_t nd){
    m_locfunc.updatePosition(nd.vx, nd.vy, nd.yaw);
    m_mainWindow.updateLocationView(m_locfunc.get_x(), m_locfunc.get_y(), nd.altitude, nd.yaw);
}

void Control::resetPosition(){
    m_locfunc.resetPosition();
}

// when detectionAlgo
// sends signal to mainWindow
void Control::handleDetectedObject(Point point, Size size){
    //TODO : add some fucking intelligence
    //DEBUG("handleDetectedObject " << CURRENT_TIME);

    bool objectIsInTheBlackList=false;
    if (((int)m_blackListCenterFIFO.size()!=0) && ((int)m_blackListSizeFIFO.size()!=0))
    {

        // Copy of the two blackLists (in order to look over the lists)
        std::queue<Point> myCenterQueue;
        myCenterQueue=m_blackListCenterFIFO;
        std::queue<Size> myRadiusQueue;
        myRadiusQueue=m_blackListSizeFIFO;
        float distance=0.0;

        while (!myCenterQueue.empty() && !myRadiusQueue.empty())
         {
            // calculation of the distance between the two centers (new detected object and object of the blackList)
           distance=sqrt(pow(point.x-myCenterQueue.front().x,2)+(point.y-myCenterQueue.front().y,2));
           if(distance<(myRadiusQueue.front().width/2))
           {
               // We do not send Object information if it seems to be in the BlackList
               objectIsInTheBlackList=true;
           }

           // We analyse the next element of the two queues
           myCenterQueue.pop();
           myRadiusQueue.pop();
         }
    }


    if(!objectIsInTheBlackList)
    {
    // No elements in the blacklist, object can be send normally
    emit sendDetectedObject(point, size);
    }
}


void Control::connectDrone(){
    //Connect to the daemon
    m_interface->get_daemon()->connect_daemon();
    if(m_interface->get_daemon()->is_drone_available())
    {
        m_interface->get_daemon()->launch_navdata_handler();
        m_interface->get_daemon()->launch_control_handler();
        m_interface->launch_sensor_thread();
        m_connected = true;

        emit sendConnectionStatus(true);

        //Set navdata
        QObject::connect(this->m_interface->get_daemon()->get_navdata_thread(), SIGNAL(sendCurrentND(navdata_t)),
                         &m_mainWindow                                        , SLOT(updateNavdataView(navdata_t)));
        QObject::connect(this->m_interface->get_daemon()->get_navdata_thread(), SIGNAL(sendCurrentND(navdata_t)),
                         this                                                 , SLOT(handleNavdata(navdata_t)));

        //Sensor connections
        // * Laser state: mainWindow -> droneInterface
        QObject::connect(&m_mainWindow,                             SIGNAL(laserState(bool)),
                         this->m_interface->get_sensor_thread(),    SLOT(setLaserState(bool)));
        // * Distance measurement request: mainWindow -> droneInterface
        QObject::connect(&m_mainWindow,                             SIGNAL(sonarRequest()),
                         this->m_interface->get_sensor_thread(),    SLOT(requestSonarData()));
        // * Distance measurement response: droneInterface -> mainWindow
        QObject::connect(this->m_interface->get_sensor_thread(),    SIGNAL(newSonarData(int)),
                         &m_mainWindow,                             SLOT(updateSonarView(int)));
        QObject::connect(this->m_interface->get_sensor_thread(),    SIGNAL(newSonarData(int)),
                         &m_mainWindow,                             SLOT(updateSonarViewMission(int)));

        if(m_interface->get_daemon()->is_control_running()){
            QObject::connect(&m_mainWindow,                                         SIGNAL(pressCmd(int)),
                             this->m_interface->get_daemon()->get_control_thread(), SLOT(key_press_cmd(int)));
            QObject::connect(&m_mainWindow,                                         SIGNAL(releaseCmd()),
                             this->m_interface->get_daemon()->get_control_thread(), SLOT(key_release_cmd()));
        }
    }
}

void Control::handleDetectThreadMessages(std::string mess){
    this->m_mainWindow.dispToCuteConsole("[DetectThread] "+QString::fromStdString(mess));
}

void Control::handleCollimatorThreadMessages(std::string mess){
    this->m_mainWindow.dispToCuteConsole("[Collimator] "+QString::fromStdString(mess));
}

/* Mission slots */
void Control::addNewMission(QString algo, QString obj){
    m_listMission.push(Mission{algo,obj});
}

void Control::subMission(){
    m_listMission.pop();
}

void Control::runMission(){
    while (m_missionThread->isFinished()!=true){

    }
    // Wait the thread is finished to start another thread
    m_missionThread->start();
}

void Control::disconnectSonarMission(){

    QObject::disconnect(this->m_interface->get_sensor_thread(),    SIGNAL(newSonarData(int)),
                     &m_mainWindow,                             SLOT(updateSonarViewMission(int)));

}
