#ifndef PROUDWING_H
#define PROUDWING_H

#include <QGridLayout>
#include <QWidget>
#include "Drone_Interface/droneinterface.h"
#include <QKeyEvent>
#include "mainwindow.h"
#include "Detection/facedetection.hpp"
#include "Threads/facethread.h"
#include "includes.h"

class Proudwing : public QWidget
{
    Q_OBJECT

private:
    DroneInterface m_interface;
    MainWindow* m_w;
    Facethread m_thread1;

public:
    Proudwing(QWidget *parent = 0);
    ~Proudwing();

    void keyPressEvent(QKeyEvent* e);
    void keyReleaseEvent(QKeyEvent* e);

signals:

public slots:

};

#endif // PROUDWING_H
