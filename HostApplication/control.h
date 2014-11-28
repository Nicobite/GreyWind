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
#include "Detection/facedetection.hpp"
#include "Threads/facethread.h"
#include "Threads/videothread.hpp"

class Control
{
public:
    Control(int childPID=0, char* childSemFD=NULL, int childPipeWrFD=0, QWidget *parent = 0);
    ~Control();

private:
    QMainWindow m_mainWindow;
    //Facethread m_face;
    VideoThread* m_vidThread;
    DroneInterface* m_interface;
    bool m_connected;

signals:
    //un signal pour les pts + taille detectés

public slots:

};

#endif // CONTROL_H
