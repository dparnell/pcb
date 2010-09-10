//
//  CocoaHID.m
//  PCB
//
//  Created by Daniel Parnell on 29/07/10.
//  Copyright (c) 2010 Automagic Software Pty Ltd. All rights reserved.
//

#import "CocoaHID.h"

#import "hid/common/draw_helpers.h"
#import "hidint.h"
#import "data.h"

#pragma mark -
#pragma mark global variables
#pragma mark -

int lastModifierFlags = 0;
static NSView* currentView = nil;
static NSGraphicsContext *nsctx = nil;
static CGContextRef context = nil;

typedef struct hid_gc_struct
{
    HID *me_pointer;
	int width;
	NSColor* color;
	CGLineCap cap;
	BOOL xor;
} hid_gc_struct;

extern HID cocoa_gui;

static hidGC currentContext = nil;

static void setupGraphicsContext(hidGC gc) {
//	NSLog(@"setupGraphicsContext: gc = %p", gc);
	
	if(currentView==nil) {
		NSLog(@"HERE!");		
	}
	
	if(gc!=currentContext) {
//		NSLog(@"gc = %p", gc);
		currentContext = gc;
		
		[gc->color set];
		CGContextSetLineWidth(context, gc->width);
		CGContextSetLineCap(context, gc->cap);
	}
}

#pragma mark -
#pragma mark Unimplemented functions
#pragma mark -

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
	
	int c = *argc;
	char** args = *argv;
	
	for(i=0; i<c; i++) {
		if (strncmp(args[i], "-psn_", 5)==0) {
			args[i][0] = 0;
		}
	}
}

void stoppingHere() {
//	NSLog(@"STOPPING");
}

#pragma mark -
#pragma mark Drawing functions
#pragma mark -

static void
cocoa_invalidate_wh (int x, int y, int width, int height, int last)
{
//	NSLog(@"cocoa_invalidate_wh %d %d %d %d %d", x, y, width, height, last);
//	[[[CocoaHID instance] mainView] setNeedsDisplay: YES];
	
	[NSTimer scheduledTimerWithTimeInterval: 0.01 target: [CocoaHID instance] selector: @selector(needsRedraw:) userInfo: nil repeats: NO];
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
	int idx = group;
	if (idx >= 0 && idx < max_layer)
    {
		idx = PCB->LayerGroups.Entries[idx][0];
    }

	if (idx >= 0 && idx < max_layer + 2)
		return PCB->Data->Layer[idx].On;
	if (idx < 0)
    {
		switch (SL_TYPE (idx))
		{
			case SL_INVISIBLE:
				return PCB->InvisibleObjectsOn;
			case SL_MASK:
				if (SL_MYSIDE (idx))
					return TEST_FLAG (SHOWMASKFLAG, PCB);
				return 0;
			case SL_SILK:
				if (SL_MYSIDE (idx))
					return PCB->ElementOn;
				return 0;
			case SL_ASSY:
				return 0;
			case SL_UDRILL:
			case SL_PDRILL:
				return 1;
		}
    }
	return 0;
}

static hidGC
cocoa_make_gc (void)
{
    hidGC rv = malloc (sizeof (hid_gc_struct));
    memset (rv, 0, sizeof (hid_gc_struct));
    rv->me_pointer = &cocoa_gui;
	rv->width = 1;
	rv->color = [NSColor blackColor];
	rv->cap = kCGLineCapButt;
    return rv;
}

static void
cocoa_destroy_gc (hidGC gc)
{
	if(currentContext==gc) {
		currentContext = nil;
	}
	
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
		gc->color = [NSColor whiteColor];
    }
	else if (strcmp (name, "drill") == 0)
    {
		gc->color = [NSColor whiteColor];
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
			gc->color = color;
		} else {
			gc->color = [NSColor blackColor];
		}
	}
	
	if(currentContext==gc) {
		[gc->color set];
	}
}

static void
cocoa_set_line_cap (hidGC gc, EndCapStyle style)
{
//	NSLog(@"cocoa_set_line_cap: %p, %d", gc, style);
	CGLineCap cap;
	
	switch (style) {
		case Round_Cap:
		case Trace_Cap:
			cap = kCGLineCapRound;
			break;
		case Square_Cap:
			cap = kCGLineCapSquare;
			break;
		case Beveled_Cap:
			cap = kCGLineCapButt;
			break;
			
		default:
			cap = kCGLineCapButt;
			break;
	}
	
	gc->cap = cap;
	if(gc==currentContext) {
		CGContextSetLineCap(context, cap);
	}
}

static void
cocoa_set_line_width (hidGC gc, int width)
{
//	NSLog(@"cocoa_set_line_width: %p %d", gc, width);
	if (gc->xor) {
		// TODO: change this to always draw 1 pixel wide
		width = 500;
	}
	
	gc->width = width;
	if(currentContext==gc) {		
		CGContextSetLineWidth(context, width);
	}
}

static void
cocoa_set_draw_xor (hidGC gc, int xor)
{
//	NSLog(@"cocoa_set_draw_xor: %p %d", gc, xor);
	gc->xor = xor;
	if(currentContext==gc) {
		
//		CGContextSetLineWidth(context, width);
	}
}

static void
cocoa_set_draw_faded (hidGC gc, int faded)
{
	NSLog(@"cocoa_set_draw_faded: %p %d", gc, faded);
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
	setupGraphicsContext(gc);
	
	CGContextBeginPath(context);
	CGContextMoveToPoint(context, x1, y1);
	CGContextAddLineToPoint(context, x2, y2);
	CGContextStrokePath(context);	
}

#define PI 3.14159265358979323846

static inline double radians(double degrees) { return degrees * PI / 180; }

static void
cocoa_draw_arc (hidGC gc, int cx, int cy, int width, int height,
                  int start_angle, int delta_angle)
{
	
	setupGraphicsContext(gc);
	
	// because the view is "flipped" the angles need to be adjusted so they are correct in the flipped context
	start_angle = 180 - start_angle;
	
	CGContextBeginPath(context);
	CGContextAddArc(context, cx, cy, width, radians(start_angle), radians(start_angle-delta_angle), delta_angle>0);
	CGContextStrokePath(context);		
}

static void
cocoa_draw_rect (hidGC gc, int x1, int y1, int x2, int y2)
{
	setupGraphicsContext(gc);

	CGContextBeginPath(context);
	CGContextAddRect(context, CGRectMake(x1, y1, x2-x1, y2-y1));
	CGContextStrokePath(context);	
}

static void
cocoa_fill_circle (hidGC gc, int cx, int cy, int radius)
{
	setupGraphicsContext(gc);
	
	CGContextFillEllipseInRect(context, NSMakeRect(cx-radius, cy-radius, radius*2, radius*2));
}

static void
cocoa_fill_polygon (hidGC gc, int n_coords, int *x, int *y)
{
	setupGraphicsContext(gc);
	
	if (n_coords>0) {
		CGContextBeginPath(context);
		CGContextMoveToPoint(context, x[0], y[0]);
		for(int i=1; i<n_coords; i++) {
			CGContextAddLineToPoint(context, x[i], y[i]);
		}
		CGContextFillPath(context);
	}
}

static void
cocoa_fill_rect (hidGC gc, int x1, int y1, int x2, int y2)
{
	setupGraphicsContext(gc);
	
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
	return (lastModifierFlags & NSShiftKeyMask) ? 1 : 0;
}

static int
cocoa_control_is_pressed (void)
{
	return (lastModifierFlags & NSControlKeyMask) ? 1 : 0;
}

static int
cocoa_mod1_is_pressed (void)
{
	return (lastModifierFlags & NSCommandKeyMask) ? 1 : 0;
}

void cocoa_get_coords (const char *msg, int *x, int *y) {
    NSLog(@"UNIMPLEMENTED: cocoa_get_coords");
}

static void
cocoa_set_crosshair (int x, int y, int action)
{
//	NSLog(@"UNIMPLEMENTED: cocoa_set_crosshair: %d %d %d", x, y, action);
}

#pragma mark -
#pragma mark utility functions
#pragma mark -

static hidval
cocoa_add_timer (void (*func) (hidval user_data),
                   unsigned long milliseconds, hidval user_data)
{
	[[CocoaHID instance] scheduleTimerFor: func withInterval: milliseconds andUserData: user_data];

	hidval result;
	result.lval = 0;
	result.ptr = nil;
	
	return result;
}

static void
cocoa_stop_timer (hidval hv)
{
	NSLog(@"UNIMPLEMENTED: cocoa_stop_timer: %d %p", hv.lval, hv.ptr);	
}

hidval
cocoa_watch_file (int fd, unsigned int condition, void (*func) (hidval watch, int fd, unsigned int condition, hidval user_data),
                    hidval user_data)
{
	NSLog(@"UNIMPLEMENTED: cocoa_watch_file");
}

void
cocoa_unwatch_file (hidval data)
{
	NSLog(@"UNIMPLEMENTED: cocoa_unwatch_file");
}

static hidval
cocoa_add_block_hook (void (*func) (hidval data), hidval user_data )
{
	NSLog(@"UNIMPLEMENTED: cocoa_add_block_hook");
}

static void
cocoa_stop_block_hook (hidval mlpoll)
{
	NSLog(@"UNIMPLEMENTED: cocoa_stop_block_hook");
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
	NSLog(@"UNIMPLEMENTED: cocoa_stop_block_hook");

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
	NSLog(@"UNIMPLEMENTED: cocoa_stop_block_hook");
}

char *
cocoa_prompt_for (char *msg, char *default_string)
{
	NSLog(@"UNIMPLEMENTED: cocoa_stop_block_hook");
    return default_string;
}

char *
cocoa_fileselect (const char *title, const char *descr,
                    char *default_file, char *default_ext,
                    const char *history_tag, int flags)
{
    if(flags & HID_FILESELECT_READ) {
		NSOpenPanel* openPanel = [NSOpenPanel openPanel];
		
		[openPanel setTitle: [NSString stringWithCString: title encoding: NSUTF8StringEncoding]];
		[openPanel setMessage: [NSString stringWithCString: descr encoding: NSUTF8StringEncoding]];
		
		if([openPanel runModal]==NSFileHandlingPanelOKButton) {
			return (char*)[[openPanel filename] cStringUsingEncoding: NSUTF8StringEncoding];
		}
	} else {
		NSSavePanel* savePanel = [NSSavePanel savePanel];
		[savePanel setTitle: [NSString stringWithCString: title encoding: NSUTF8StringEncoding]];
		[savePanel setMessage: [NSString stringWithCString: descr encoding: NSUTF8StringEncoding]];
		
		if([savePanel runModal]==NSFileHandlingPanelOKButton) {
			return (char*)[[savePanel filename] cStringUsingEncoding: NSUTF8StringEncoding];
		}
	}
	
    return nil;
}

int
cocoa_attribute_dialog (HID_Attribute * attrs,
                          int n_attrs, HID_Attr_Val * results,
                          const char * title, const char * descr)
{
	NSLog(@"UNIMPLEMENTED: cocoa_stop_block_hook");
}

static void
cocoa_show_item (void *item)
{
	NSLog(@"UNIMPLEMENTED: cocoa_stop_block_hook");
}

static void
cocoa_beep (void)
{
	NSLog(@"UNIMPLEMENTED: cocoa_stop_block_hook");
}

static int
cocoa_progress (int so_far, int total, const char *message)
{
	NSLog(@"UNIMPLEMENTED: cocoa_stop_block_hook");
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

static int
PCBChanged (int argc, char **argv, int x, int y)
{
	hid_action ("NetlistChanged");
	hid_action ("LayersChanged");
	hid_action ("RouteStylesChanged");

	[[CocoaHID instance] PCBChanged];
	
	return 0;
}

static int
PointCursor (int argc, char **argv, int x, int y)
{
	[[CocoaHID instance] pointCursor];
}

HID_Action cocoa_main_action_list[] = {
	{"PCBChanged", 0, PCBChanged,
		pcbchanged_help, pcbchanged_syntax},
	{"PointCursor", 0, PointCursor},
/*	
	{"SetUnits", 0, SetUnits,
		setunits_help, setunits_syntax},
	{"Zoom", "Click on a place to zoom in", ZoomAction,
		zoom_help, zoom_syntax},
	{"Pan", "Click on a place to pan", PanAction,
		zoom_help, zoom_syntax},
	{"SwapSides", 0, SwapSides,
		swapsides_help, swapsides_syntax},
	{"Command", 0, Command,
		command_help, command_syntax},
	{"Benchmark", 0, Benchmark,
		benchmark_help, benchmark_syntax},
	{"Center", "Click on a location to center", Center},
	{"Busy", 0, Busy},
	{"Cursor", 0, CursorAction,
		cursor_help, cursor_syntax},
*/ 
};

REGISTER_ACTIONS (cocoa_main_action_list)

#include "dolists.h"


void
hid_cocoa_init ()
{	
    hid_register_hid (&cocoa_gui);

// REGISTER_ACTIONS (cocoa_dialog_action_list)
 REGISTER_ACTIONS (cocoa_library_action_list)
// REGISTER_FLAGS (cocoa_main_flag_list)
// REGISTER_ATTRIBUTES (cocoa_attribute_list)
 REGISTER_ACTIONS (cocoa_main_action_list)
 REGISTER_ACTIONS (cocoa_menu_action_list)
 REGISTER_ATTRIBUTES(pcbmenu_attr)
// REGISTER_ACTIONS (cocoa_netlist_action_list)
 REGISTER_ACTIONS (cocoa_styles_action_list)
}


static CocoaHID* instance = nil;

@implementation CocoaHID

@synthesize mainView;
@synthesize scrollView;

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
	context = nil;
	currentView = nil;
	currentContext = nil;
}

+(CocoaHID*) instance {
	return instance;
}

- (void) awakeFromNib {
	instance = self;
	[[mainView window] setAcceptsMouseMovedEvents: YES];
	[mainView setPostsBoundsChangedNotifications: YES];
	[mainView setPostsFrameChangedNotifications: YES];
	[scrollView setDocumentView: mainView];

//	CrosshairOn(YES);
//	[mainView scaleUnitSquareToSize: NSMakeSize(0.002, 0.002)];
}

#pragma mark -
#pragma mark Cocoa <-> PCB functions
#pragma mark -

static const NSSize unitSize = {1.0, 1.0};

- (void) PCBChanged {
	float zoom = PCB->Zoom/1000.0;

//	NSRect r;
//	r = [mainView convertRect: [mainView bounds] toView: nil];
	NSSize newFrame = NSMakeSize(PCB->MaxWidth*zoom, PCB->MaxHeight*zoom);
	NSRect scrollFrame = [scrollView frame];
	
	if(newFrame.width<scrollFrame.size.width) {
		newFrame.width = scrollFrame.size.width;
	}
	
	if(newFrame.height<scrollFrame.size.height) {
		newFrame.height = scrollFrame.size.height;
	}
	
	[mainView setFrameSize: newFrame];
//	[mainView setBoundsSize: NSMakeSize(PCB->MaxWidth*zoom, PCB->MaxHeight*zoom)];
	 
	// reset the scaling
	[mainView scaleUnitSquareToSize: [mainView convertSize:unitSize fromView:nil]];
	[mainView scaleUnitSquareToSize: NSMakeSize(zoom, zoom)];
	[mainView setNeedsDisplay: YES];
}

- (void) pointCursor {
	[scrollView setDocumentCursor: [NSCursor crosshairCursor]];
}

- (void) timerCallback:(NSTimer*)timer {
	NSDictionary* dict;
	void (*func) (hidval);
	hidval user_data;

	dict = [timer userInfo];
	func = [[dict objectForKey: @"callback"] pointerValue];
	user_data.lval = [[dict objectForKey: @"lvar"] longValue];
	user_data.ptr = [[dict objectForKey: @"ptr"] pointerValue];
	
	// set things up so that the callback function can perform drawing operations
	[mainView lockFocus];
	[CocoaHID drawToView: mainView];
	func(user_data);
	[CocoaHID finishedDrawing];
	[mainView unlockFocus];
	
}

- (NSTimer*) scheduleTimerFor:(void*)callback withInterval:(unsigned long) milliseconds andUserData:(hidval)data {
	NSDictionary* dict = [NSDictionary dictionaryWithObjectsAndKeys:
						  [NSValue valueWithPointer: callback], @"callback",
						  [NSNumber numberWithLong: data.lval], @"lvar",
						  [NSValue valueWithPointer: data.ptr], @"ptr",
						  nil];
	return [NSTimer scheduledTimerWithTimeInterval: milliseconds/1000.0 target: self selector: @selector(timerCallback:) userInfo: dict repeats: NO];
}

#pragma mark -
#pragma mark Actions
#pragma mark -

- (IBAction) needsRedraw:(id)sender {
	[mainView setNeedsDisplay: YES];
}


- (IBAction) zoomIn:(id)sender {
	// TODO: make the zoom centered
	
	PCB->Zoom *= 1.25;
	[self PCBChanged];
}

- (IBAction) zoomOut:(id)sender {
	PCB->Zoom /= 1.25;
	[self PCBChanged];
}

@end
