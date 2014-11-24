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
    DroneInterface(int childPID=0, char* childSemFD=NULL, int childPipeWrFD=0);
    ~DroneInterface();
    DaemonInterface* get_daemon();
    UDPClient* get_udp();
};

#endif // DRONEINTERFACE_H
