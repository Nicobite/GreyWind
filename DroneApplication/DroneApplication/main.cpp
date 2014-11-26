#include <errno.h>
#include <fcntl.h>
#include <string.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <semaphore.h>
#include <signal.h>
#include "protocol.hpp"

using namespace std;

char udpfull_sem_fd[] = "udpReceiverBufferFull";
char usbfull_sem_fd[] = "usbReceiverBufferFull";
char udphostaddr_sem_fd[] = "udpHostAddrOK";
//#define DEBUG

void controlCHandler (int signal)
{
    unlink(udpfull_sem_fd);
    unlink(usbfull_sem_fd);
    unlink(udphostaddr_sem_fd);

    printf("Killing the application ...\n");

    if(signal==SIGSEGV)
        exit(-1);
    else
        exit(0);
}

int main()
{
    signal (SIGABRT, &controlCHandler);
    signal (SIGTERM, &controlCHandler);
    signal (SIGINT, &controlCHandler);
    signal (SIGABRT, &controlCHandler);
    //signal (SIGSEGV, &controlCHandler);

    int udp_pipe_fd[2];      //UDP receiver -> router pipe
    int usb_pipe_fd[2];      //USB receiver -> router pipe

    int udp_host_addr_pipe_fd[2];
    bool host_addr_known = false;

    pipe(udp_pipe_fd);
    pipe(usb_pipe_fd);

    pipe(udp_host_addr_pipe_fd);

    sem_t* sem_udp_full = sem_open(udpfull_sem_fd, O_CREAT, 0666, 0);
    if(sem_udp_full==SEM_FAILED)
    {
        perror("main sem connect");
        exit(1);
    }
    unlink(udpfull_sem_fd);

    sem_t* sem_usb_full = sem_open(usbfull_sem_fd, O_CREAT, 0666, 0);
    if(sem_usb_full==SEM_FAILED)
    {
        perror("main sem connect");
        exit(1);
    }
    unlink(usbfull_sem_fd);

    sem_t* sem_udp_addr_ok = sem_open(udphostaddr_sem_fd, O_CREAT, 0666, 0);
    if(sem_usb_full==SEM_FAILED)
    {
        perror("main sem connect");
        exit(1);
    }
    unlink(usbfull_sem_fd);


    int firstChild = fork();
    switch(firstChild)
    {
    case -1:
        perror("firstChild fork");
        exit(1);

    case 0:         //UDP Receiver
    {
        close(udp_pipe_fd[0]); // close the read-end of the pipe
        close(usb_pipe_fd[0]); // close the usb pipe
        close(usb_pipe_fd[1]); // close the usb pipe
        close(udp_host_addr_pipe_fd[0]); // close the read-end of the pipe


        Trame udp_data;
        int port, port_prev;
        std::string client_addr, addr_prev;

        /** UDP reception thread **/
        while(1){
#ifdef DEBUG
            write(udp_pipe_fd[1], "C'est UDP!", 10);
            sem_post(sem_udp_full);
            usleep(1250000);
#else
            udp_data = Reception_from_HOST_PC();
            write(udp_pipe_fd[1], &udp_data, sizeof(Trame));
            sem_post(sem_udp_full);

            port = get_server()->get_client_port();
            client_addr = get_server()->get_client_addr();

            if(!host_addr_known || port_prev != port || addr_prev!=client_addr){
                write(udp_host_addr_pipe_fd[1], &port, sizeof(int));
                write(udp_host_addr_pipe_fd[1], client_addr.c_str(), client_addr.length()+1);
                sem_post(sem_udp_addr_ok);
                host_addr_known = true;
                port_prev = port;
                addr_prev = client_addr;
            }
#endif

        }

        perror("firstChild failure");
        exit(1);
    }
    default:
    {
        int secondChild = fork();
        switch(secondChild)
        {
        case -1:
            perror("secondChild fork");
            exit(1);

        case 0:
            close(usb_pipe_fd[0]); // close the read-end of the pipe
            close(udp_pipe_fd[0]); // close pipe
            close(udp_pipe_fd[1]); // close pipe
            close(udp_host_addr_pipe_fd[0]); // close pipe
            close(udp_host_addr_pipe_fd[1]); // close pipe

            Trame usb_data;

            /** USB reception thread **/
            while(1){

#ifdef DEBUG
            write(usb_pipe_fd[1], "C'est USB!", 10);
            sem_post(sem_usb_full);
            usleep(750000);
#else
            usb_data = Reception_from_STM32();

            write(usb_pipe_fd[1], &usb_data, sizeof(Trame));
            sem_post(sem_usb_full);
#endif
            }

            perror("secondChild failure");
            exit(1);

        default:    //parent
            close(udp_pipe_fd[1]); // close the write-end of the pipe
            close(usb_pipe_fd[1]); // close the write-end of the pipe
            close(udp_host_addr_pipe_fd[1]); // close the write-end of the pipe

            char buf[50];

            Trame router_data;
            int client_port;

            int nbytes=0;
            /** Router thread **/
            while(1){
#ifdef DEBUG
                if(sem_trywait(sem_udp_full)==0){
                    if((nbytes=read(udp_pipe_fd[0], buf, 10)) == 10)
                    {
                        //ADD buf TREATMENT
                        buf[10]='\0';
                        printf("Router received from UDP: %s\n", buf);

                    } else{
                        printf("Programming fault, never supposed to reach here!\n");
                    }
                }
                if(sem_trywait(sem_usb_full)==0){
                    if((nbytes=read(usb_pipe_fd[0], buf, 10)) == 10)
                    {

                        //ADD buf TREATMENT
                        buf[10]='\0';
                        printf("Router received from USB: %s\n", buf);


                    } else{
                        printf("Programming fault, never supposed to reach here!\n");
                    }
                }

                usleep(50000);
#else
                if(sem_trywait(sem_udp_addr_ok)==0){
                    read(udp_host_addr_pipe_fd[0], &client_port, sizeof(int));
                    read(udp_host_addr_pipe_fd[0], buf, 50);
                    std::string client_addr(buf);
                    printf("[Router] Got new client address: %s, port %i\n", client_addr.c_str(), client_port);
                    get_server()->set_client(client_addr, client_port);
                    printf("[Router] Client address set.\n");
                    host_addr_known = true;
                }

                if(sem_trywait(sem_udp_full)==0){
                    if((nbytes=read(udp_pipe_fd[0], &router_data, sizeof(Trame))) == 10)
                    {
                        if(router_data.id_number != 226){
                            printf("[ROUTER] Data received from UDP!\n");
                            Routage(&router_data);
                        }
                    } else{
                        printf("Programming fault, never supposed to reach here!\n");
                    }
                }
                if(sem_trywait(sem_usb_full)==0){
                    if((nbytes=read(usb_pipe_fd[0], &router_data, sizeof(Trame))) == 10)
                    {
                        printf("[USB RX] Recv data!!!!!\n");
                        if(router_data.id_number != 226){
                            printf("[ROUTER] Data received from USB!\n");
                            Routage(&router_data);
                        }
                    } else{
                        printf("Programming fault, never supposed to reach here!\n");
                    }
                }

                usleep(100000);
#endif
            }

            perror("main_process");
            return -1;
        }
    }
    }

    return 0;
}

