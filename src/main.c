#include "tempo-constants.h"
# include "timer/tempo-timer-view.h"
#include <gtk/gtk.h>
#include "gtk/gtkshortcut.h"
#include <adwaita.h>
#include <sqlite3.h>

static void
active_cb (GtkApplication *app, gpointer user_data)
{
  GtkWidget *box;
  GtkWidget *window;
  GtkWidget *header_bar;
  GtkWidget *view_title;
  GtkWidget *status_page;
  GtkWidget *timer_label;
  GtkWidget *timer_display;

  (void) user_data;
  window = adw_application_window_new (app);
  gtk_window_set_title (GTK_WINDOW (window), TEMPO_APP_NAME);
  gtk_window_set_default_size (GTK_WINDOW (window), TEMPO_WINDOW_WIDTH, TEMPO_WINDOW_HEIGHT);

  // Lovely header
  header_bar = adw_header_bar_new ();
  view_title = adw_window_title_new (TEMPO_APP_NAME, TEMPO_APP_SUBTITLE);
  adw_header_bar_set_title_widget (ADW_HEADER_BAR (header_bar), view_title);

  // Main page
  status_page = adw_status_page_new ();
  adw_status_page_set_icon_name (ADW_STATUS_PAGE (status_page),
                                 "alarm-symbolic");
  adw_status_page_set_title (ADW_STATUS_PAGE (status_page),
                             "Welcome to Tempo");
  adw_status_page_set_description (
      ADW_STATUS_PAGE (status_page),
      "Track tasks, log active intervals, and preserve your focus.");
  
  // Timer
  timer_display = tempo_create_timer_display (&timer_label,
                                              GTK_ORIENTATION_HORIZONTAL, TEMPO_MAIN_SPACING);
  adw_status_page_set_child (ADW_STATUS_PAGE (status_page), timer_display);

  // Main box
  box = gtk_box_new (GTK_ORIENTATION_VERTICAL, 0);
  gtk_box_append (GTK_BOX (box), header_bar);
  gtk_box_append(GTK_BOX(box), status_page);

  adw_application_window_set_content(ADW_APPLICATION_WINDOW(window), box);
  gtk_window_present (GTK_WINDOW (window));
}

int
main(int argc,
     char *argv[])
{
  g_autoptr (AdwApplication) app = NULL;
  
  app = adw_application_new ("io.github.Srourrzan.Tempo",
                             G_APPLICATION_DEFAULT_FLAGS);
  g_signal_connect (app, "activate", G_CALLBACK (active_cb), NULL);
  return g_application_run (G_APPLICATION (app), argc, argv);
}
