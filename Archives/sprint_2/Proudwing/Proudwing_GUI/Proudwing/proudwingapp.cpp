#include "proudwingapp.h"
#include "ui_proudwingapp.h"

ProudwingApp::ProudwingApp(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ProudwingApp)
{
    ui->setupUi(this);

    interface.connect_daemon();
    if(interface.is_drone_available())
    {
        interface.launch_navdata_handler();
        interface.launch_control_handler();
    }
}

ProudwingApp::~ProudwingApp()
{
    interface.kill_daemon();
    delete ui;
}

void ProudwingApp::keyPressEvent(QKeyEvent* e){
    if(!e->isAutoRepeat())
        interface.get_control_thread()->key_press_cmd(e->key());

}

void ProudwingApp::keyReleaseEvent(QKeyEvent* e){
    if(!e->isAutoRepeat())
        interface.get_control_thread()->key_release_cmd();
}
