#include "navdatathread.h"

NavdataThread::NavdataThread(int t_samp_us): m_t_samp_us(t_samp_us)
{
    this->m_stop = false;

    this->m_sem_empty = sem_open(NAVD_SEM_E_PATH, 0);
    if(this->m_sem_empty==SEM_FAILED)
    {
        perror("nd sem empty");
        exit(1);
    }
    this->m_sem_full  = sem_open(NAVD_SEM_F_PATH, 0);
    if(this->m_sem_empty==SEM_FAILED)
    {
        perror("nd sem full");
        exit(1);
    }
    this->m_ctrl_state = 0;
    this->m_vbat_percentage = 0;
    this->m_altitude = 0;
    this->m_theta = 0.0;
    this->m_phi = 0.0;
    this->m_psi = 0.0;
    this->m_vx = 0.0;
    this->m_vy = 0.0;
    this->m_vz = 0.0;
}

NavdataThread::~NavdataThread()
{
    this->m_stop = true;
    this->quit();
    this->wait();
}

void NavdataThread::run()
{
    while(!this->m_stop)
    {
        if(sem_trywait(m_sem_full)==0)
        {
            if((m_fd_fifo=open(NAVD_BUFFER_PATH, O_RDONLY)) != - 1)
            {
                if(read(m_fd_fifo, &m_ctrl_state, sizeof(int)) == -1)
                    perror("Navdata read error occured: ");
                if(read(m_fd_fifo, &m_vbat_percentage, sizeof(int)) == -1)
                    perror("Navdata read error occured: ");
                if(read(m_fd_fifo, &m_theta, sizeof(float)) == -1)
                    perror("Navdata read error occured: ");
                if(read(m_fd_fifo, &m_phi, sizeof(float)) == -1)
                    perror("Navdata read error occured: ");
                if(read(m_fd_fifo, &m_psi, sizeof(float)) == -1)
                    perror("Navdata read error occured: ");
                if(read(m_fd_fifo, &m_altitude, sizeof(int)) == -1)
                    perror("Navdata read error occured: ");
                if(read(m_fd_fifo, &m_vx, sizeof(float)) == -1)
                    perror("Navdata read error occured: ");
                if(read(m_fd_fifo, &m_vy, sizeof(float)) == -1)
                    perror("Navdata read error occured: ");
                if(read(m_fd_fifo, &m_vz, sizeof(float)) == -1)
                    perror("Navdata read error occured: ");
                close(m_fd_fifo);
                sem_post(m_sem_empty);
                /*printf("\033[2J\033[5;0H");
                printf("================== Navdata for flight demonstrations ==================\n\n");

                printf("Control state : %i\n", m_ctrl_state);
                printf("Battery level : %i%\n", m_vbat_percentage);
                printf("Orientation   : [Theta] %3.3f° [Phi] %3.3f° [Psi] %3.3f°\n", m_theta/1000, m_phi/1000, m_psi/1000);
                printf("Altitude      : %i mm\n", m_altitude);
                printf("Speed         : [vX] %4.3f  [vY] %4.3f  [vZPsi] %4.3f\n", m_vx, m_vy, m_vz);*/
            }
        }
        this->usleep(m_t_samp_us);
    }
}


void NavdataThread::set_samplig_period(int samp_us)
{
    this->m_t_samp_us = samp_us;
}

int NavdataThread::get_ctrl_state()
{
    return this->m_ctrl_state;
}


//TODO
std::string NavdataThread::get_ctrl_state_str(){
    return std::string("");
}


int NavdataThread::get_vbat()
{
    return this->m_vbat_percentage;
}

int NavdataThread::get_altitude()
{
    return this->m_altitude;
}

float NavdataThread::get_theta()
{
    return this->m_theta;
}

float NavdataThread::get_phi()
{
    return this->m_phi;
}

float NavdataThread::get_psi()
{
    return this->m_psi;
}

float NavdataThread::get_vx()
{
    return this->m_vx;
}

float NavdataThread::get_vy()
{
    return this->m_vy;
}

float NavdataThread::get_vz()
{
    return this->m_vz;
}
