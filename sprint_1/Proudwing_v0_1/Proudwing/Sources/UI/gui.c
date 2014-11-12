#include <stdlib.h>
#include "gui.h"
 
DEFINE_THREAD_ROUTINE(gui, data)
{
   gdk_threads_enter();
   gtk_main();
   gdk_threads_leave();
}


gui_t *gui = NULL;
 
gui_t *get_gui()
{
  return gui;
}
 
 
static void on_destroy(GtkWidget *widget, gpointer data)
{
  vp_os_free(gui);
  gtk_main_quit();
}
 
void init_gui(int argc, char **argv)
{
  gui = vp_os_malloc(sizeof (gui_t));
 
  g_thread_init(NULL);
  gdk_threads_init();
  gtk_init(&argc, &argv);
 
  gui->window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  g_signal_connect(G_OBJECT(gui->window),
           "destroy",
           G_CALLBACK(on_destroy),
           NULL);
  gui->box = gtk_vbox_new(FALSE, 10);
  gtk_container_add(GTK_CONTAINER(gui->window),
            gui->box);
  gui->cam = gtk_image_new();
  gtk_box_pack_start(GTK_BOX(gui->box), gui->cam, FALSE, TRUE, 0);
 

  gtk_widget_show_all(gui->window);
}
