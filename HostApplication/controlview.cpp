#include "controlview.h"
#include "ui_controlview.h"

ControlView::ControlView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ControlView)
{
    ui->setupUi(this);

    // Connect help button
    QObject::connect(ui->helpButton ,     SIGNAL(   clicked()                           ),
                     this               , SLOT  (   displayHelp())                      );



}

ControlView::~ControlView()
{
    delete ui;
}

void ControlView::displayHelp(){
    m_helpWindow.show();
}


void ControlView::keyPressEvent(QKeyEvent* e)
{
    if(!e->isAutoRepeat()){
        qDebug() << "Keybutton press:" << e->key() << endl;

        emit pressCmd(e->key());
        /*if(m_interface.get_daemon()->is_control_running()){
            m_interface.get_daemon()->get_control_thread()->key_press_cmd(e->key());
        } */
    }

}

void ControlView::keyReleaseEvent(QKeyEvent* e)
{
    if(!e->isAutoRepeat()) {
        qDebug() << "Keybutton release" << endl;

        emit releaseCmd();
        /*if(m_interface.get_daemon()->is_control_running()){
            m_interface.get_daemon()->get_control_thread()->key_release_cmd();
        }*/
    }

}

