#include "droneinterfacetest.h"
#include <QApplication>
#include "navdatathread.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DroneInterfaceTest w;
    w.show();

    NavdataThread nd_thread;
    nd_thread.start();

    return a.exec();
}
