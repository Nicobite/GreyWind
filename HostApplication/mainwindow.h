#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "help.h"
#include "controlview.h"
#include <QGridLayout>

#include <QWidget>
#include "Drone_Interface/droneinterface.h"
#include <QKeyEvent>
#include "Detection/facedetection.hpp"
#include "Threads/facethread.h"
#include "includes.h"

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

private:
    ControlView m_controlWindow;
    DroneInterface* m_interface;
    Facethread m_thread1;
    bool m_connected;

public slots:
    void setFrame(QImage image);
    void updateNavdataView(navdata_t nd);
    void drawDetectedEllipse(Point center, Size size);

    //void displayControl();
    //void connectDrone();

private slots:
    void emitVidSource(const QString& text);
    void emitFramesB4Detect(double fbd);

signals:
    void vidSourceChanged(std::string src);
    void detectFrameRateChanged(int fbd);
    //void dispToCuteConsole(QString);

};

#endif // MAINWINDOW_H
