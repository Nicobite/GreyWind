#include "droneinterfacetest.h"
#include "ui_droneinterfacetest.h"

DroneInterfaceTest::DroneInterfaceTest(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DroneInterfaceTest)
{
    ui->setupUi(this);
}

DroneInterfaceTest::~DroneInterfaceTest()
{
    delete ui;
}
