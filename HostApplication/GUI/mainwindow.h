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
#include "GUI/threedview.h"
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
    ThreeDView m_3DWindow;
    Detection m_detectionWindow;
    Size m_size; // Get from Control class
    Point m_center; // Get from Control class
    Size m_size_detected; // Get from pressure on detectButton
    Point m_center_detected; // Get from pressure on detectButton
    std::string m_objectName;
    bool m_haltDetection;
    int m_skipValue;
	
public slots:
    void setFrame(QImage image);
    void updateNavdataView(navdata_t nd);
    void drawDetectedEllipse(Point center, Size size);
    void drawTrackedRect(Point center, Size size);
    void drawLaserDot(Point center, Size size);
    void updateConnectionStatus(bool status);
    void updateSonarView(int distance);
    void updateTrackState(std::string state);

private slots:
    void emitVidSource(const QString& text);
    void emitFramesB4Detect(double fbd);
    void emitRstPosButton();
    void emitConnectButton();
    void emitLaserState(int state);
    void emitSonarRequest();
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

};

#endif // MAINWINDOW_H
