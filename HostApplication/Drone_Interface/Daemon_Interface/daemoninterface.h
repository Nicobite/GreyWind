#ifndef DAEMONINTERFACE_H
#define DAEMONINTERFACE_H

#include "navdatathread.h"
#include "controlthread.h"
#include <QMessageBox>
#include <unistd.h>
#include <cstdio>
#include <cstdlib>
#include <signal.h>

class DaemonInterface
{
private:
    bool m_connected;
    pid_t m_daemon_pid;
    int m_log_fd;

    NavdataThread *m_nd_thread;
    bool m_nd_state;

    ControlThread *m_ctrl_thread;
    bool m_ctrl_state;

public:
    DaemonInterface();
    ~DaemonInterface();

    bool connect_daemon();
    void kill_daemon();

    void launch_navdata_handler();
    bool is_navdata_running();
    NavdataThread* get_navdata_thread();

    void launch_control_handler();
    bool is_control_running();
    ControlThread* get_control_thread();

    bool  is_drone_available();
};

#endif // DAEMONINTERFACE_H
