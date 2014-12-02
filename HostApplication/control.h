#ifndef CONTROL_H
#define CONTROL_H

#include <QMainWindow>
#include <QWidget>
#include <QKeyEvent>
#include <QGridLayout>

#include "GUI/mainwindow.h"
#include "GUI/help.h"
#include "Drone_Interface/droneinterface.h"
#include "Video/videothread.hpp"
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

    std::string m_currentVidSource;

    VideoThread* m_vidThread;
    DetectionAlgo* m_detectionAlgo;

signals:
    void sendFrameToDetect(Mat frame);
    void sendDetectedObject(Point point, Size size);
    void sendConnectionStatus(bool status);

public slots:
    void changeVideoSource(std::string src, int err=0);
    void handleFrame(Mat frame);
    void handleDetectedObject(Point point, Size size);
    void connectDrone();
};

#endif // CONTROL_H
