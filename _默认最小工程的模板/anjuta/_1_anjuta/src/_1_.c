/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * _1_.c
 * Copyright (C) 2023 nisy <nisy@nisy>
 * 
 * _1_ is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * _1_ is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License along
 * with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include "_1_.h"

#include <glib/gi18n.h>



/* For testing propose use the local (not installed) ui file */
/* #define UI_FILE PACKAGE_DATA_DIR"/ui/_1_.ui" */
#define UI_FILE "src/_1_.ui"
#define TOP_WINDOW "window"


G_DEFINE_TYPE (_1_, _1_, GTK_TYPE_APPLICATION);

/* ANJUTA: Macro _1__APPLICATION gets _1_ - DO NOT REMOVE */
struct __1_Private
{
	/* ANJUTA: Widgets declaration for _1_.ui - DO NOT REMOVE */
};

/* Create a new window loading a file */
static void
_1__new_window (GApplication *app,
                           GFile        *file)
{
	GtkWidget *window;

	GtkBuilder *builder;
	GError* error = NULL;

	_1_Private *priv = _1__APPLICATION(app)->priv;

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

	
	/* ANJUTA: Widgets initialization for _1_.ui - DO NOT REMOVE */

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
_1__activate (GApplication *application)
{
	_1__new_window (application, NULL);
}

static void
_1__open (GApplication  *application,
                     GFile        **files,
                     gint           n_files,
                     const gchar   *hint)
{
	gint i;

	for (i = 0; i < n_files; i++)
		_1__new_window (application, files[i]);
}

static void
_1__init (_1_ *object)
{
	object->priv = G_TYPE_INSTANCE_GET_PRIVATE (object, _1__TYPE_APPLICATION, _1_Private);
}

static void
_1__finalize (GObject *object)
{
	G_OBJECT_CLASS (_1__parent_class)->finalize (object);
}

static void
_1__class_init (_1_Class *klass)
{
	G_APPLICATION_CLASS (klass)->activate = _1__activate;
	G_APPLICATION_CLASS (klass)->open = _1__open;

	g_type_class_add_private (klass, sizeof (_1_Private));

	G_OBJECT_CLASS (klass)->finalize = _1__finalize;
}

_1_ *
_1__new (void)
{
	return g_object_new (_1__get_type (),
	                     "application-id", "org.gnome._1_",
	                     "flags", G_APPLICATION_HANDLES_OPEN,
	                     NULL);
}

