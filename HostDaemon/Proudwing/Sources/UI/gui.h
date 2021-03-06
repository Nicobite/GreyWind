#ifndef GUI_H_
# define GUI_H_
 
#include <gtk/gtk.h>
#include <ardrone_tool/UI/ardrone_input.h>
#include <VP_Api/vp_api_thread_helper.h>
PROTO_THREAD_ROUTINE(gui, data);

typedef struct gui
{
  GtkWidget *window;
  GtkWidget *box;
  GtkWidget *cam;
} gui_t;
 
gui_t *get_gui();
 
void init_gui(int argc, char **argv);
 
#endif
