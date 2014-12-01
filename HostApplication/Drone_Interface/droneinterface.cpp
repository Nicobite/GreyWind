#include "droneinterface.h"

DroneInterface::DroneInterface(int childPID, char *childSemFD, int childPipeWrFD)
{
    this->m_daemon_interface = new DaemonInterface(childPID, childSemFD, childPipeWrFD);
}

DroneInterface::~DroneInterface()
{
    delete this->m_daemon_interface;
    //delete this->m_udp_client;
}

DaemonInterface* DroneInterface::get_daemon()
{
    return this->m_daemon_interface;
}


SensorThread* DroneInterface::get_sensor_thread()
{
    return this->m_sensor_thread;
}

void DroneInterface::launch_sensor_thread()
{
    this->m_sensor_thread = new SensorThread();
    this->m_sensor_thread->start();
}
