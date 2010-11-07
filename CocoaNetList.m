//
//  CocoaNetList.m
//  PCB
//
//  Created by Daniel Parnell on 7/11/10.
//  Copyright 2010 Automagic Software Pty Ltd. All rights reserved.
//

#import "CocoaNetList.h"
#include "global.h"

static int
CocoaNetlistChanged (int argc, char **argv, int x, int y)
{
	NSLog(@"NOT YET IMPLEMENTED: CocoaNetlistChanged");
	return 0;
}

static const char netlistshow_syntax[] =
"NetlistShow(pinname|netname)";

static const char netlistshow_help[] =
"Selects the given pinname or netname in the netlist window. Does not \
show the window if it isn't already shown.";

static int
CocoaNetlistShow (int argc, char **argv, int x, int y)
{
	NSLog(@"NOT YET IMPLEMENTED: CocoaNetlistShow");
	return 0;
}

static const char netlistpresent_syntax[] =
"NetlistPresent()";

static const char netlistpresent_help[] =
"Presents the netlist window.";

static int
CocoaNetlistPresent (int argc, char **argv, int x, int y)
{
	NSLog(@"NOT YET IMPLEMENTED: CocoaNetlistPresent");
	return 0;
}


HID_Action cocoa_netlist_action_list[] = {
	{"NetlistChanged", 0, CocoaNetlistChanged,
		netlistchanged_help, netlistchanged_syntax},
	{"NetlistShow", 0, CocoaNetlistShow,
		netlistshow_help, netlistshow_syntax},
	{"NetlistPresent", 0, CocoaNetlistPresent,
		netlistpresent_help, netlistpresent_syntax}
	,
};

REGISTER_ACTIONS (cocoa_netlist_action_list)

@implementation CocoaNetList

@end
