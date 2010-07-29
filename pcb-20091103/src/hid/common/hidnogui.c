/* $Id$ */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>

#include "global.h"
#include "hid.h"

#ifdef HAVE_LIBDMALLOC
#include <dmalloc.h>
#endif

RCSID ("$Id$");

/* This is the "gui" that is installed at startup, and is used when
   there is no other real GUI to use.  For the most part, it just
   stops the application from (1) crashing randomly, and (2) doing
   gui-specific things when it shouldn't.  */

#define CRASH fprintf(stderr, "HID error: pcb called GUI function %s without having a GUI available.\n", __FUNCTION__); abort()

typedef struct hid_gc_struct
{
  int nothing_interesting_here;
} hid_gc_struct;

static HID_Attribute *
nogui_get_export_options (int *n_ret)
{
  CRASH;
  return 0;
}

static void
nogui_do_export (HID_Attr_Val * options)
{
  CRASH;
}

static void
nogui_parse_arguments (int *argc, char ***argv)
{
  CRASH;
}

static void
nogui_invalidate_wh (int x, int y, int width, int height, int last)
{
  CRASH;
}

static void
nogui_invalidate_lr (int l, int r, int t, int b, int last)
{
  CRASH;
}

static void
nogui_invalidate_all (void)
{
  CRASH;
}

static int
nogui_set_layer (const char *name, int idx, int empty)
{
  CRASH;
  return 0;
}

static hidGC
nogui_make_gc (void)
{
  return 0;
}

static void
nogui_destroy_gc (hidGC gc)
{
}

static void
nogui_use_mask (int use_it)
{
  CRASH;
}

static void
nogui_set_color (hidGC gc, const char *name)
{
  CRASH;
}

static void
nogui_set_line_cap (hidGC gc, EndCapStyle style)
{
  CRASH;
}

static void
nogui_set_line_width (hidGC gc, int width)
{
  CRASH;
}

static void
nogui_set_draw_xor (hidGC gc, int xor)
{
  CRASH;
}

static void
nogui_set_draw_faded (hidGC gc, int faded)
{
  CRASH;
}

static void
nogui_set_line_cap_angle (hidGC gc, int x1, int y1, int x2, int y2)
{
  CRASH;
}

static void
nogui_draw_line (hidGC gc, int x1, int y1, int x2, int y2)
{
  CRASH;
}

static void
nogui_draw_arc (hidGC gc, int cx, int cy, int width, int height,
		int start_angle, int end_angle)
{
  CRASH;
}

static void
nogui_draw_rect (hidGC gc, int x1, int y1, int x2, int y2)
{
  CRASH;
}

static void
nogui_fill_circle (hidGC gc, int cx, int cy, int radius)
{
  CRASH;
}

static void
nogui_fill_polygon (hidGC gc, int n_coords, int *x, int *y)
{
  CRASH;
}

static void
nogui_fill_pcb_polygon (hidGC gc, PolygonType *poly, const BoxType *clip_box)
{
  CRASH;
}

static void
nogui_fill_rect (hidGC gc, int x1, int y1, int x2, int y2)
{
  CRASH;
}

static void
nogui_calibrate (double xval, double yval)
{
  CRASH;
}

static int
nogui_shift_is_pressed (void)
{
  /* This is called from FitCrosshairIntoGrid() when the board is loaded.  */
  return 0;
}

static int
nogui_control_is_pressed (void)
{
  CRASH;
  return 0;
}

static int
nogui_mod1_is_pressed (void)
{
  CRASH;
  return 0;
}

static void
nogui_get_coords (const char *msg, int *x, int *y)
{
  CRASH;
}

static void
nogui_set_crosshair (int x, int y, int action)
{
}

static hidval
nogui_add_timer (void (*func) (hidval user_data),
		 unsigned long milliseconds, hidval user_data)
{
  hidval rv;
  CRASH;
  rv.lval = 0;
  return rv;
}

static void
nogui_stop_timer (hidval timer)
{
  CRASH;
}

static hidval
nogui_watch_file (int fd, unsigned int condition, void (*func) (hidval watch, int fd, unsigned int condition, hidval user_data),
  hidval user_data)
{
  hidval rv;
  CRASH;
  rv.lval = 0;
  return rv;
}

static void
nogui_unwatch_file (hidval watch)
{
  CRASH;
}

static hidval
nogui_add_block_hook (void (*func) (hidval data), hidval data)
{
  hidval rv;
  CRASH;
  rv.ptr = NULL;
  return rv;
}

static void
nogui_stop_block_hook (hidval block_hook)
{
  CRASH;
}

static void
nogui_log (const char *fmt, ...)
{
  va_list ap;
  va_start (ap, fmt);
  vprintf (fmt, ap);
  va_end (ap);
}

static void
nogui_logv (const char *fmt, va_list ap)
{
  vprintf (fmt, ap);
}

static int
nogui_confirm_dialog (char *msg, ...)
{
  int rv;
  printf ("%s ? 0=cancel 1=ok : ", msg);
  fflush (stdout);
  scanf ("%d", &rv);
  return rv;
}

static int
nogui_close_confirm_dialog ()
{
  return nogui_confirm_dialog (_("OK to lose data ?"), NULL);
}

static void
nogui_report_dialog (char *title, char *msg)
{
  printf ("--- %s ---\n%s\n", title, msg);
}

static char *
nogui_prompt_for (char *msg, char *default_string)
{
  static char buf[1024];
  if (default_string)
    printf ("%s [%s] : ", msg, default_string);
  else
    printf ("%s : ", msg);
  fgets (buf, 1024, stdin);
  if (buf[0] == 0 && default_string)
    strcpy (buf, default_string);
  return buf;
}

/* FIXME - this could use some enhancement to actually use the other
   args */
static char *
nogui_fileselect (const char *title, const char *descr,
		  char *default_file, char *default_ext,
		  const char *history_tag, int flags)
{
  static char buf[1024];
  if (default_file)
    printf ("%s [%s] : ", title, default_file);
  else
    printf ("%s : ", title);
  fgets (buf, 1024, stdin);
  if (buf[0] == 0 && default_file)
    strcpy (buf, default_file);
  return buf;
}

static int
nogui_attribute_dialog (HID_Attribute * attrs,
			int n_attrs, HID_Attr_Val * results,
			const char * title, const char * descr)
{
  CRASH;
}

static void
nogui_show_item (void *item)
{
  CRASH;
}

static void
nogui_beep (void)
{
  putchar (7);
  fflush (stdout);
}

static int
nogui_progress (int so_far, int total, const char *message)
{
  return 0;
}

HID hid_nogui = {
  sizeof (HID),
  "nogui",
  "Default GUI when no other GUI is present.  Does nothing.",
  0, 0, 0, 0, 0, 0,
  nogui_get_export_options,
  nogui_do_export,
  nogui_parse_arguments,
  nogui_invalidate_wh,
  nogui_invalidate_lr,
  nogui_invalidate_all,
  nogui_set_layer,
  nogui_make_gc,
  nogui_destroy_gc,
  nogui_use_mask,
  nogui_set_color,
  nogui_set_line_cap,
  nogui_set_line_width,
  nogui_set_draw_xor,
  nogui_set_draw_faded,
  nogui_set_line_cap_angle,
  nogui_draw_line,
  nogui_draw_arc,
  nogui_draw_rect,
  nogui_fill_circle,
  nogui_fill_polygon,
  nogui_fill_pcb_polygon,
  0 /* nogui_thindraw_pcb_polygon */ ,
  nogui_fill_rect,
  nogui_calibrate,
  nogui_shift_is_pressed,
  nogui_control_is_pressed,
  nogui_mod1_is_pressed,
  nogui_get_coords,
  nogui_set_crosshair,
  nogui_add_timer,
  nogui_stop_timer,
  nogui_watch_file,
  nogui_unwatch_file,
  nogui_add_block_hook,
  nogui_stop_block_hook,
  nogui_log,
  nogui_logv,
  nogui_confirm_dialog,
  nogui_close_confirm_dialog,
  nogui_report_dialog,
  nogui_prompt_for,
  nogui_fileselect,
  nogui_attribute_dialog,
  nogui_show_item,
  nogui_beep,
  nogui_progress,
  0 /* nogui_drc_gui */
};

#define AD(x) if (!d->x) d->x = s->x

void
apply_default_hid (HID * d, HID * s)
{
  if (s == 0)
    s = &hid_nogui;
  AD (get_export_options);
  AD (do_export);
  AD (parse_arguments);
  AD (invalidate_wh);
  AD (invalidate_lr);
  AD (invalidate_all);
  AD (set_layer);
  AD (make_gc);
  AD (destroy_gc);
  AD (use_mask);
  AD (set_color);
  AD (set_line_cap);
  AD (set_line_width);
  AD (set_draw_xor);
  AD (set_line_cap_angle);
  AD (draw_line);
  AD (draw_arc);
  AD (fill_circle);
  AD (fill_polygon);
  AD (fill_pcb_polygon);
  AD (thindraw_pcb_polygon);
  AD (calibrate);
  AD (shift_is_pressed);
  AD (control_is_pressed);
  AD (mod1_is_pressed);
  AD (get_coords);
  AD (set_crosshair);
  AD (add_timer);
  AD (stop_timer);
  AD (watch_file);
  AD (unwatch_file);
  AD (add_block_hook);
  AD (stop_block_hook);
  AD (log);
  AD (logv);
  AD (confirm_dialog);
  AD (close_confirm_dialog);
  AD (report_dialog);
  AD (prompt_for);
  AD (fileselect);
  AD (attribute_dialog);
  AD (show_item);
  AD (beep);
  AD (progress);
  AD (drc_gui);
}
