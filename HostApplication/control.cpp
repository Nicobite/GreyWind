#include "control.h"

Control::Control(int childPID, char * childSemFD, int childPipeWrFD, QWidget * parent)
{
    //Creating interfaces and video threads
    m_interface = new DroneInterface(childPID, childSemFD, childPipeWrFD);
    //m_mainWindow = new MainWindow();

    // Connecting main window and thread
    // * updating video on main widget
    QObject::connect(&m_face        , SIGNAL(   displayedFrame(QImage)          ),
                     &m_mainWindow  , SLOT  (   getFrame(QImage))               );
    // * requesting source update
    QObject::connect(&m_face        , SIGNAL(   sigReqSrc()                     ),
                     &m_mainWindow  , SLOT  (   getSrc())                       );
    // * sending back new source
    QObject::connect(&m_mainWindow  , SIGNAL(   sigResponsesSrc(std::string)    ),
                     &m_face        , SLOT  (   updateSrc(std::string))         );

    // Starting up the threads
    m_mainWindow.show();
    m_face.start();

}

Control::~Control(){
    m_interface->get_daemon()->kill_daemon(); // TODO Delete this shit ?
    delete m_interface;
}
