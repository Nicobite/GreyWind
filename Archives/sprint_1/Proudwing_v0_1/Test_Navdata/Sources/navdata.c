#include <errno.h>
#include <fcntl.h>
#include <string.h>
#include <stddef.h>
#include <stdio.h>
#include <unistd.h>
#include <semaphore.h>

int fd_fifo, fd_fifo_fb;

int readsafe(int fd,void* buff, size_t count){
    int state=0;
    size_t nread = 0;
    int i=0;
#if DEBUG
    printf("Reading... \n")
#endif

    do{
        state = read(fd, buff, count-nread);
        if(state == 0){
            //i ++;
        }else{
            i=0;
            if(state != -1)
                nread += state;
        }
    }while(state != -1 && (i < 10 && nread<count));

    return state;
}


int main(int argc, char *argv[]) 
{
    sem_t *sem_full = sem_open("/proudwing_nd_full", 0);
    sem_t *sem_empty = sem_open("/proudwing_nd_empty", 0);


    float time = 0.0f;
    sem_post(sem_empty);

    while(1)
    {
        if(sem_trywait(sem_full)==0)
        {
            if((fd_fifo=open("/tmp/proudwing_navdata", O_RDONLY)) != - 1)
            {
                int ctrl_state, vbat_percentage, altitude;
                float theta, phi, psi, vx, vy, vz;

                if(readsafe(fd_fifo, &ctrl_state, sizeof(int)) == -1)
                    perror("Navdata write error occured: ");
                if(readsafe(fd_fifo, &vbat_percentage, sizeof(int)) == -1)
                    perror("Navdata write error occured: ");
                if(readsafe(fd_fifo, &theta, sizeof(float)) == -1)
                    perror("Navdata write error occured: ");
                if(readsafe(fd_fifo, &phi, sizeof(float)) == -1)
                    perror("Navdata write error occured: ");
                if(readsafe(fd_fifo, &psi, sizeof(float)) == -1)
                    perror("Navdata write error occured: ");
                if(readsafe(fd_fifo, &altitude, sizeof(int)) == -1)
                    perror("Navdata write error occured: ");
                if(readsafe(fd_fifo, &vx, sizeof(float)) == -1)
                    perror("Navdata write error occured: ");
                if(readsafe(fd_fifo, &vy, sizeof(float)) == -1)
                    perror("Navdata write error occured: ");
                if(readsafe(fd_fifo, &vz, sizeof(float)) == -1)
                    perror("Navdata write error occured: ");
                close(fd_fifo);
                printf("\033[2J\033[5;0H");
                printf("Time : %f \n", time);
                printf("=====================\nNavdata for flight demonstrations =====================\n\n");

                printf("Control state : %i\n", ctrl_state);
                printf("Battery level : %i%\n", vbat_percentage);
                printf("Orientation   : [Theta] %3.3f° [Phi] %3.3f° [Psi] %3.3f°\n", theta/1000, phi/1000, psi/1000);
                printf("Altitude      : %i mm\n", altitude);
                printf("Speed         : [vX] %4.3f  [vY] %4.3f  [vZPsi] %4.3f\n", vx, vy, vz);

                sem_post(sem_empty);
            } else{
                printf("\033[2J\033[5;0H");
                printf("Time : %f \n", time);
                printf("No navdata pipe is open.\n");
            }
        }

        usleep(5000);
        time += 0.005;

    }
    //unlink("/tmp/proudwing_navdata_fb");
    return 0;
}
