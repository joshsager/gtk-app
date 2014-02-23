/*
	@author: Joshua Sager
	@version: in development
	@description: playground application for me to learn how to write software using gtk
*/
#include <gtk/gtk.h>
// TODO: Insert an image

gint count = 0;
char buf[5];

void increase(GtkWidget *widget, gpointer label)
{
	count++;

	sprintf(buf, "%d", count);
	gtk_label_set_text(GTK_LABEL(label), buf);
}

void decrease(GtkWidget *widget, gpointer label)
{
	count--;

	sprintf(buf, "%d", count);
	gtk_label_set_text(GTK_LABEL(label), buf);

}
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

	GtkWidget *window;
	GtkWidget *label;
	GtkWidget *frame;
	GtkWidget *plus;
	GtkWidget *minus;

	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(window), "Plus or Minus");
	gtk_window_set_default_size(GTK_WINDOW(window), 400,200);
	gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
	gtk_window_set_icon(GTK_WINDOW(window), create_pixbuf("icon.png"));

	frame = gtk_fixed_new();
	gtk_container_add(GTK_CONTAINER(window), frame);

	plus = gtk_button_new_with_label("+");
	gtk_widget_set_size_request(plus, 80, 35);
	gtk_fixed_put(GTK_FIXED(frame), plus, 50, 20);

	minus = gtk_button_new_with_label("-");
	gtk_widget_set_size_request(minus, 80, 35);
	gtk_fixed_put(GTK_FIXED(frame), minus, 50, 80);

	label = gtk_label_new("0");
	gtk_fixed_put(GTK_FIXED(frame), label, 190, 58);

	// gtk_container_set_border_width (GTK_CONTAINER (window), 10);
	// button = gtk_button_new_with_label ("hello world");
	// gtk_container_add (GTK_CONTAINER (window), button);

	// gtk_widget_show (button);
	gtk_widget_show_all(window);
	g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);
	g_signal_connect(plus, "clicked", G_CALLBACK(increase), label);
	g_signal_connect(minus, "clicked", G_CALLBACK(decrease), label);
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
