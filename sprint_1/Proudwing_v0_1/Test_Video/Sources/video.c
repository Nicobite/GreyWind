#include <errno.h>
#include <fcntl.h>
#include <string.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <semaphore.h>
#include <gtk/gtk.h>
#include <gdk-pixbuf/gdk-pixbuf.h>
#include <pthread.h>
#include <gtk/gtkcontainer.h>
#include <glib.h>
#include <pthread.h>

#define VIDEO_WIDTH 320
#define VIDEO_HEIGHT 240

typedef struct gui
{
  GtkWidget *window;
  GtkWidget *box;
  GtkWidget *cam;
} gui_t;

gui_t *gui = NULL;

int fd_fifo;

void* update_thread(void *args){
    sem_t *sem_full = sem_open("/proudwing_vid_full", 0);
    sem_t *sem_empty = sem_open("/proudwing_vid_empty", 0);
    sem_t *sem_complete = sem_open("/proudwing_vid_complete", 0);

    sem_post(sem_empty);

    gui_t *gui = args;

    while(1)
    {
        gdk_threads_enter();

        if(gui->cam!=NULL){
            GdkPixbuf *pixbuf = NULL;
            GError *error = NULL;

            if(sem_trywait(sem_complete)==0){
#if DEBUG
                printf("Loading...\n");
#endif
                gtk_image_set_from_file(GTK_IMAGE(gui->cam), "/tmp/proudwing_vid_frame");

                sem_post(sem_empty);
            }
        }

        gdk_threads_leave();
    }

    return NULL;
}

static void on_destroy(GtkWidget *widget, gpointer data)
{
  gtk_main_quit();
}


void controlCHandler (int signal)
{
    printf("Ctrl-C pressed. Killing the application ...\n");
    exit(-1);
}

int main(int argc, char *argv[]) 
{
    gui = malloc(sizeof (gui_t));

    signal (SIGABRT, &controlCHandler);
    signal (SIGTERM, &controlCHandler);
    signal (SIGINT, &controlCHandler);

    pthread_t update_tid;

    gdk_threads_init();
    printf("Initializing...\n");
    gtk_init(&argc, &argv);
    printf("Init completed.\n");

    gui->window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    g_signal_connect(G_OBJECT(gui->window),
             "destroy",
             G_CALLBACK(on_destroy),
             NULL);

    gui->box = gtk_vbox_new(FALSE, 10);
    gtk_container_add(GTK_CONTAINER(gui->window), gui->box);

    gui->cam = gtk_image_new();
    gtk_box_pack_start(GTK_BOX(gui->box), gui->cam, FALSE, TRUE, 0);

    gtk_widget_show_all(gui->window);

    pthread_create(&update_tid, NULL, update_thread, gui);

    gdk_threads_enter();
    gtk_main();
    gdk_threads_leave();


    return 0;
}
