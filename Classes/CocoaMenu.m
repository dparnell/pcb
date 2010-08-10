//
//  CocoaMenu.m
//  PCB
//
//  Created by Daniel Parnell on 30/07/10.
//  Copyright 2010 __MyCompanyName__. All rights reserved.
//

#import "CocoaMenu.h"
#import "config.h"
#import "global.h"
#import "hidint.h"

static char *pcbmenu_path = "pcb-menu.res";

static HID_Attribute pcbmenu_attr[] = {
	{"pcb-menu", "Location of pcb-menu.res file",
		HID_String, 0, 0, {0, PCBLIBDIR "/pcb-menu.res", 0}, 0, &pcbmenu_path}
};

REGISTER_ATTRIBUTES(pcbmenu_attr)


static const char dumpkeys_syntax[] =
"DumpKeys()";

static const char dumpkeys_help[] =
"Dump cocoa key bindings.";

static int
DumpKeys (int argc, char **argv, int x, int y)
{
	return 0;
}

static const char debug_syntax[] =
"Debug(...)";

static const char debug_help[] =
"Debug action.";

static int
Debug (int argc, char **argv, int x, int y)
{
	int i;
	printf ("Debug:");
	for (i = 0; i < argc; i++)
		printf (" [%d] `%s'", i, argv[i]);
	printf (" x,y %d,%d\n", x, y);
	return 0;
}

static const char debugxy_syntax[] =
"DebugXY(...)";

static const char debugxy_help[] =
"Debug action, with coordinates";

static int
LayersChanged (int argc, char **argv, int x, int y)
{
	return 0;
}

static const char toggleview_syntax[] =
"ToggleView(1..MAXLAYER)\n"
"ToggleView(layername)\n"
"ToggleView(Silk|Rats|Pins|Vias|Mask|BackSide)";

static const char toggleview_help[] =
"Toggle the visibility of the specified layer or layer group.";

static int
ToggleView (int argc, char **argv, int x, int y)
{
	return 1;
}

static const char selectlayer_syntax[] =
"SelectLayer(1..MAXLAYER|Silk|Rats)";

static const char selectlayer_help[] =
"Select which layer is the current layer.";

static int
SelectLayer (int argc, char **argv, int x, int y)
{
	return 1;
}

HID_Action cocoa_menu_action_list[] = {
	{"DumpKeys", 0, DumpKeys,
		dumpkeys_help, dumpkeys_syntax},
	{"Debug", 0, Debug,
		debug_help, debug_syntax},
	{"DebugXY", "Click X,Y for Debug", Debug,
		debugxy_help, debugxy_syntax},
	{"LayersChanged", 0, LayersChanged,
		layerschanged_help, layerschanged_syntax},
	{"ToggleView", 0, ToggleView,
		toggleview_help, toggleview_syntax},
	{"SelectLayer", 0, SelectLayer,
		selectlayer_help, selectlayer_syntax}
};

REGISTER_ACTIONS (cocoa_menu_action_list)


@implementation CocoaMenu

@end
