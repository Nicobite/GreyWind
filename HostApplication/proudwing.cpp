#include "proudwing.h"

Proudwing::Proudwing(QWidget *parent) :
    QWidget(parent)
{
    m_interface.get_daemon()->connect_daemon();
    if(m_interface.get_daemon()->is_drone_available())
    {
        m_interface.get_daemon()->launch_navdata_handler();
        m_interface.get_daemon()->launch_control_handler();
    }

    this->m_w = new MainWindow(this);

    // Connecting main window and thread
    // * updating video on main widget
    QObject::connect(&m_thread1   , SIGNAL(   displayedFrame(QImage)          ),
                     m_w         , SLOT  (   getFrame(QImage))               );
    // * requesting source update
    QObject::connect(&m_thread1   , SIGNAL(   sigReqSrc()                     ),
                     m_w       , SLOT  (   getSrc())                       );
    // * sending back new source
    QObject::connect(m_w         , SIGNAL(   sigResponsesSrc(std::string)    ),
                     &m_thread1   , SLOT  (   updateSrc(std::string))         );

    // Starting up the threads
    //w.show();
    m_thread1.start();

}

Proudwing::~Proudwing()
{
    m_interface.get_daemon()->kill_daemon();
}

void Proudwing::keyPressEvent(QKeyEvent* e)
{
    if(m_interface.get_daemon()->is_control_running()){
        if(!e->isAutoRepeat())
            m_interface.get_daemon()->get_control_thread()->key_press_cmd(e->key());
    }
}

void Proudwing::keyReleaseEvent(QKeyEvent* e)
{
    if(m_interface.get_daemon()->is_control_running()){
        if(!e->isAutoRepeat())
            m_interface.get_daemon()->get_control_thread()->key_release_cmd();
    }
}
