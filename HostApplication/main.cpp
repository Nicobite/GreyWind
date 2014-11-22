#include <QApplication>

#include "proudwing.h"
#include "includes.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

#if NBM
#include <QMainWindow>
#include "Detection/facedetection.hpp"
#include "Threads/facethread.h"

    MainWindow w;
    Facethread thread1;

    // Connecting main window and thread
    // * updating video on main widget
    QObject::connect(&thread1   , SIGNAL(   displayedFrame(QImage)          ),
                     &w         , SLOT  (   getFrame(QImage))               );
    // * requesting source update
    QObject::connect(&thread1   , SIGNAL(   sigReqSrc()                     ),
                     &w         , SLOT  (   getSrc())                       );
    // * sending back new source
    QObject::connect(&w         , SIGNAL(   sigResponsesSrc(std::string)    ),
                     &thread1   , SLOT  (   updateSrc(std::string))         );

    // Starting up the threads
    w.show();
    thread1.start();

#else
    Proudwing app;
    app.show();
#endif

    return a.exec();
}
