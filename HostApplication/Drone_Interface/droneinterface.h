#ifndef DRONEINTERFACE_H
#define DRONEINTERFACE_H

#include "Drone_Interface/Daemon_Interface/daemoninterface.h"
#include "Drone_Interface/UDP_Interface/udp_wrapper.hpp"

class DroneInterface
{
private:
    DaemonInterface *m_daemon_interface;
    UDPClient *m_udp_client;

public:
    DroneInterface();
    ~DroneInterface();
};

#endif // DRONEINTERFACE_H
