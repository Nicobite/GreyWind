#ifndef MISSION_H
#define MISSION_H

#include <QMainWindow>
#include <QWidget>
#include <QKeyEvent>
#include <QGridLayout>
#include <QThread>

#include "control.h"

using namespace cv;

//enum MissionStatus{ MISSION_NOT_STARTED, DETECTION,  WAIT_USER_VALIDATION_DETECTION, TRACKING,MEASUREMENT,MISSION_FINISHED};


class MissionThread : public QThread
{
    Q_OBJECT
public:
    explicit MissionThread(QObject *parent = 0);
    ~MissionThread();



private:

    void run();

signals:


public slots:


};



//class Mission : public QThread
//{
//    Q_OBJECT
//public:
//    explicit Mission(QObject *parent = 0);
//    ~Mission();


//private:

//    //MissionStatus mission_status;

//    //void run();

//signals:


//public slots:


//};

#endif // MISSION_H
