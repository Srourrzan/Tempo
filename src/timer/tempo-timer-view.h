#ifndef TEMPO_TIMER_VIEW_H
# define TEMPO_TIMER_VIEW_H

# include <adwaita.h>
#include <gtk/gtk.h>
#include "tempo-constants.h"

GtkWidget *tempo_create_icon_button (const char *, const char *);
GtkWidget *tempo_create_controls_box (GtkOrientation, gint, GtkAlign);
GtkWidget *tempo_create_timer_display (GtkWidget **, GtkOrientation, gint);

#endif
