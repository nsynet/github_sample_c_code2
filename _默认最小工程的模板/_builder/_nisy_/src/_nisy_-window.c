/* _nisy_-window.c
 *
 * Copyright 2020 nsynet
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "_nisy_-config.h"
#include "_nisy_-window.h"

struct _NisyWindow
{
  GtkApplicationWindow  parent_instance;

  /* Template widgets */
  GtkHeaderBar        *header_bar;
  GtkLabel            *label;
};

G_DEFINE_TYPE (NisyWindow, _nisy__window, GTK_TYPE_APPLICATION_WINDOW)

static void
_nisy__window_class_init (NisyWindowClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/org/example/App/_nisy_-window.ui");
  gtk_widget_class_bind_template_child (widget_class, NisyWindow, header_bar);
  gtk_widget_class_bind_template_child (widget_class, NisyWindow, label);
}

static void
_nisy__window_init (NisyWindow *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
