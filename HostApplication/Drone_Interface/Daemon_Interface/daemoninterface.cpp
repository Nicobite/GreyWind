#include "daemoninterface.h"

DaemonThread::DaemonThread(bool mp4codec, bool videothread){
    m_mp4codec = mp4codec;
    m_videothread = videothread;
}

DaemonThread::~DaemonThread(){
    close(this->m_log_fd);
    this->quit();
    this->wait();
}

void DaemonThread::run(){
    this->m_log_fd = open("daemon_log.txt", O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
    dup2(m_log_fd, 1);
    dup2(m_log_fd, 2);

    if(m_mp4codec && m_videothread){
        execl("./proudwing_daemon","./proudwing_daemon -c -v", NULL);
    } else{
        if(m_mp4codec){
            execl("./proudwing_daemon","./proudwing_daemon -c", NULL);
        }else if(m_videothread){
            execl("./proudwing_daemon","./proudwing_daemon -v", NULL);

        }else{
            execl("./proudwing_daemon","./proudwing_daemon", NULL);
        }
    }

    perror("daemon");
    exit(1);
}

DaemonInterface::DaemonInterface(int childPID, char* childSemFD, int childPipeWrFD)
{
    this->m_connected = false;
    this->m_ctrl_state = false;
    this->m_nd_state = false;
    this->m_childPID = childPID;
    this->m_childSemFD = childSemFD;
    this->m_childPipeWrFD = childPipeWrFD;
}

DaemonInterface::~DaemonInterface()
{
    if(m_nd_state){
        this->m_nd_state = false;
        delete this->m_nd_thread;
    }
    if(m_ctrl_state){
        this->m_ctrl_state = false;
        delete this->m_ctrl_thread;
    }
}

void DaemonInterface::launch_navdata_handler()
{
    this->m_nd_thread = new NavdataThread();
    if(this->m_connected)
    {
        this->m_nd_thread->start();
        this->m_nd_state = true;
    } else
    {
        QMessageBox *box = new QMessageBox();
        box->setWindowTitle(QString("Navdata Handler"));
        box->setText(QString("Drone is disconnected."));
        box->show();
    }
}

bool DaemonInterface::is_navdata_running()
{
    return m_nd_state;
}

NavdataThread* DaemonInterface::get_navdata_thread()
{
    return m_nd_thread;
}

void DaemonInterface::launch_control_handler()
{
    this->m_ctrl_thread = new ControlThread();
    if(this->m_connected)
    {
        this->m_ctrl_thread->start();
        this->m_ctrl_state = true;
    } else
    {
        QMessageBox *box = new QMessageBox();
        box->setWindowTitle(QString("Control Handler"));
        box->setText(QString("Drone is disconnected."));
        box->show();
    }
}

bool DaemonInterface::is_control_running()
{
    return m_ctrl_state;
}

ControlThread* DaemonInterface::get_control_thread()
{
    return m_ctrl_thread;
}

bool DaemonInterface::is_drone_available()
{
    if (system("ping 192.168.1.1 -c 1 -w 1 -q >> log_icmp.txt") != 0)
        return false;
    else
        return true;
}


bool DaemonInterface::connect_daemon(bool mp4codec, bool videothread){
    if(this->is_drone_available()){
/*
        this->m_daemon_pid = fork();

        switch(this->m_daemon_pid)
        {
        case -1:
            perror("fork");
            exit(1);
        case 0:
            this->m_log_fd = open("daemon_log.txt", O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
            dup2(m_log_fd, 1);
            dup2(m_log_fd, 2);

            if(mp4codec && videothread){
                execl("./proudwing_daemon","./proudwing_daemon -c -v", NULL);
            } else{
                if(mp4codec){
                    execl("./proudwing_daemon","./proudwing_daemon -c", NULL);
                }else if(videothread){
                    execl("./proudwing_daemon","./proudwing_daemon -v", NULL);

                }else{
                    execl("./proudwing_daemon","./proudwing_daemon", NULL);
                }
            }

            perror("daemon");
            exit(1);
        default:
            //parent
            /*QMessageBox *box = new QMessageBox();
            box->setWindowTitle(QString("Proudwing Daemon"));
            box->setText(QString("Daemon is running."));
            box->show();*/
            //m_daemon_thread = new DaemonThread(mp4codec, videothread);
            //m_daemon_thread->start();


            if(mp4codec && videothread){
                write(m_childPipeWrFD, "vc", 2);
            } else{
                if(mp4codec){
                    write(m_childPipeWrFD, " c", 2);
                }else if(videothread){
                    write(m_childPipeWrFD, "v ", 2);

                }else{
                    write(m_childPipeWrFD, "  ", 2);
                }
            }
            close(m_childPipeWrFD);
            sem_t* sem_connect = sem_open(m_childSemFD, 0);
            if(sem_connect==SEM_FAILED)
            {
                perror("daemon sem connect");
                exit(1);
            }
            sem_post(sem_connect);
            usleep(100000);
            this->m_connected = true;
            return true;
        //}


    } else
    {
        QMessageBox *box = new QMessageBox();
        box->setWindowTitle(QString("Proudwing Daemon"));
        box->setText(QString("Drone is not available."));
        box->show();
        return false;
    }
}


void DaemonInterface::kill_daemon(){
    kill(this->m_childPID, SIGTERM);
    usleep(10000);
    kill(this->m_childPID, SIGTERM);
    usleep(10000);
    kill(this->m_childPID, SIGTERM);
    usleep(10000);
    kill(this->m_childPID, SIGTERM);
    usleep(100000);
    //close(this->m_log_fd);
    //delete m_daemon_thread;
    /*QMessageBox *box = new QMessageBox();
    box->setWindowTitle(QString("Proudwing Daemon"));
    box->setText(QString("Daemon is killed."));
    box->show();*/
}
