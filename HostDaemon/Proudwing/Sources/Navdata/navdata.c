/*
 * @video_stage.c
 * @author Grey Wind
 * @date 2014
 *
 *  Video pipeline thread
 *
 */


#include <Navdata/navdata.h>

sem_t *sem_full;
sem_t *sem_empty;

/* Initialization local variables before event loop  */
inline C_RESULT demo_navdata_client_init( void* data )
{
    sem_full = sem_open(NAVD_SEM_F_PATH, O_CREAT, 0666, 1);
    sem_empty = sem_open(NAVD_SEM_E_PATH, O_CREAT, 0666, 1);

    unlink(NAVD_BUFFER_PATH);
    int fd;
    if((fd=open(NAVD_BUFFER_PATH, O_CREAT, 0666)) == -1)
    {
        fprintf(stderr, "Cannot create FIFO engine..\n");
        return C_FAIL;
    }
    close(fd);
    /*if((mkfifo(NAVD_BUFFER_PATH, 0666)) == -1)
    {
        fprintf(stderr, "Cannot create FIFO engine..\n");
        return C_FAIL;
    }*/
  #if 0
    printf("[Debug] Navdata pipe has been created.\n");
  #endif

    return C_OK;
}

/* Receving navdata during the event loop */
inline C_RESULT demo_navdata_client_process( const navdata_unpacked_t* const navdata )
{
	const navdata_demo_t*nd = &navdata->navdata_demo;
    int fd_fifo;
    int ctrl_state=nd->ctrl_state, vbat_percentage=nd->vbat_flying_percentage, altitude=nd->altitude;
    float theta=nd->theta, phi=nd->phi, psi=nd->psi, vx=nd->vx, vy=nd->vy, vz=nd->vz;

    if(sem_trywait(sem_empty)==0){

        if((fd_fifo=open(NAVD_BUFFER_PATH, O_WRONLY)) != - 1)
        {

            if(write(fd_fifo, &ctrl_state, sizeof(int)) == -1)
                perror("Navdata write error occured: ");
            if(write(fd_fifo, &vbat_percentage, sizeof(int)) == -1)
                perror("Navdata write error occured: ");
            if(write(fd_fifo, &theta, sizeof(float)) == -1)
                perror("Navdata write error occured: ");
            if(write(fd_fifo, &phi, sizeof(float)) == -1)
                perror("Navdata write error occured: ");
            if(write(fd_fifo, &psi, sizeof(float)) == -1)
                perror("Navdata write error occured: ");
            if(write(fd_fifo, &altitude, sizeof(int)) == -1)
                perror("Navdata write error occured: ");
            if(write(fd_fifo, &vx, sizeof(float)) == -1)
                perror("Navdata write error occured: ");
            if(write(fd_fifo, &vy, sizeof(float)) == -1)
                perror("Navdata write error occured: ");
            if(write(fd_fifo, &vz, sizeof(float)) == -1)
                perror("Navdata write error occured: ");
            close(fd_fifo);
#if 0
            printf("=====================\nNavdata for flight demonstrations =====================\n\n");

            printf("Control state : %i\n", ctrl_state);
            printf("Battery level : %i mV\n", nd->vbat_flying_percentage);
            printf("Orientation   : [Theta] %4.3f  [Phi] %4.3f  [Psi] %4.3f\n", theta, phi, psi);
            printf("Altitude   "/proudwing_nd_empty"   : %i\n", altitude);
            printf("Speed         : [vX] %4.3f  [vY] %4.3f  [vZPsi] %4.3f\n", vx, vy, vz);

            printf("\033[8A");
#endif
        }
        sem_post(sem_full);

    }

    return C_OK;
}

/* Relinquish the local resources after the event loop exit */
inline C_RESULT demo_navdata_client_release( void )
{
    sem_close(sem_empty);
    sem_close(sem_full);
    sem_destroy(sem_empty);
    sem_destroy(sem_full);
    sem_unlink(NAVD_SEM_F_PATH);
    sem_unlink(NAVD_SEM_E_PATH);
    unlink(NAVD_BUFFER_PATH);

    return C_OK;
}

/* Registering to navdata client */
BEGIN_NAVDATA_HANDLER_TABLE
  NAVDATA_HANDLER_TABLE_ENTRY(demo_navdata_client_init, demo_navdata_client_process, demo_navdata_client_release, NULL)
END_NAVDATA_HANDLER_TABLE

