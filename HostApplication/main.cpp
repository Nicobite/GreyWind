#include <QApplication>

#include "mainwindow.h"
#include "Detection/facedetection.hpp"
#include "Threads/facethread.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    Facethread thread1;

    QObject::connect(&thread1, SIGNAL(displayedFrame(QImage)),
                         &w, SLOT(getFrame(QImage)));

    w.show();
    thread1.start();

    return a.exec();
}
