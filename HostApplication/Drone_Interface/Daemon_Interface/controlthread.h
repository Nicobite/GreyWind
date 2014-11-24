#ifndef CONTROLTHREAD_H
#define CONTROLTHREAD_H

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
#include <queue>

#define CMD_BUFFER_PATH "/tmp/proudwing_control"
#define CMD_SEM_E_PATH "/proudwing_ctrl_empty"
#define CMD_SEM_F_PATH  "/proudwing_ctrl_full"


class ControlThread : public QThread
{
    Q_OBJECT

private:
    int m_t_samp_us;
    bool m_stop;
    int m_fd_fifo;
    sem_t *m_sem_full;
    sem_t *m_sem_empty;
    std::queue<std::string> m_cmd_fifo;

protected:
    void run();

public:
    ControlThread(int t_samp_us = 20000);
    ~ControlThread();

    void set_samplig_period(int samp_us);

public slots:
    void key_press_cmd(int key_val);
    void key_release_cmd();
};

#endif // CONTROLTHREAD_H
