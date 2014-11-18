#ifndef PROUDWINGAPP_H
#define PROUDWINGAPP_H

#include <QWidget>
#include "Drone_Interface/Daemon_Interface/daemoninterface.h"
#include <QKeyEvent>
#include <QtDebug>

namespace Ui {
class ProudwingApp;
}

class ProudwingApp : public QWidget
{
    Q_OBJECT

public:
    explicit ProudwingApp(QWidget *parent = 0);
    ~ProudwingApp();

    void keyPressEvent(QKeyEvent* e);
    void keyReleaseEvent(QKeyEvent* e);

private:
    Ui::ProudwingApp *ui;
    DaemonInterface interface;

};

#endif // PROUDWINGAPP_H
