#include "control.h"

Control::Control(int childPID, char * childSemFD, int childPipeWrFD,QObject *parent) :
    QObject(parent)
{

    qRegisterMetaType<std::string> ("std::string");
    qRegisterMetaType<Mat> ("Mat");

    //Creating interfaces and video threads
    m_connected = false;
    m_interface = new DroneInterface(childPID, childSemFD, childPipeWrFD);

    m_vidThread = new VideoThread();
    QObject::connect(m_vidThread,       SIGNAL(sendVideoFrame(QImage)),
                     &m_mainWindow,     SLOT(setFrame(QImage)));
    QObject::connect(&m_mainWindow,     SIGNAL(detectFrameRateChanged(int)),
                     m_vidThread,       SLOT(setDetectionPeriod(int)));
    QObject::connect(&m_mainWindow,     SIGNAL(vidSourceChanged(std::string)),
                     this,              SLOT(changeVideoSource(std::string)));
    QObject::connect(m_vidThread,       SIGNAL(cannotChangeSource(std::string,int)),
                     this,              SLOT(changeVideoSource(std::string,int)));
    /* QObject::connect(&m_mainWindow,     SIGNAL(vidSourceChanged(std::string)),
                     this,              SLOT(changeVideoSource(std::string)));
    */m_vidThread->start();

    m_detectionAlgo = new HaarFaceDetectionAlgo("haarcascade_frontalface_alt.xml");
    QObject::connect(m_vidThread,       SIGNAL(sendDetectionFrame(Mat)),
                     m_detectionAlgo,   SLOT(handleFrame(Mat)));
    QObject::connect(m_detectionAlgo,   SIGNAL(detectedObject(Point,Size)),
                     &m_mainWindow,     SLOT(drawDetectedEllipse(Point,Size)));
    // Connecting main window and thread
    // * updating video on main widget
    /*    // * requesting source update
    QObject::connect(&m_face        , SIGNAL(   sigReqSrc()                     ),
                     &m_mainWindow  , SLOT  (   getSrc())                       );
    // * sending back new source
    QObject::connect(&m_mainWindow  , SIGNAL(   sigResponsesSrc(std::string)    ),
                     &m_face        , SLOT  (   updateSrc(std::string))         );
    */
    // Starting up the threads
    m_mainWindow.show();
    //m_face.start();

}

Control::~Control(){
    m_interface->get_daemon()->kill_daemon(); // TODO Delete this shit ?
    delete m_interface;
}

void Control::changeVideoSource(std::string src, int err){
    if(err==0){
        if(src=="TCP" && m_connected==false){
            m_mainWindow.dispToCuteConsole(QString::fromStdString(
            "[Control]: Cannot change source to "+src+", drone is not connected!"
            ));
        }else{
            m_vidThread->setSource(src);
        }
    }else if(err==1){
        m_mainWindow.dispToCuteConsole(QString::fromStdString(
        "[Control]: Cannot change source to "+src+", device cannot be opened!"
        ));
    }
}
