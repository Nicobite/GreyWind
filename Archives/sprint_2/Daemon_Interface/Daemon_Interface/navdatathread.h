#ifndef NAVDATATHREAD_H
#define NAVDATATHREAD_H

#include <errno.h>
#include <fcntl.h>
#include <string.h>
#include <stddef.h>
#include <stdio.h>
#include <unistd.h>
#include <semaphore.h>
#include <string>

#include <QThread>

#define NAVD_BUFFER_PATH "/tmp/proudwing_navdata"
#define NAVD_SEM_E_PATH "/proudwing_nd_empty"
#define NAVD_SEM_F_PATH  "/proudwing_nd_full"

class NavdataThread : public QThread
{
    Q_OBJECT

private:
    int m_t_samp_us;

    int m_fd_fifo;
    sem_t *m_sem_full;
    sem_t *m_sem_empty;

    int m_ctrl_state, m_vbat_percentage, m_altitude;
    float m_theta, m_phi, m_psi, m_vx, m_vy, m_vz;

protected:
    void run();

public:
    NavdataThread(int t_samp_us = 20000);
    ~NavdataThread();

    void set_samplig_period();

    int get_ctrl_state();
    std::string get_ctrl_state_str();
    int get_vbat();
    int get_altitude();
    float get_theta();
    float get_phi();
    float get_psi();
    float get_vx();
    float get_vy();
    float get_vz();


};

#endif // NAVDATATHREAD_H
