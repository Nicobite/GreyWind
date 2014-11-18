#ifndef DRONEINTERFACETEST_H
#define DRONEINTERFACETEST_H

#include <QWidget>

namespace Ui {
class DroneInterfaceTest;
}

class DroneInterfaceTest : public QWidget
{
    Q_OBJECT

public:
    explicit DroneInterfaceTest(QWidget *parent = 0);
    ~DroneInterfaceTest();

private:
    Ui::DroneInterfaceTest *ui;
};

#endif // DRONEINTERFACETEST_H
