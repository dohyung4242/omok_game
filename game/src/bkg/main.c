#include <gtk/gtk.h>

#define WINDOW_WIDTH     500
#define WINDOW_HEIGHT    500

#define BTN_WIDTH       200
#define BTN_HEIGHT      50

static void button_test()
{
    printf("I'm testing button\n");
}

static void button_create (GtkWidget* hbox, const char* label, GCallback func, gint x, gint y)
{
    GtkWidget* btn_test = gtk_button_new_with_label (label); //BUTTON'S CREATED
    gtk_widget_set_size_request(btn_test, BTN_WIDTH, BTN_HEIGHT); //SIZE CONTROL
    gtk_fixed_put( GTK_FIXED(hbox), btn_test , x, y);
    g_signal_connect( G_OBJECT (btn_test), "clicked", func, NULL);
}


int main(int argc, char* argv[])
{
    GtkWidget* window;
    GtkWidget* frame;
    GtkWidget* btn;
    
    /*INITIALIZE */
    gtk_init(&argc, &argv);

    /* DIALOG'S ADDED */
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
    gtk_window_set_default_size( GTK_WINDOW (window), WINDOW_WIDTH, WINDOW_HEIGHT);
    gtk_window_set_title( GTK_WINDOW (window), "omok");

    g_signal_connect( G_OBJECT (window), "destroy",
            G_CALLBACK(gtk_main_quit), NULL);

    /* BUTTON'S ADDED */
    frame = gtk_fixed_new();
    gtk_container_add(GTK_CONTAINER(window), frame);
    button_create( frame , "Create Room", button_test, 150, 200); 
    

    gtk_widget_show_all (window);
        
    gtk_main();
    
    return 0;
}
