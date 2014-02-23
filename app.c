/*
	@author: Joshua Sager
	@version: in development
	@description: playground application for me to learn how to write software using gtk
*/
#include <gtk/gtk.h>
// TODO: Create a label
// TOOD: Update the label when button is pressed
// TODO: Insert an image
GtkWidget *button; 
GtkWidget *window;

void drawWindow(){
	gtk_container_add (GTK_CONTAINER (window), button);
	gtk_widget_show (button);
	gtk_widget_show (window);

	gtk_main();
}
static void hello(GtkWidget *widget, gpointer data){

	g_print("Hello World verion 2\n");
	button = gtk_button_new_with_label ("Changed Text");
	// drawWindow();
}

static gboolean delete_event( GtkWidget *widget, 
							  GdkEvent *event,
							  gpointer data)
{
	g_print("delete event occurred\n");

	return FALSE;
}

static void destroy(GtkWidget *widget, 
					gpointer data)
{
	gtk_main_quit();
}

int main( int argc, char *argv[]){
	
//  GtkWidget *window;
//	GtkWidget *button;

	gtk_init (&argc, &argv);

	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);

	g_signal_connect(window, "delete_event", 
					 G_CALLBACK (delete_event), NULL);

	g_signal_connect (window, "destroy",
					  G_CALLBACK (destroy), NULL);
	gtk_container_set_border_width (GTK_CONTAINER (window), 10);
	
	button = gtk_button_new_with_label ("hello world");

	g_signal_connect(button, "clicked",
					 G_CALLBACK (hello), NULL);

/*	g_signal_connect_swapped (button, "clicked",
							  G_CALLBACK (gtk_widget_destroy),
							  window);*/
	
	drawWindow();

	return 0;
}
