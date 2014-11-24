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


UDPClient* DroneInterface::get_udp()
{
    return this->m_udp_client;
}
