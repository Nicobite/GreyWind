#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGridLayout>
#include <QWidget>
#include <QKeyEvent>

#include "includes.h"
#include "GUI/videoview.h"
#include "Drone_Interface/droneinterface.h"
#include "GUI/help.h"
#include "GUI/helpdetect.h"
#include "GUI/webview.h"
#include "GUI/detection.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    Ui::MainWindow *ui;

    void dispToCuteConsole(QString message);
    void updateLocationView(float x, float y, float z, float psi);

    void keyPressEvent(QKeyEvent* e);
    void keyReleaseEvent(QKeyEvent* e);
    void focusInEvent(QFocusEvent* event);
    void focusOutEvent(QFocusEvent* event);


private:
    bool m_connected;
    Help m_helpWindow;
    HelpDetect m_helpDetectWindow;
    WebView m_3DWindow;
    Detection m_detectionWindow;
    Size m_size; // Get from Control class
    Point m_center; // Get from Control class
    Size m_size_detected; // Get from pressure on detectButton
    Point m_center_detected; // Get from pressure on detectButton
    std::string m_objectName;
    bool m_haltDetection;
    QString m_algochoosen;
    int m_skipValue;
    std::string missionTracker;
    int m_current_objective;

    bool m_isLocalized;
    double m_locDistance, m_locAngle;
	
public slots:
    void setFrame(QImage image);
    void updateNavdataView(navdata_t nd);
    void drawDetectedEllipse(Point center, Size size);
    void drawTrackedRect(Point center, Size size);
    void drawLaserDot(Point center, Size size);
    void updateConnectionStatus(bool status);
    void updateSonarView(int distance);
    void updateTrackState(std::string state);

    void emitLaserState(int state);
    void emitSonarRequest();

    void updateLocalizedObjectInfo(double dist, double angle);

private slots:
    void emitVidSource(const QString& text);
    void emitFramesB4Detect(double fbd);
    void emitRstPosButton();
    void emitConnectButton();

    void displayHelp();
    void display3D();

    void displayDetection();
    void validDetection();
    void addToBlackListDetection();
    void skip1Detection();
    void skip5Detections();
    void skip10Detections();
    void displayHelpDetect();

    void emitAlgoChoice(const QString& text);
    void emitObjectChoice();

    void emitTrackerChoice(const QString& text);
    void emitTrackerInit();
    void clearBlackList();
    void updateSizeBlackList(int size);

    void addAlgoObject();
    void subAlgoObject();
    //void emitAlgoDetectionMissionChoice(const QString& text);
    //void emitAlgoTrackingMissionChoice(const QString& text);
    void stopMission();
    void startMission();
    //void emitObjectChoiceMission();
    //void updateListWidget(QString text);
    void updateSonarViewMission(int distance);
    void reInitWidgetsMission();
    void changeStatusMission(QString text);

    void emitTakePicture();

signals:
    void vidSourceChanged(std::string src);
    void detectFrameRateChanged(int fbd);
    void rstPosButtonClicked();
    void connectButtonClicked();
    void laserState(bool state);
    void sonarRequest();

    void sigValidatedObject(Point point, Size size);
    void sendObjectToBlackList(Point point, Size size);
    void sendClearBlackList();

    void detectAlgoChanged(std::string src);
    void detectObjectChanged(std::string src);

    void detectTrackerChanged(std::string src);
    void initialiseTracker();

    void pressCmd(int keyval);
    void releaseCmd();

    void sigTakePicture();

    //void newMissionObject(QString algo, QString obj);
    void delMissionObject();
    void stopMissionSignal();
    void startMissionSignal();

    void detectionAlgoMissionChoosen(std::string scr);
    void trackingAlgoMissionChoosen(QString scr);
    void detectObjectMissionChoosen(std::string src);
    void missionStatusChanged();
    void sendUserResponseDetection(bool res);
    void sendTrackStatus(std::string st);
    void disconnectSonarViewMission();

    void to3DView(QString name, int x, int y, int z);
};

#endif // MAINWINDOW_H
