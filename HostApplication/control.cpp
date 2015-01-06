#include "control.h"
#include <QTime>

Control::Control(int childPID, char * childSemFD, int childPipeWrFD,QObject *parent) :
    QObject(parent)
{

    qRegisterMetaType<std::string> ("std::string");
    qRegisterMetaType<Mat> ("Mat");


    m_appState = AppTestMode;
    m_missionState = MissionIdle;

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
                     &m_mainWindow,              SLOT(updateSizeBlackList(int)));

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
    //************************************************/
    //************************************************/

    m_mainWindow.show();

}

Control::~Control(){
    m_interface->get_daemon()->kill_daemon();
    delete m_interface;
    delete m_vidThread;
    delete m_detectThread;
}


void Control::state_machine(){
    while(true){
       switch(m_appState){
       case AppTestMode:
           break;
       case AppMissionMode:
           break;
       }
    }
}


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
    //TODO : add intelligence
    //emit sendFrameToDetect(frame);
    //DEBUG("Control: pushing to detectThread FIFO");
    m_detectThread->pushMatToFIFO(frame);

    /*
     * if( detection ) {
     *      m_detectThread->pushMatToFIFO(frame);
     * } else if( tracking ) {
     *      m_trackingThread->pushMatToFIFO(frame);
     * }
    */
}

void Control::handleTrackerInitialisation(){

}

void Control::handleCollimatorThreadMessages(std::string mess){

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
}
