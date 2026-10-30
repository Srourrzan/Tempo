#include "tempo-timer-view.h"
#include "gtk/gtk.h"
#include "gtk/gtkshortcut.h"
#include "tempo-constants.h"

GtkWidget *
tempo_create_icon_button (const char *icon_name, const char *tooltip)
{
  GtkWidget *button;

  button = gtk_button_new_from_icon_name (icon_name);
  gtk_widget_set_halign (button, GTK_ALIGN_CENTER);
  gtk_widget_set_tooltip_text (button, tooltip);
  return (button);
}

GtkWidget *
tempo_create_controls_box (GtkOrientation orientation, gint spacing,
                           GtkAlign align)
{
  GtkWidget *box;
  GtkWidget *start_button;
  GtkWidget *pause_button;
  GtkWidget *stop_button;

  box = gtk_box_new (orientation, spacing);
  start_button
      = tempo_create_icon_button ("media-playback-start-symbolic", "Start");
  pause_button
      = tempo_create_icon_button ("media-playback-pause-symbolic", "Pause");
  stop_button = tempo_create_icon_button("media-playback-stop-symbolic", "Stop");
  gtk_widget_set_halign (box, align);
  // order affects the UI order
  gtk_box_append (GTK_BOX (box), start_button);
  gtk_box_append (GTK_BOX (box), pause_button);
  gtk_box_append (GTK_BOX (box), stop_button);
  return (box);
}

static GtkWidget *
tempo_create_time_label ()
{
  GtkWidget *label;

  label = gtk_label_new(TEMPO_DEFAULT_TIME);
  /* Libadwaita CSS classes for the clock look*/
  gtk_widget_add_css_class (label, TEMPO_CSS_NUMERIC);
  gtk_widget_add_css_class (label, TEMPO_CSS_TITLE_1);
  gtk_label_set_xalign (GTK_LABEL (label), TEMPO_ALIGN_SPACING);
  gtk_widget_set_size_request (label, TEMPO_LABEL_SIZE, TEMPO_DEFAULT_DIM);
  return (label);
}

GtkWidget *
tempo_create_timer_display (GtkWidget **out_label, GtkOrientation orient, gint spacing)
{
  GtkWidget *box;
  GtkWidget *time_label;
  GtkWidget *time_ctrls;

  (void)out_label;
  time_label = tempo_create_time_label ();
  box = gtk_box_new (orient, spacing);
  time_ctrls = tempo_create_controls_box (GTK_ORIENTATION_HORIZONTAL,
                                          TEMPO_CTRL_SPACING, GTK_ALIGN_START);
  gtk_widget_set_halign (box, TEMPO_HALIGN_CENTER);
  gtk_widget_set_valign (box, TEMPO_VALIGN_CENTER);
  gtk_box_append (GTK_BOX (box), time_label);
  gtk_box_append(GTK_BOX(box), time_ctrls);
  return (box);
}
