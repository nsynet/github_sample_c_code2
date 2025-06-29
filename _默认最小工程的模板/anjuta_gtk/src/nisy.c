/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * nisy.c
 * Copyright (C) 2021 nisy <nisy@nisy-matebook>
 * 
 * nisy is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * nisy is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License along
 * with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include "nisy.h"

#include <glib/gi18n.h>



/* For testing propose use the local (not installed) ui file */
/* #define UI_FILE PACKAGE_DATA_DIR"/ui/nisy.ui" */
#define UI_FILE "src/nisy.ui"
#define TOP_WINDOW "window"


G_DEFINE_TYPE (Nisy, nisy, GTK_TYPE_APPLICATION);

/* ANJUTA: Macro NISY_APPLICATION gets Nisy - DO NOT REMOVE */
struct _NisyPrivate
{
	/* ANJUTA: Widgets declaration for nisy.ui - DO NOT REMOVE */
};

/* Create a new window loading a file */
static void
nisy_new_window (GApplication *app,
                           GFile        *file)
{
	GtkWidget *window;

	GtkBuilder *builder;
	GError* error = NULL;

	NisyPrivate *priv = NISY_APPLICATION(app)->priv;

	/* Load UI from file */
	builder = gtk_builder_new ();
	if (!gtk_builder_add_from_file (builder, UI_FILE, &error))
	{
		g_critical ("Couldn't load builder file: %s", error->message);
		g_error_free (error);
	}

	/* Auto-connect signal handlers */
	gtk_builder_connect_signals (builder, app);

	/* Get the window object from the ui file */
	window = GTK_WIDGET (gtk_builder_get_object (builder, TOP_WINDOW));
        if (!window)
        {
		g_critical ("Widget \"%s\" is missing in file %s.",
				TOP_WINDOW,
				UI_FILE);
        }

	
	/* ANJUTA: Widgets initialization for nisy.ui - DO NOT REMOVE */

	g_object_unref (builder);
	
	
	gtk_window_set_application (GTK_WINDOW (window), GTK_APPLICATION (app));
	if (file != NULL)
	{
		/* TODO: Add code here to open the file in the new window */
	}

	gtk_widget_show_all (GTK_WIDGET (window));
}


/* GApplication implementation */
static void
nisy_activate (GApplication *application)
{
	nisy_new_window (application, NULL);
}

static void
nisy_open (GApplication  *application,
                     GFile        **files,
                     gint           n_files,
                     const gchar   *hint)
{
	gint i;

	for (i = 0; i < n_files; i++)
		nisy_new_window (application, files[i]);
}

static void
nisy_init (Nisy *object)
{
	object->priv = G_TYPE_INSTANCE_GET_PRIVATE (object, NISY_TYPE_APPLICATION, NisyPrivate);
}

static void
nisy_finalize (GObject *object)
{
	G_OBJECT_CLASS (nisy_parent_class)->finalize (object);
}

static void
nisy_class_init (NisyClass *klass)
{
	G_APPLICATION_CLASS (klass)->activate = nisy_activate;
	G_APPLICATION_CLASS (klass)->open = nisy_open;

	g_type_class_add_private (klass, sizeof (NisyPrivate));

	G_OBJECT_CLASS (klass)->finalize = nisy_finalize;
}

Nisy *
nisy_new (void)
{
	return g_object_new (nisy_get_type (),
	                     "application-id", "org.gnome.nisy",
	                     "flags", G_APPLICATION_HANDLES_OPEN,
	                     NULL);
}

