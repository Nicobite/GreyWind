#ifndef MISSION_H
#define MISSION_H

#include <QMainWindow>
#include <QWidget>
#include <QObject>
#include <QKeyEvent>
#include <QGridLayout>
#include <QThread>
#include "opencv2/opencv.hpp"
#include <iostream>
#include "includes.h"


using namespace std;
using namespace cv;

enum MissionStatus{ MISSION_NOT_STARTED, DETECTION,  WAIT_USER_VALIDATION_DETECTION, TRACKING,MEASUREMENT,MISSION_FINISHED, MISSION_ABORDED};


class MissionThread : public QThread
{
    Q_OBJECT
public:
    explicit MissionThread(QObject *parent = 0);
    ~MissionThread();

    MissionStatus mission_status;
    string detectionAlgo;
    string trackingAlgo;
    string objectToDetect;
    bool startMissionOrder;
    bool detectionIsDone;



private:

    void run();

signals:

    void sendDetectionToDo();


public slots:
    void abortMission();
    void startMission();
    void detectAlgoChoosen(std::string algoname);
    void trackingAlgoChoosen(std::string algoname);
    void objectToDetectChoosen(std::string objectname);


};


#endif // MISSION_H


