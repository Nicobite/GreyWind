#include "navdatathread.h"
#include "control_states.h"

NavdataThread::NavdataThread(int t_samp_us): m_t_samp_us(t_samp_us)
{
    qRegisterMetaType<navdata_t> ("navdata_t");

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
    this->m_nd.ctrl_state = std::string(ctrl_state_str(0));
    this->m_nd.vbat = 0;
    this->m_nd.altitude = 0;
    this->m_nd.pitch = 0.0;
    this->m_nd.roll = 0.0;
    this->m_nd.yaw = 0.0;
    this->m_nd.vx = 0.0;
    this->m_nd.vy = 0.0;
    this->m_nd.vz = 0.0;
}

NavdataThread::~NavdataThread()
{
    this->m_stop = true;
    this->quit();
    this->wait();
}

void NavdataThread::run()
{
    static int ctrl_state, vbat_percentage, altitude;
    static float theta, phi, psi, vx, vy, vz;

    while(!this->m_stop)
    {
        if(sem_trywait(m_sem_full)==0)
        {
            if((m_fd_fifo=open(NAVD_BUFFER_PATH, O_RDONLY)) != - 1)
            {
                if(read(m_fd_fifo, &ctrl_state, sizeof(int)) == -1)
                    perror("Navdata read error occured: ");
                if(read(m_fd_fifo, &vbat_percentage, sizeof(int)) == -1)
                    perror("Navdata read error occured: ");
                if(read(m_fd_fifo, &theta, sizeof(float)) == -1)
                    perror("Navdata read error occured: ");
                if(read(m_fd_fifo, &phi, sizeof(float)) == -1)
                    perror("Navdata read error occured: ");
                if(read(m_fd_fifo, &psi, sizeof(float)) == -1)
                    perror("Navdata read error occured: ");
                if(read(m_fd_fifo, &altitude, sizeof(int)) == -1)
                    perror("Navdata read error occured: ");
                if(read(m_fd_fifo, &vx, sizeof(float)) == -1)
                    perror("Navdata read error occured: ");
                if(read(m_fd_fifo, &vy, sizeof(float)) == -1)
                    perror("Navdata read error occured: ");
                if(read(m_fd_fifo, &vz, sizeof(float)) == -1)
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
                this->m_nd.ctrl_state = std::string(ctrl_state_str(ctrl_state));
                this->m_nd.vbat = vbat_percentage;
                this->m_nd.altitude = altitude;
                this->m_nd.pitch = theta/1000;
                this->m_nd.roll = phi/1000;
                this->m_nd.yaw = psi/1000;
                this->m_nd.vx = vx;
                this->m_nd.vy = vy;
                this->m_nd.vz = vz;

                emit sendCurrentND(this->m_nd);
            }
        }
        this->usleep(m_t_samp_us);
    }
}


void NavdataThread::set_samplig_period(int samp_us)
{
    this->m_t_samp_us = samp_us;
}

navdata_t NavdataThread::get_navdata()
{
    return this->m_nd;
}


/*============================================================================*/
/**
  * Builds a string describing the drone control state.
  * @param ctrl_state Integer containing the control state from the unpacked navdata.
  * @return A pointer to the built string. The returned address always points to the last built string.
  */
const char* ctrl_state_str(int ctrl_state)
{
  static char str_ctrl_state[32];

  ctrl_string_t* ctrl_string;
  int major = ctrl_state >> 16;
  int minor = ctrl_state & 0xFFFF;

  if( strlen(ctrl_states[major]) < 32 )
  {
    memset(str_ctrl_state, 0, sizeof(str_ctrl_state));

    strcat(str_ctrl_state, ctrl_states[major]);
    ctrl_string = control_states_link[major];

    if( ctrl_string != NULL && (strlen(ctrl_states[major]) + strlen(ctrl_string[minor]) < 32) )
    {
      strcat( str_ctrl_state, " | " );
      strcat( str_ctrl_state, ctrl_string[minor] );
    }
  }
  else
  {
    memset( str_ctrl_state, '#', sizeof(str_ctrl_state) );
  }

  return str_ctrl_state;
}
