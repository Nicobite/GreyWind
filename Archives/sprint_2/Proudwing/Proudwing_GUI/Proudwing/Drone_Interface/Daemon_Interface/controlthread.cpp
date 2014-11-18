#include "controlthread.h"

ControlThread::ControlThread(int t_samp_us): m_t_samp_us(t_samp_us)
{
    this->m_stop = false;

    this->m_sem_empty = sem_open(CMD_SEM_E_PATH, 0);
    if(this->m_sem_empty==SEM_FAILED)
    {
        perror("nd sem empty");
        exit(1);
    }
    this->m_sem_full  = sem_open(CMD_SEM_F_PATH, 0);
    if(this->m_sem_empty==SEM_FAILED)
    {
        perror("nd sem full");
        exit(1);
    }
}

ControlThread::~ControlThread()
{
    this->m_stop = true;
    this->quit();
    this->wait();
}

void ControlThread::run()
{
    while(!this->m_stop)
    {
        if(!this->m_cmd_fifo.empty())
        {
            if(sem_trywait(m_sem_empty)==0)
            {
                if((m_fd_fifo=open(CMD_BUFFER_PATH, O_WRONLY)) != - 1)
                {
                    char cmd[2];
                    cmd[0] = m_cmd_fifo.front().at(0);
                    cmd[1] = m_cmd_fifo.front().at(1);

                    write(m_fd_fifo, cmd,2) ;
                    m_cmd_fifo.pop();
                    close(m_fd_fifo);
                    sem_post(m_sem_full);
                }
            }
        }
        this->usleep(m_t_samp_us);
    }
}

void ControlThread::set_samplig_period(int samp_us)
{
    this->m_t_samp_us = samp_us;
}

void ControlThread::key_press_cmd(int key_val)
{
    switch(key_val)
    {
    case 32:        //SPACE: take off/land
        m_cmd_fifo.push("st");
        break;
    case 16777235:     //up arrow: go forward
        m_cmd_fifo.push("fw");
        break;
    case 16777237:     //down arrow: for backwards
        m_cmd_fifo.push("bw");
        break;
    case 16777234:     //left arrow: go left
        m_cmd_fifo.push("le");
        break;
    case 16777236:     //right arrow: go right
        m_cmd_fifo.push("ri");
        break;
    case 90:     //z button: go up
        m_cmd_fifo.push("up");
        break;
    case 83:     //s button: go down
        m_cmd_fifo.push("do");
        break;
    case 81:     //q button: turn left
        m_cmd_fifo.push("tl");
        break;
    case 68:     //d button: turn right
        m_cmd_fifo.push("tr");
        break;
    case 70:     //f button: trim magnetometer
        m_cmd_fifo.push("ft");
        break;
    default:     //unknown button: clear cmd
        m_cmd_fifo.push("cl");
        break;
    }
}


void ControlThread::key_release_cmd()
{
    //released button: clear cmd
    m_cmd_fifo.push("cl");
}
