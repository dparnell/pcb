//
//  CocoaMenu.m
//  PCB
//
//  Created by Daniel Parnell on 30/07/10.
//  Copyright 2010 Automagic Software Pty Ltd. All rights reserved.
//

#import "CocoaMenu.h"
#import "config.h"
#import "global.h"
#import "hidint.h"

#include "hid_resource.h"
#include "resource.h"
#include "misc.h"
#include "error.h"

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

+ (void) installMenus {
	char *filename;
	Resource *r = 0, *bir;
	char *home_pcbmenu, *home;
	Resource *mr;
	
	
	/* homedir is set by the core */
	home = homedir;
	home_pcbmenu = NULL;
	if (home == NULL)
    {
		Message ("Warning:  could not determine home directory (from HOME)\n");
    }
	else 
    {
		home_pcbmenu = Concat (home, PCB_DIR_SEPARATOR_S, ".pcb", 
							   PCB_DIR_SEPARATOR_S, "pcb-menu.res", NULL);
    }
	
	if (access ("pcb-menu.res", R_OK) == 0)
		filename = "pcb-menu.res";
	else if (home_pcbmenu != NULL && (access (home_pcbmenu, R_OK) == 0))
		filename = home_pcbmenu;
	else if (access (pcbmenu_path, R_OK) == 0)
		filename = pcbmenu_path;
	else
		filename = 0;
	
	bir = resource_parse ((char*)[[[NSBundle mainBundle] pathForResource: @"gpcb-menu" ofType: @"res"] cStringUsingEncoding: NSUTF8StringEncoding], 0);
	if (!bir)
    {
		fprintf (stderr, "Error: internal menu resource didn't parse\n");
		exit(1);
    }
	
	if (filename)
		r = resource_parse (filename, 0);
	
	if (!r)
		r = bir;
	
	if (home_pcbmenu != NULL)
    {
		free (home_pcbmenu);
    }
	
	mr = resource_subres (r, "MainMenu");
	if (!mr)
		mr = resource_subres (bir, "MainMenu");
//	if (mr)
//		add_resource_to_menu (mb, mr, (XtCallbackProc) callback);
	
	mr = resource_subres (r, "Mouse");
	if (!mr)
		mr = resource_subres (bir, "Mouse");
	if (mr)
		load_mouse_resource (mr);
	
	
}

@end
