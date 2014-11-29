#ifndef CONTROL_H
#define CONTROL_H

#include <QMainWindow>
#include <QWidget>
#include <QKeyEvent>
#include <QGridLayout>

#include "mainwindow.h"
#include "help.h"
#include "controlview.h"
#include "Drone_Interface/droneinterface.h"
#include "Threads/videothread.hpp"
#include "Detection/detectionalgo.h"
#include "Detection/haarfacedetectionalgo.h"

class Control: public QObject
{
    Q_OBJECT

public:
    Control(int childPID=0, char* childSemFD=NULL, int childPipeWrFD=0, QObject *parent = 0);
    ~Control();

private:
    MainWindow m_mainWindow;

    bool m_connected;
    DroneInterface* m_interface;

    VideoThread* m_vidThread;
    DetectionAlgo* m_detectionAlgo;

signals:
    //un signal pour les pts + taille detectés

public slots:
    void changeVideoSource(std::string src, int err=0);

};

#endif // CONTROL_H
