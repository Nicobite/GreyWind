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

    //void keyPressEvent(QKeyEvent* e);
    //void keyReleaseEvent(QKeyEvent* e);
    void dispToCuteConsole(QString message);
    void updateLocationView(float x, float y, float z, float psi);

    void keyPressEvent(QKeyEvent* e);
    void keyReleaseEvent(QKeyEvent* e);
    void focusInEvent(QFocusEvent* event);
    void focusOutEvent(QFocusEvent* event);

    std::queue<Point> m_blackListCenterFIFO;
    std::queue<Size> m_blackListSizeFIFO;


private:
    bool m_connected;
    Help m_helpWindow;
    ThreeDView m_3DWindow;
    Detection m_detectionWindow;
    Size m_size; // Get from Control class
    Point m_center; // Get from Control class
    Size m_size_detected; // Get from pressure on detectButton
    Point m_center_detected; // Get from pressure on detectButton

public slots:
    void setFrame(QImage image);
    void updateNavdataView(navdata_t nd);
    void drawDetectedEllipse(Point center, Size size);
    void updateConnectionStatus(bool status);
    void updateSonarView(int distance);

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

signals:
    void vidSourceChanged(std::string src);
    void detectFrameRateChanged(int fbd);
    void rstPosButtonClicked();
    void connectButtonClicked();
    void laserState(bool state);
    void sonarRequest();
    void sendStopDrawingEllipse(void);


    void pressCmd(int keyval);
    void releaseCmd();

};

#endif // MAINWINDOW_H
