#include "proudwingapp.h"
#include "Drone_Interface/Daemon_Interface/daemoninterface.h"
#include <QApplication>

#include <iostream>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ProudwingApp w;
    w.show();

    /*DaemonInterface interface;
    interface.connect_daemon();
    //usleep(10000);
    interface.launch_navdata_handler();
    /*while(1){
        std::cout << interface.is_drone_available() << std::endl;
        usleep(1000000);
    }*/
    /*usleep(10000000);
    interface.kill_daemon();
    return 0;*/
    return a.exec();
}
