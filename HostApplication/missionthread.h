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

private:
    MissionStatus mission_status;
    string detectionAlgo;
    QString trackingAlgo;
    string objectToDetect;
    bool startMissionOrder;
    bool detectionIsValid;
    string trackStatus;

    bool m_gotNewSonarData;
    int  m_latestSonarData;

    int m_measureNo;
    double m_dist;

    void run();

    void reInitMission();
    double filteredMeasurement();

signals:

    void sendDetectionToDo();
    void missionStatusChanged();
    void skip5order();
    void sigMessageToConsole(std::string message);
    //void updateMissionListWidget(QString);
    void sendStartTracking();
    void sendTrackAlgoChoosen(QString);
    void setLaserState(int);
    void makeOneMeasure();
    void reInitDetection(std::string);
    void reInitTracking();
    void reInitWidgets();
    void reInitObjectChoice();
    void sendStatusMission(QString);
    void sendLocalizedObject(std::string, double);


public slots:
    void abortMission();
    void startMission();
    void detectAlgoChoosen(std::string algoname);
    void trackingAlgoChoosen(QString algoname);
    void objectToDetectChoosen(std::string objectname);
    void userDetectionValidation(bool res);
    void updateTrackStatus(std::string st);
    void acquireSonarData(int distance);



};


#endif // MISSION_H


