/* gEDA - GPL Electronic Design Automation
 * gschem - gEDA Schematic Capture
 * Copyright (C) 1998-2004 Ales V. Hvezda
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */


#ifndef __GUI_LIBRARY_WINDOW_H__
#define __GUI_LIBRARY_WINDOW_H__


/*
 * GhidLibraryWindow
 */

#define GHID_TYPE_LIBRARY_WINDOW           (ghid_library_window_get_type())
#define GHID_LIBRARY_WINDOW(obj)           (G_TYPE_CHECK_INSTANCE_CAST ((obj), GHID_TYPE_LIBRARY_WINDOW, GhidLibraryWindow))
#define GHID_LIBRARY_CLASS(klass)          (G_TYPE_CHECK_CLASS_CAST ((klass),  GHID_TYPE_LIBRARY_WINDOW, GhidLibraryWindowClass))
#define GHID_IS_LIBRARY_WINDOW(obj)        (G_TYPE_CHECK_INSTANCE_TYPE ((obj), GHID_TYPE_LIBRARY_WINDOW))
#define GHID_GET_LIBRARY_WINDOW_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj),  GHID_TYPE_LIBRARY, GhidLibraryWindowClass))

typedef struct _GhidLibraryWindowClass GhidLibraryWindowClass;
typedef struct _GhidLibraryWindow GhidLibraryWindow;


struct _GhidLibraryWindowClass
{
  GtkDialogClass parent_class;
};

struct _GhidLibraryWindow
{
  GtkDialog parent_instance;

  GtkWidget *hpaned;
  GtkTreeView *libtreeview;
  GtkNotebook *viewtabs;
  GtkWidget *preview;
  GtkEntry *entry_filter;
  GtkButton *button_clear;
  guint filter_timeout;
};


GType ghid_library_window_get_type (void);

#endif /* __GUI_LIBRARY_WINDOW_H__ */
