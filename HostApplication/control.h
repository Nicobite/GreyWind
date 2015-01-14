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
#include "missionthread.h"

/* Structure for one mission */
typedef struct t_mission{
    QString algo;
    QString obj;
}Mission;

enum AppState{ AppTestMode, AppMissionMode};

enum MissionState{ MissionIdle, MissionDetection, MissionTracking, MissionLocalisation};

class Control: public QObject
{
    Q_OBJECT

public:
    Control(int childPID=0, char* childSemFD=NULL, int childPipeWrFD=0, QObject *parent = 0);
    ~Control();

    //void state_machine();

protected:
     //void run();

private:
    bool            m_running;

    MainWindow      m_mainWindow;
    bool            m_connected;
    DroneInterface* m_interface;
    std::string     m_currentVidSource;
    VideoThread*    m_vidThread;
    DetectThread*   m_detectThread;
    std::string     m_currentDetectAlgo;
    std::string     m_currentDetectObject;
    LocalizationFunctions m_locfunc;
    Collimator      m_collimator;
    MissionThread* m_missionThread;

    AppState m_appState;
    MissionState m_missionState;
	std::queue<Mission> m_listMission;

    bool m_objDetected;
    Mat m_imgDetected;
    Size m_sizeDetected;
    Point m_centerDetected;

    int m_videoDestination; //0: none, 1: detect, 2: tracker, 3:save to m_objDetected
    bool m_frameSaved; //internal variable

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

    void updateDetectionAlgo(std::string algo);
    void updateDetectionObject(std::string obj);

    void handleFrame(Mat frame);
    void changeVideoSource(std::string src, int err=0);

    void handleDetectedObject(Point point, Size size);
    void handleDetectThreadMessages(std::string mess);

    void addObjectToBlacklist(Point point, Size size);
    void clearAllBlackList();

    void handleValidatedObject(Point point, Size size);
    void handleTrackerInitialisation();
    void handleCollimatorThreadMessages(std::string mess);

	void addNewMission(QString algo, QString obj);
    void subMission();
    void runMission();
    void disconnectSonarMission();
    void collimatorDeinit();
};

#endif // CONTROL_H

