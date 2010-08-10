//
//  CocoaStyles.m
//  PCB
//
//  Created by Daniel Parnell on 30/07/10.
//  Copyright 2010 Automagic Software Pty Ltd. All rights reserved.
//

#import "CocoaStyles.h"
#import "config.h"
#import "global.h"
#import "hidint.h"

static const char adjuststyle_syntax[] =
"AdjustStyle()";

static const char adjuststyle_help[] =
"Displays the route style adjustment window.";

/* %start-doc actions AdjustStyle
 
 %end-doc */

static int
AdjustStyle (int argc, char **argv, int x, int y)
{
	return 1;
}	

static int
RouteStylesChanged (int argc, char **argv, int x, int y)
{
	return 0;
}

HID_Action cocoa_styles_action_list[] = {
	{"AdjustStyle", 0, AdjustStyle,
		adjuststyle_help, adjuststyle_syntax},
	{"RouteStylesChanged", 0, RouteStylesChanged,
		routestyleschanged_help, routestyleschanged_syntax}
};

REGISTER_ACTIONS (cocoa_styles_action_list)


@implementation CocoaStyles

@end
