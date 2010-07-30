//
//  CocoaHID.m
//  PCB
//
//  Created by Daniel Parnell on 29/07/10.
//  Copyright (c) 2010 __MyCompanyName__. All rights reserved.
//

#import "CocoaHID.h"

#import "hid/common/draw_helpers.h"
#import "hidint.h"
#import "data.h"

static NSView* currentView = nil;
static NSGraphicsContext *nsctx = nil;
static CGContextRef context = nil;

typedef struct hid_gc_struct
{
    HID *me_pointer;
    int color;
    const char *colorname;
    int width;
    EndCapStyle cap;
    char xor;
    char erase;
} hid_gc_struct;

extern HID cocoa_gui;

void register_toporouter_action_list() {
    // do nothing
}

void bindtextdomain (char* package, char* locale_dir) {
    // do nothing
}

void bind_textdomain_codeset(char* package, char* encoding) {
    // do nothing
}

static HID_Attribute *
cocoa_get_export_options (int *n)
{
    return 0;
}

static void
cocoa_do_export (HID_Attr_Val * options)
{
	NSApplicationMain(0, nil);
}

static void
cocoa_parse_arguments (int *argc, char ***argv)
{
	HID_AttrNode *ha;
	int i;
	
	for (ha = hid_attr_nodes; ha; ha = ha->next) {
		for (i = 0; i < ha->n; i++) {
			HID_Attribute *a = ha->attributes + i;
			switch (a->type)
			{
				case HID_Integer:
					*(int*)a->value = a->default_val.int_value;
					break;
				case HID_Real:
					*(float*)a->value = a->default_val.real_value;
					break;
				case HID_String:
					*(char**)a->value = a->default_val.str_value;
					break;
				case HID_Path:
					*(char**)a->value = a->default_val.str_value;
					break;
				case HID_Boolean:
					*(int*)a->value = a->default_val.int_value;
					break;
				default:
					break;
			}
		}
	}
	
	Settings.verbose = 0;
}

void stoppingHere() {
//	NSLog(@"STOPPING");
}

static void
cocoa_invalidate_wh (int x, int y, int width, int height, int last)
{
//	NSLog(@"cocoa_invalidate_wh %d %d %d %d %d", x, y, width, height, last);
}

static void
cocoa_invalidate_lr (int l, int r, int t, int b, int last)
{
    cocoa_invalidate_wh (l, t, r - l + 1, b - t + 1, last);
}

void
cocoa_invalidate_all (void)
{
    cocoa_invalidate_wh (0, 0, PCB->MaxWidth, PCB->MaxHeight, 1);
}

static int
cocoa_set_layer (const char *name, int group, int empty)
{
//	NSLog(@"cocoa_set_layer %s, %d %d", name, group, empty);
	
    return 0;
}

static hidGC
cocoa_make_gc (void)
{
    hidGC rv = malloc (sizeof (hid_gc_struct));
    memset (rv, 0, sizeof (hid_gc_struct));
    rv->me_pointer = &cocoa_gui;
    return rv;
}

static void
cocoa_destroy_gc (hidGC gc)
{
    free (gc);
}

static void
cocoa_use_mask (int use_it)
{
}

NSMutableDictionary* color_cache = nil;

static void
cocoa_set_color (hidGC gc, const char *name)
{
//	NSLog(@"cocoa_set_color: %p %s", gc, name);
	if (strcmp (name, "erase") == 0)
    {
		[[NSColor whiteColor] set];
    }
	else if (strcmp (name, "drill") == 0)
    {
		[[NSColor whiteColor] set];
    }
	else {
		if(name[0]=='#') {
			if(color_cache==nil) {
				color_cache = [[NSMutableDictionary dictionary] retain];
			}
			NSString* n = [NSString stringWithCString: name encoding: NSUTF8StringEncoding];
			NSColor* color = [color_cache objectForKey: n];
			if(color==nil) {
				NSRange range;
				range.location = 1;
				range.length = 2;
				NSString *rString = [n substringWithRange:range];
				
				range.location = 3;
				NSString *gString = [n substringWithRange:range];
				
				range.location = 5;
				NSString *bString = [n substringWithRange:range];
				
				// Scan values
				unsigned int r, g, b;
				[[NSScanner scannerWithString:rString] scanHexInt:&r];
				[[NSScanner scannerWithString:gString] scanHexInt:&g];
				[[NSScanner scannerWithString:bString] scanHexInt:&b];
				
				color = [NSColor colorWithDeviceRed:((float) r / 255.0f)
											  green:((float) g / 255.0f)
											   blue:((float) b / 255.0f)
											  alpha:1.0f];
				
				[color_cache setObject: color forKey: n];
			}
			[color set];
		} else {
			[[NSColor blackColor] set];
		}
	}
}

static void
cocoa_set_line_cap (hidGC gc, EndCapStyle style)
{
//	NSLog(@"cocoa_set_line_cap: %p, %d", gc, style);
	
    gc->cap = style;
}

static void
cocoa_set_line_width (hidGC gc, int width)
{
//	NSLog(@"cocoa_set_line_width: %p %d", gc, width);
	CGContextSetLineWidth(context, width);
    gc->width = width;
}

static void
cocoa_set_draw_xor (hidGC gc, int xor)
{
//	NSLog(@"cocoa_set_draw_xor: %p %d", gc, xor);
    gc->xor = xor;
}

static void
cocoa_set_draw_faded (hidGC gc, int faded)
{
//	NSLog(@"cocoa_set_draw_faded: %p %d", gc, faded);
    /* We don't use this */
}

static void
cocoa_set_line_cap_angle (hidGC gc, int x1, int y1, int x2, int y2)
{
//    CRASH;
}

static void
cocoa_draw_line (hidGC gc, int x1, int y1, int x2, int y2)
{
//	NSLog(@"cocoa_draw_line: %p %d %d %d %d", gc, x1, y1, x2, y2);

	if(currentView) {
		CGContextBeginPath(context);
		CGContextMoveToPoint(context, x1, y1);
		CGContextAddLineToPoint(context, x2, y2);
		CGContextStrokePath(context);	
	}
	
//	[NSBezierPath strokeLineFromPoint: NSMakePoint(x1/1000.0, y1/1000.0) toPoint: NSMakePoint(x2/1000.0, y2/1000.0)];
}

static void
cocoa_draw_arc (hidGC gc, int cx, int cy, int width, int height,
                  int start_angle, int delta_angle)
{
}

static void
cocoa_draw_rect (hidGC gc, int x1, int y1, int x2, int y2)
{
	[NSBezierPath strokeRect: NSMakeRect(x1, y1, x2-x1, y2-y1)];
}

static void
cocoa_fill_circle (hidGC gc, int cx, int cy, int radius)
{
}

static void
cocoa_fill_polygon (hidGC gc, int n_coords, int *x, int *y)
{
}

static void
cocoa_fill_rect (hidGC gc, int x1, int y1, int x2, int y2)
{
	[NSBezierPath fillRect: NSMakeRect(x1, y1, x2-x1, y2-y1)];
}

static void
cocoa_calibrate (double xval, double yval)
{
//    CRASH;
}

static int
cocoa_shift_is_pressed (void)
{
    return 0;
}

static int
cocoa_control_is_pressed (void)
{
    return 0;
}

static int
cocoa_mod1_is_pressed (void)
{
    return 0;
}

void cocoa_get_coords (const char *msg, int *x, int *y) {
    
}

static void
cocoa_set_crosshair (int x, int y, int action)
{
}

static hidval
cocoa_add_timer (void (*func) (hidval user_data),
                   unsigned long milliseconds, hidval user_data)
{
    
}

static void
cocoa_stop_timer (hidval hv)
{
}

hidval
cocoa_watch_file (int fd, unsigned int condition, void (*func) (hidval watch, int fd, unsigned int condition, hidval user_data),
                    hidval user_data)
{
}

void
cocoa_unwatch_file (hidval data)
{
}

static hidval
cocoa_add_block_hook (void (*func) (hidval data), hidval user_data )
{
}

static void
cocoa_stop_block_hook (hidval mlpoll)
{
}

void cocoa_logv (const char *fmt, va_list ap) {
    printf(fmt, ap);    
}

void
cocoa_log (const char *fmt, ...)
{
    va_list ap;
    va_start (ap, fmt);
    cocoa_logv (fmt, ap);
    va_end (ap);
}

int
cocoa_confirm_dialog (char *msg, ...)
{
    return 0;
}

int
cocoa_close_confirm_dialog ()
{
    return cocoa_confirm_dialog ("OK to lose data ?", NULL);
}

void
cocoa_report_dialog (char *title, char *msg)
{
}

char *
cocoa_prompt_for (char *msg, char *default_string)
{
    return default_string;
}

char *
cocoa_fileselect (const char *title, const char *descr,
                    char *default_file, char *default_ext,
                    const char *history_tag, int flags)
{
    
    return cocoa_prompt_for ((char *)title, default_file);
}

int
cocoa_attribute_dialog (HID_Attribute * attrs,
                          int n_attrs, HID_Attr_Val * results,
                          const char * title, const char * descr)
{
}

static void
cocoa_show_item (void *item)
{
}

static void
cocoa_beep (void)
{
}

static int
cocoa_progress (int so_far, int total, const char *message)
{
    return 0;
}

HID cocoa_gui = {
    sizeof (HID),
    "cocoa",
    "cocoa - The MacOS X GUI of choice",
    1,				/* gui */
    0,				/* printer */
    0,				/* exporter */
    1,				/* poly before */
    0,				/* poly after */
    0,				/* poly dicer */
    
    cocoa_get_export_options,
    cocoa_do_export,
    cocoa_parse_arguments,
    
    cocoa_invalidate_wh,
    cocoa_invalidate_lr,
    cocoa_invalidate_all,
    cocoa_set_layer,
    cocoa_make_gc,
    cocoa_destroy_gc,
    cocoa_use_mask,
    cocoa_set_color,
    cocoa_set_line_cap,
    cocoa_set_line_width,
    cocoa_set_draw_xor,
    cocoa_set_draw_faded,
    cocoa_set_line_cap_angle,
    cocoa_draw_line,
    cocoa_draw_arc,
    cocoa_draw_rect,
    cocoa_fill_circle,
    cocoa_fill_polygon,
    common_fill_pcb_polygon,
    common_thindraw_pcb_polygon,
    cocoa_fill_rect,
    
    cocoa_calibrate,
    cocoa_shift_is_pressed,
    cocoa_control_is_pressed,
    cocoa_mod1_is_pressed,
    cocoa_get_coords,
    cocoa_set_crosshair,
    cocoa_add_timer,
    cocoa_stop_timer,
    cocoa_watch_file,
    cocoa_unwatch_file,
    cocoa_add_block_hook,
    cocoa_stop_block_hook,
    
    cocoa_log,
    cocoa_logv,
    cocoa_confirm_dialog,
    cocoa_close_confirm_dialog,
    cocoa_report_dialog,
    cocoa_prompt_for,
    cocoa_fileselect,
    cocoa_attribute_dialog,
    cocoa_show_item,
    cocoa_beep,
    cocoa_progress,
    0 /* cocoa_drc_gui */
};

#include "dolists.h"

void
hid_cocoa_init ()
{	
    hid_register_hid (&cocoa_gui);

// REGISTER_ACTIONS (cocoa_dialog_action_list)
 REGISTER_ACTIONS (cocoa_library_action_list)
// REGISTER_FLAGS (cocoa_main_flag_list)
// REGISTER_ATTRIBUTES (cocoa_attribute_list)
// REGISTER_ACTIONS (cocoa_main_action_list)
 REGISTER_ACTIONS (cocoa_menu_action_list)
 REGISTER_ATTRIBUTES(pcbmenu_attr)
// REGISTER_ACTIONS (cocoa_netlist_action_list)
 REGISTER_ACTIONS (cocoa_styles_action_list)
}


@implementation CocoaHID

+(HID*) HID {
	return &cocoa_gui;
}

+(void) drawToView:(NSView*)aView {
	currentView = aView;
	nsctx = [NSGraphicsContext currentContext];
    context = (CGContextRef)[nsctx graphicsPort];	
}

+(void) finishedDrawing {
	CGContextFlush(context);
	currentView = nil;
}

@end
