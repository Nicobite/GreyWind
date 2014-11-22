#include "droneinterface.h"

DroneInterface::DroneInterface()
{
    this->m_daemon_interface = new DaemonInterface();
    this->m_udp_client = new UDPClient();
}

DroneInterface::~DroneInterface()
{
    delete this->m_daemon_interface;
    delete this->m_udp_client;
}

DaemonInterface* DroneInterface::get_daemon()
{
    return this->m_daemon_interface;
}


UDPClient* DroneInterface::get_udp()
{
    return this->m_udp_client;
}
