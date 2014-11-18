#ifndef DAEMONINTERFACE_H
#define DAEMONINTERFACE_H

#define NAVD_BUFFER_PATH "/tmp/proudwing_navdata"
#define NAVD_SEM_E_PATH "/proudwing_nd_empty"
#define NAVD_SEM_F_PATH  "/proudwing_nd_full"

class DaemonInterface
{
private:


public:
    DaemonInterface();
    ~DaemonInterface();

};

#endif // DAEMONINTERFACE_H
