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
#include <errno.h>
#include <QThread>

#define NAVD_BUFFER_PATH "/tmp/proudwing_navdata"
#define NAVD_SEM_E_PATH "/proudwing_nd_empty"
#define NAVD_SEM_F_PATH  "/proudwing_nd_full"

typedef struct navdata{
    std::string ctrl_state;
    int vbat;
    int altitude;
    float pitch;
    float roll;
    float yaw;
    float vx;
    float vy;
    float vz;
}navdata_t;

const char* ctrl_state_str(int ctrl_state);


class NavdataThread : public QThread
{
    Q_OBJECT

private:
    int m_t_samp_us;
    bool m_stop;
    int m_fd_fifo;
    sem_t *m_sem_full;
    sem_t *m_sem_empty;

    navdata_t m_nd;

protected:
    void run();

signals:
    void sendCurrentND(navdata_t nd);

public:
    NavdataThread(int t_samp_us = 20000);
    ~NavdataThread();

    void set_samplig_period(int samp_us);

    navdata_t get_navdata();
};

#endif // NAVDATATHREAD_H
