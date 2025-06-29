/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * nisy.h
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

#ifndef _NISY_
#define _NISY_

#include <gtk/gtk.h>

G_BEGIN_DECLS

#define NISY_TYPE_APPLICATION             (nisy_get_type ())
#define NISY_APPLICATION(obj)             (G_TYPE_CHECK_INSTANCE_CAST ((obj), NISY_TYPE_APPLICATION, Nisy))
#define NISY_APPLICATION_CLASS(klass)     (G_TYPE_CHECK_CLASS_CAST ((klass), NISY_TYPE_APPLICATION, NisyClass))
#define NISY_IS_APPLICATION(obj)          (G_TYPE_CHECK_INSTANCE_TYPE ((obj), NISY_TYPE_APPLICATION))
#define NISY_IS_APPLICATION_CLASS(klass)  (G_TYPE_CHECK_CLASS_TYPE ((klass), NISY_TYPE_APPLICATION))
#define NISY_APPLICATION_GET_CLASS(obj)   (G_TYPE_INSTANCE_GET_CLASS ((obj), NISY_TYPE_APPLICATION, NisyClass))

typedef struct _NisyClass NisyClass;
typedef struct _Nisy Nisy;
typedef struct _NisyPrivate NisyPrivate;

struct _NisyClass
{
	GtkApplicationClass parent_class;
};

struct _Nisy
{
	GtkApplication parent_instance;

	NisyPrivate *priv;

};

GType nisy_get_type (void) G_GNUC_CONST;
Nisy *nisy_new (void);

/* Callbacks */

G_END_DECLS

#endif /* _APPLICATION_H_ */

