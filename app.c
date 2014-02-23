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

/*
	Loads in the icon
*/
GdkPixbuf *create_pixbuf(const gchar * filename)
{
	GdkPixbuf *pixbuf;
	GError *error = NULL;
	pixbuf = gdk_pixbuf_new_from_file(filename, &error);
	if(!pixbuf){
		fprintf(stderr, "%s\n", error->message);
		g_error_free(error);
	}
	return pixbuf;
}

/*
	Creates the window
*/
void drawWindow()
{
	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(window), "icon");
	gtk_window_set_default_size(GTK_WINDOW(window), 400,200);
	gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
	gtk_window_set_icon(GTK_WINDOW(window), create_pixbuf("icon.png"));

	gtk_container_set_border_width (GTK_CONTAINER (window), 10);
	button = gtk_button_new_with_label ("hello world");
	gtk_container_add (GTK_CONTAINER (window), button);

	gtk_widget_show (button);
	gtk_widget_show (window);

	gtk_main();
}
/*static void hello(GtkWidget *widget, gpointer data){

	g_print("Hello World verion 2\n");
}

static gboolean delete_event( GtkWidget *widget, GdkEvent *event, gpointer data)
{
	g_print("delete event occurred\n");
	return TRUE;
}

static void destroy(GtkWidget *widget, gpointer data)
{
	gtk_main_quit();
}
*/
int main( int argc, char *argv[]){

	gtk_init (&argc, &argv);
//	g_signal_connect_swapped(G_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quit), NULL);
	
// 	g_signal_connect(window, "delete_event", G_CALLBACK (delete_event), NULL);
//	g_signal_connect (window, "destroy", G_CALLBACK (destroy), NULL);
//	g_signal_connect(button, "clicked", G_CALLBACK (hello), NULL);
//	g_signal_connect_swapped (button, "clicked", G_CALLBACK (gtk_widget_destroy), window);
	
	drawWindow();

	return 0;
}
