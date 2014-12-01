#ifndef DRONEINTERFACE_H
#define DRONEINTERFACE_H

#include "Drone_Interface/Daemon_Interface/daemoninterface.h"
#include "Drone_Interface/Sensor_Interface/sensorthread.h"

class DroneInterface
{
private:
    DaemonInterface *m_daemon_interface;
    SensorThread *m_sensor_thread;

public:
    DroneInterface(int childPID=0, char* childSemFD=NULL, int childPipeWrFD=0);
    ~DroneInterface();

    DaemonInterface* get_daemon();
    SensorThread * get_sensor_thread();

    void launch_sensor_thread();
};

#endif // DRONEINTERFACE_H
