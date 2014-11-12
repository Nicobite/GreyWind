/**
 *  \brief    buffered command handler
 *  \author   Greywind
 *  \version  1.0
 *  \date     2014
 */

#include <UI/control_cmd.h>

#define DEBUG (0)

input_device_t autonom = {
  "Autonom",
    open_autonom,
    update_autonom,
    close_autonom
};

sem_t *sem_c_full;
sem_t *sem_c_empty;

////////////////////////////////////
// keyboard controll              //
////////////////////////////////////

C_RESULT open_autonom(void)
{
    sem_c_full = sem_open(CMD_SEM_F_PATH, O_CREAT, 0666, 0);
    sem_c_empty = sem_open(CMD_SEM_E_PATH, O_CREAT, 0666, 0);

    //Create a command buffering file
    unlink(CMD_BUFFER_PATH);
    int fd;
    if((fd=open(CMD_BUFFER_PATH, O_CREAT, 0666)) == -1)
    {
        fprintf(stderr, "Cannot create FIFO engine..\n");
        return C_FAIL;
    }
    close(fd);

#if DEBUG
    printf("[Debug] Control pipe has been created.\n");
#endif

    sem_post(sem_c_empty);

    return C_OK;
}

C_RESULT update_autonom(void)
{
    static char init = 0;
    static int32_t start = 0;
    static float roll=0.0f, pitch=0.0f, gaz=0.0f, yaw=0.0f;
    int fd_fifo;
    char buf[3];
    buf[0] = '\0';
    buf[1] = '\0';
    buf[2] = '\0';


    if(sem_trywait(sem_c_full)==0){
        if((fd_fifo=open(CMD_BUFFER_PATH, O_RDONLY)) == - 1)
        {
        } else{
            if(read(fd_fifo, &buf, sizeof(buf)-1) == -1)
                fprintf(stderr, "Error! can't read from FIFO.\n");
            else{
#if DEBUG
                printf("read now from FIFO : %s\n",buf);
                printf("%u\n", start);
#endif
                if( strcmp(buf, "st") == 0)
                {
                    start ^= 1;
                    ardrone_tool_set_ui_pad_start( start );
#if DEBUG
                    if(start == 1)
                        printf("[Debug] Taking off.\n");
                    else
                        printf("[Debug] Landing...\n");
#endif
                }else if( strcmp(buf, "ft") == 0)
                {
#if DEBUG
                    printf("[Debug] Flat trim.\n");
#endif
                    ardrone_at_set_flat_trim();
                }else if( strcmp(buf, "fw") == 0)
                    {
#if DEBUG
                    printf("[Debug] Fly forward.\n");
#endif
                    pitch = -1.0;
                }
                else if( strcmp(buf, "bw") == 0)
                {
#if DEBUG
                    printf("[Debug] Fly backward.\n");
#endif
                    pitch = 1.0;
                }
                else if( strcmp(buf, "ri") == 0)
                {
#if DEBUG
                    printf("[Debug] Fly to right side.\n");
#endif
                    roll = 1.0;
                }
                else if( strcmp(buf, "le") == 0)
                {
#if DEBUG
                    printf("[Debug] Fly to left side.\n");
#endif
                    roll = -1.0;
                }
                else if( strcmp(buf, "tl") == 0)
                {
#if DEBUG
                    printf("[Debug] Turn to left side.\n");
#endif
                    yaw = -1.0;
                }
                else if( strcmp(buf, "tr") == 0)
                {
#if DEBUG
                    printf("[Debug] Turn to right side.\n");
#endif
                    yaw = 1.0;
                }
                else if( strcmp(buf, "up") == 0)
                {
#if DEBUG
                    printf("[Debug] Get up.\n");
#endif
                    gaz = 1.0;
                }
                else if( strcmp(buf, "do") == 0)
                {
#if DEBUG
                    printf("[Debug] Get down.\n");
#endif
                    gaz = -1.0;
                }
                else if( strcmp(buf, "cl") == 0)
                {
#if DEBUG
                    printf("[Debug] Clear.\n");
#endif
                    roll = 0.0;
                    pitch = 0.0;
                    gaz = 0.0;
                    yaw = 0.0;
                }
                else{
#if DEBUG
                    printf("[Debug] Nothing to do.\n");
#endif
                    roll = 0.0;
                    pitch = 0.0;
                    gaz = 0.0;
                    yaw = 0.0;
                }
                close(fd_fifo);
                sem_post(sem_c_empty);
            }

        }

        if(start){
            int enable_ctrl = 1;
            if(roll==0 && pitch==0)
                enable_ctrl = 0;

#if DEBUG
            printf("===================== Navdata for flight demonstrations =====================\n\n");

            printf("Gaz : %f\n", gaz);
            printf("Speed   : [Roll] %1.3f  [Pitch] %1.3f  [Yaw] %1.3f\n", roll, pitch, yaw);

            printf("\033[4A");
#endif
            ardrone_tool_set_progressive_cmd(enable_ctrl, roll, pitch, gaz, yaw, 0.0, 0.0);
        }
    }

    return C_OK;
}


C_RESULT close_autonom(void)
{
    sem_close(sem_c_empty);
    sem_close(sem_c_full);
    sem_destroy(sem_c_empty);
    sem_destroy(sem_c_full);
    sem_unlink(CMD_SEM_F_PATH);
    sem_unlink(CMD_SEM_E_PATH);
    unlink(CMD_BUFFER_PATH);
    return C_OK;
}


