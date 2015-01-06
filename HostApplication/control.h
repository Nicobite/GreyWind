#ifndef CONTROL_H
#define CONTROL_H

#include <QMainWindow>
#include <QWidget>
#include <QKeyEvent>
#include <QGridLayout>
#include <QThread>

#include "GUI/mainwindow.h"
#include "GUI/help.h"
#include "Drone_Interface/droneinterface.h"
#include "Video/videothread.hpp"
#include "Detection/detectthread.h"
#include "Detection/detectionalgo.h"
#include "Detection/haarfacedetectionalgo.h"
#include "Tracking/collimator.h"
#include "localizationfunctions.h"


enum AppState{ AppTestMode, AppMissionMode};

enum MissionState{ MissionIdle, MissionDetection, MissionTracking, MissionLocalisation};

class Control: public QObject
{
    Q_OBJECT

public:
    Control(int childPID=0, char* childSemFD=NULL, int childPipeWrFD=0, QObject *parent = 0);
    ~Control();

    void state_machine();

private:
    MainWindow      m_mainWindow;
    bool            m_connected;
    DroneInterface* m_interface;
    std::string     m_currentVidSource;
    VideoThread*    m_vidThread;
    DetectThread*   m_detectThread;
    LocalizationFunctions m_locfunc;
    Collimator      m_collimator;

    AppState m_appState;
    MissionState m_missionState;

    bool m_objDetected;
    Mat m_imgDetected;
    Size m_sizeDetected;
    Point m_centerDetected;

    std::queue<Point> m_blackListCenterFIFO;
    std::queue<Size> m_blackListSizeFIFO;

signals:
    void sendFrameToDetect(Mat frame);
    void sendDetectedObject(Point point, Size size);
    void sendConnectionStatus(bool status);
    void sendSizeBlackList(int size);

public slots:

    void connectDrone();
    void handleNavdata(navdata_t nd);
    void resetPosition();

    void handleFrame(Mat frame);
    void changeVideoSource(std::string src, int err=0);

    void handleDetectedObject(Point point, Size size);
    void handleDetectThreadMessages(std::string mess);

    void addObjectToBlacklist(Point point, Size size);
    void clearAllBlackList();

    void handleTrackerInitialisation();
    void handleCollimatorThreadMessages(std::string mess);
};

#endif // CONTROL_H

