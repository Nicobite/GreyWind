#include <QApplication>

#include "mainwindow.h"
#include "includes.h"
#include "semaphore.h"
#include "control.h"

void controlCHandler (int signal)
{
    printf("Killing the application ...\n");
    exit (0);
}

int main(int argc, char *argv[])
{
#if NBM
#include <QMainWindow>
#include "Detection/facedetection.hpp"
#include "Threads/facethread.h"
    QApplication a(argc, argv);

    MainWindow w;
    Facethread thread1;

    // Connecting main window and thread
    // * updating video on main widget
    QObject::connect(&thread1   , SIGNAL(   displayedFrame(QImage)          ),
                     &w         , SLOT  (   getFrame(QImage))               );
    // * requesting source update
    QObject::connect(&thread1   , SIGNAL(   sigReqSrc()                     ),
                     &w         , SLOT  (   getSrc())                       );
    // * sending back new source
    QObject::connect(&w         , SIGNAL(   sigResponsesSrc(std::string)    ),
                     &thread1   , SLOT  (   updateSrc(std::string))         );

    // Starting up the threads
    w.show();
    thread1.start();

    return a.exec();

#else

    signal (SIGABRT, &controlCHandler);
    signal (SIGTERM, &controlCHandler);
    signal (SIGINT, &controlCHandler);
    signal (SIGABRT, &controlCHandler);
    signal (SIGSEGV, &controlCHandler);

    char child_sem_fd[] = "connectDaemon";
    int pipefd[2];      //daemon launcher-APP pipe
    int log_fd;

    pipe(pipefd);
    sem_t *sem_connect = sem_open(child_sem_fd, O_CREAT, 0666, 0);
    if(sem_connect==SEM_FAILED)
    {
        perror("main sem connect");
        exit(1);
    }
    unlink(child_sem_fd);

    int child = fork();
    switch(child)
    {
    case -1:
        perror("fork");
        exit(1);
    case 0:         //child
        close(pipefd[1]); // close the write-end of the pipe
        //hold on
        printf("Waiting for parent...");
        sem_wait(sem_connect);
        char buf[2];
        read(pipefd[0], &buf, 2);
        close(pipefd[0]);
        printf("Proceeding.");

        log_fd = open("daemon_log.txt", O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
        dup2(log_fd, 1);
        dup2(log_fd, 2);

        if(buf[0]=='v' && buf[1]=='c'){
            execl("./proudwing_daemon","./proudwing_daemon -c -v", NULL);
        } else{
            if(buf[0]==' ' && buf[1]=='c'){
                execl("./proudwing_daemon","./proudwing_daemon -c", NULL);
            }else if(buf[0]=='v' && buf[1]==' '){
                execl("./proudwing_daemon","./proudwing_daemon -v", NULL);
            }else{
                execl("./proudwing_daemon","./proudwing_daemon", NULL);
            }
        }

        perror("daemon");
        exit(1);
        break;
    default:        //parent
        close(pipefd[0]); //close the read-end of the pipe

        QApplication a(argc, argv);

        //MainWindow w(child, child_sem_fd, pipefd[1]);
        Control c(child, child_sem_fd, pipefd[1]);

        return a.exec();
    }

#endif

}
