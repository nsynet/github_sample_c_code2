/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * _1_.h
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

#ifndef __1__
#define __1__

#include <gtk/gtk.h>

G_BEGIN_DECLS

#define _1__TYPE_APPLICATION             (_1__get_type ())
#define _1__APPLICATION(obj)             (G_TYPE_CHECK_INSTANCE_CAST ((obj), _1__TYPE_APPLICATION, _1_))
#define _1__APPLICATION_CLASS(klass)     (G_TYPE_CHECK_CLASS_CAST ((klass), _1__TYPE_APPLICATION, _1_Class))
#define _1__IS_APPLICATION(obj)          (G_TYPE_CHECK_INSTANCE_TYPE ((obj), _1__TYPE_APPLICATION))
#define _1__IS_APPLICATION_CLASS(klass)  (G_TYPE_CHECK_CLASS_TYPE ((klass), _1__TYPE_APPLICATION))
#define _1__APPLICATION_GET_CLASS(obj)   (G_TYPE_INSTANCE_GET_CLASS ((obj), _1__TYPE_APPLICATION, _1_Class))

typedef struct __1_Class _1_Class;
typedef struct __1_ _1_;
typedef struct __1_Private _1_Private;

struct __1_Class
{
	GtkApplicationClass parent_class;
};

struct __1_
{
	GtkApplication parent_instance;

	_1_Private *priv;

};

GType _1__get_type (void) G_GNUC_CONST;
_1_ *_1__new (void);

/* Callbacks */

G_END_DECLS

#endif /* _APPLICATION_H_ */

