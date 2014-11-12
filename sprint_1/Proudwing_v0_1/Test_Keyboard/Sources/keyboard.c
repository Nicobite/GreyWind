#include <gtk/gtk.h>
#include <sys/types.h>
#include <errno.h>
#include <fcntl.h>
#include <string.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <semaphore.h>
#include <sys/stat.h>



int fd_fifo;
sem_t *sem_full;
sem_t *sem_empty;

gint key_press_cb(GtkWidget *widget, GdkEventKey *kevent, gpointer data)  {
    GtkWidget *btn = (GtkWidget *)data;
    
    /* ============================================================================= */
    //printf("Waiting...\n");

    if(sem_trywait(sem_empty)==0){
        //printf("Done.\n");

        if((fd_fifo=open("/tmp/proudwing_control", O_WRONLY)) == - 1)
        {
          fprintf(stderr, "Can't get connection to the fifo pipe .....\n");
          exit(0);
        } else{

            if(kevent->type == GDK_KEY_PRESS)  {
                g_message("%d, %c;", kevent->keyval, kevent->keyval);
                if(kevent->keyval == 32)
                {
                    g_message("start or stop event");
                    write(fd_fifo,"st",2) ;
                }else if(kevent->keyval == 65362)
                {
                    g_message("forward");
                    write(fd_fifo,"fw",2) ;
                }else if(kevent->keyval == 65364)
                {
                    g_message("backward");
                    write(fd_fifo,"bw",2) ;
                }else if(kevent->keyval == 65361)
                {
                    g_message("left");
                    write(fd_fifo,"le",2) ;
                }else if(kevent->keyval == 65363)
                {
                    g_message("rigth");
                    write(fd_fifo,"ri",2) ;
                }else if(kevent->keyval == 113)
                {
                    g_message("turnleft");
                    write(fd_fifo,"tl",2) ;
                }else if(kevent->keyval == 100)
                {
                    g_message("turnright");
                    write(fd_fifo,"tr",2) ;
                }else if(kevent->keyval == 122)
                {
                    g_message("up");
                    write(fd_fifo,"up",2) ;
                }else if(kevent->keyval == 115)
                {
                    g_message("down");
                    write(fd_fifo,"do",2) ;
                }else if(kevent->keyval == 102)
                {
                    g_message("ft");
                    write(fd_fifo,"ft",2) ;
                }
                else
                {
                    g_message("clear");
                    write(fd_fifo,"cl",2) ;
                }
               // printf("Done.\n");

                close(fd_fifo);

                sem_post(sem_full);
                //printf("Done.\n");
            }
        }
    }

    /* ================================================================================== */

    // void g_signal_emit_by_name(GObject *object, const gchar *name, ... );
    // g_signal_emit_by_name(G_OBJECT(btn), "clicked", NULL);
    //g_signal_emit_by_name(G_OBJECT(widget), "clicked", NULL);
    g_signal_emit_by_name(G_OBJECT(widget), "activate", NULL);
    return TRUE;
}

int main(int argc, char *argv[]) 
{
    sem_full = sem_open("/proudwing_ctrl_full", 0);
    sem_empty = sem_open("/proudwing_ctrl_empty", 0);

    //g_thread_init(NULL);
    gdk_threads_init();

    GtkWidget *window, *button;

    gtk_init(&argc, &argv);
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_default_size(GTK_WINDOW(window), 100, 50);
    g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quit), NULL);
    button = gtk_button_new_with_label("OK");
    gtk_container_set_border_width(GTK_CONTAINER(window), 10);
    gtk_container_add(GTK_CONTAINER(window), button);
    gtk_widget_show_all(window);

    g_signal_connect(G_OBJECT(button), "key_press_event", G_CALLBACK(key_press_cb), button);

    gtk_main();
    
    return 0;
}
