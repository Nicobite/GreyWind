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
    explicit MainWindow(int childPID=0, char* childSemFD=NULL, int childPipeWrFD=0, QWidget *parent = 0);
    ~MainWindow();
    Ui::MainWindow *ui;

    //void keyPressEvent(QKeyEvent* e);
    //void keyReleaseEvent(QKeyEvent* e);

private:
    ControlView m_controlWindow;
    DroneInterface* m_interface;
    Facethread m_thread1;
    bool m_connected;

public slots:
    void getFrame(QImage image);
    void getSrc();
    void getFramesB4Detect(double fbd);
    void displayControl();
    void connectDrone();
    void updateNavdataView(navdata_t nd);

signals:
    void sigResponsesSrc(std::string src);
    void sigDispToCuteConsole(QString);

};

#endif // MAINWINDOW_H
