#include "control.h"
#include <QTime>

Control::Control(int childPID, char * childSemFD, int childPipeWrFD,QObject *parent) :
    QObject(parent)
{

    qRegisterMetaType<std::string> ("std::string");
    qRegisterMetaType<Mat> ("Mat");

    // Drone interface
    m_connected = false;
    m_interface = new DroneInterface(childPID, childSemFD, childPipeWrFD);
    QObject::connect(this,              SIGNAL(sendConnectionStatus(bool)),
                     &m_mainWindow,     SLOT(updateConnectionStatus(bool)));
    QObject::connect(&m_mainWindow,     SIGNAL(connectButtonClicked()),
                     this,              SLOT(connectDrone()));

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

    // Detection related handlers:
    QObject::connect(m_vidThread,       SIGNAL(sendDetectionFrame(Mat)),
                     this,              SLOT(handleFrame(Mat)));
    QObject::connect(this,              SIGNAL(sendDetectedObject(Point,Size)),
                     &m_mainWindow,     SLOT(drawDetectedEllipse(Point,Size)));


    /*TODO : lol change that shit       */
    //m_detectionAlgo = new HaarFaceDetectionAlgo("haarcascade_frontalface_alt.xml");
    /*QObject::connect(this,              SIGNAL(sendFrameToDetect(Mat)),
                     m_detectionAlgo,   SLOT(handleFrame(Mat)));//*/
    m_detectThread = new DetectThread;
    QObject::connect(m_detectThread,    SIGNAL(sigDetectedToControl(Point,Size)),
                     this,              SLOT(handleDetectedObject(Point,Size)));
    /* END TODO                         */

    m_detectThread->start();
    m_mainWindow.show();

}

Control::~Control(){
    m_interface->get_daemon()->kill_daemon();
    delete m_interface;
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
}

// when detectionAlgo
// sends signal to mainWindow
void Control::handleDetectedObject(Point point, Size size){
    //TODO : add some fucking intelligence
    //DEBUG("handleDetectedObject " << CURRENT_TIME);
    emit sendDetectedObject(point, size);
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

        //Sensor connections
        QObject::connect(&m_mainWindow,                             SIGNAL(laserState(bool)),
                         this->m_interface->get_sensor_thread(),    SLOT(setLaserState(bool)));
        QObject::connect(&m_mainWindow,                             SIGNAL(sonarRequest()),
                         this->m_interface->get_sensor_thread(),    SLOT(requestSonarData()));
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
