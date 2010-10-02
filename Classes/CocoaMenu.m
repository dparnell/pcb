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
#import "data.h"

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


int
cocoa_call_action (const char *aname, int argc, char **argv)
{
	int px, py, ret;
	HID_Action *a;

	if (!aname)
		return 1;
	a = hid_find_action (aname);
	if (!a)
    {
		int i;
		printf ("no action %s(", aname);
		for (i = 0; i < argc; i++)
			printf ("%s%s", i ? ", " : "", argv[i]);
		printf (")\n");
		return 1;
    }
/*	
	if (a->need_coord_msg && !have_xy)
    {
		const char *msg;
		if (strcmp (aname, "GetXY") == 0)
			msg = argv[0];
		else
			msg = a->need_coord_msg;
		lesstif_get_xy (msg);
    }
	lesstif_coords_to_pcb (action_x, action_y, &px, &py);
*/	
	if (Settings.verbose)
    {
		int i;
		printf ("Action: \033[34m%s(", aname);
		for (i = 0; i < argc; i++)
			printf ("%s%s", i ? "," : "", argv[i]);
		printf (")\033[0m\n");
    }
	ret = a->trigger_cb (argc, argv, px, py);
	return ret;
}

static CocoaMenu* instance = nil;

@interface CocoaMenu(Private)

- (void) addResources:(Resource*)node toMenu:(NSMenu*) menu;

@end

@implementation CocoaMenu

@synthesize mainMenu;

+(CocoaMenu*) instance {
	return instance;
}

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
	
	if (mr) {
		[[CocoaMenu instance] addResources: mr toMenu: nil];
		
//		NSLog(@"menu = %@", instance.mainMenu);
	}
	
//		add_resource_to_menu (mb, mr, (XtCallbackProc) callback);
	
	mr = resource_subres (r, "Mouse");
	if (!mr)
		mr = resource_subres (bir, "Mouse");
	if (mr)
		load_mouse_resource (mr);
	
	
}

- (void)awakeFromNib {
	instance = self;
}

- (void) menuItemSelected:(NSMenuItem*) sender {
	NSValue* value = [sender representedObject];
	if(value) {
		int vi;
		Resource* node = [value pointerValue];
				
		for (vi = 1; vi < node->c; vi++)
			if (resource_type (node->v[vi]) == 10)
				if (hid_parse_actions (node->v[vi].value))
					return;
					
	}
	
}

- (void) addResources:(Resource*)node toMenu:(NSMenu*) menu {
	int i, j, n;
	char *v;
	Resource *r;
	NSMenuItem* item;
	NSMenu* subMenu;
	NSString* mnemonic;
	NSString* accelerator;
	NSString* title;
	
	if (menu==nil) {
		menu = mainMenu;
	}
	
	for (i = 0; i < node->c; i++)
		switch (resource_type (node->v[i]))
	{
		case 101:		/* named subnode */
			title = [NSString stringWithCString: node->v[i].value encoding: NSUTF8StringEncoding];
			item = [NSMenuItem new];
			[item setTitle: title];
			[item setRepresentedObject: [NSValue valueWithPointer: &node->v[i].subres]];
			
			subMenu = [[NSMenu alloc] initWithTitle: title];
			[item setSubmenu: subMenu];
			[menu addItem: item];
			
			[self addResources: node->v[i].subres toMenu: subMenu]; 
			break;
			
		case 1:			/* unnamed subres */
			n = 0;			
			if ((v = resource_value (node->v[i].subres, "m")))
			{
				mnemonic = [NSString stringWithCString: v encoding: NSUTF8StringEncoding];
			} else {
				mnemonic = nil;
			}
			if ((r = resource_subres (node->v[i].subres, "a")))
			{
				accelerator = [NSString stringWithCString: r->v[0].value encoding: NSUTF8StringEncoding];
			} else {
				accelerator = nil;
			}
			
			v = "button";
			for (j = 0; j < node->v[i].subres->c; j++)
				if (resource_type (node->v[i].subres->v[j]) == 10)
				{
					v = node->v[i].subres->v[j].value;
					break;
				}
			title = [NSString stringWithCString: v encoding: NSUTF8StringEncoding];

			if (node->v[i].subres->flags & FLAG_S)
			{
				item = [NSMenuItem new];
				[item setTitle: title];
				subMenu = [[NSMenu alloc] initWithTitle: title];
				[item setSubmenu: subMenu];
				[menu addItem: item];
				[self addResources: node->v[i].subres toMenu: subMenu];
			}
			else
			{
				Resource *radio = resource_subres (node->v[i].subres, "radio");
				char *checked = resource_value (node->v[i].subres, "checked");
				char *label = resource_value (node->v[i].subres, "sensitive");
				
				item = [[NSMenuItem alloc] initWithTitle: title action: @selector(menuItemSelected:) keyEquivalent: @""];
				[item setRepresentedObject: [NSValue valueWithPointer: node->v[i].subres]];
				[item setTarget: self];
				[menu addItem: item];
				
				if(accelerator) {
					[item setKeyEquivalent: accelerator];
				}
				
				if (radio)
				{
					 if (resource_value (node->v[i].subres, "set")) {
						 [item setState: NSOnState];
					 } else {
						 [item setState: NSOffState];
					 }
				}
				else if (checked)
				{
					
/*					
					if (strchr (checked, ','))
						stdarg (XmNindicatorType, XmONE_OF_MANY);
					else
						stdarg (XmNindicatorType, XmN_OF_MANY);
					btn = XmCreateToggleButton (menu, "menubutton", args, n);
					XtAddCallback (btn, XmNvalueChangedCallback,
								   callback, (XtPointer) node->v[i].subres);
*/ 
				}
				else if (label && strcmp (label, "false") == 0)
				{
					[item setEnabled: NO];
/*					
					stdarg (XmNalignment, XmALIGNMENT_BEGINNING);
					btn = XmCreateLabel (menu, "menulabel", args, n);
 */
				}
				else
				{
					/*
					btn = XmCreatePushButton (menu, "menubutton", args, n);
					XtAddCallback (btn, XmNactivateCallback,
								   callback, (XtPointer) node->v[i].subres);
					 */
				}
				
				for (j = 0; j < node->v[i].subres->c; j++)
					switch (resource_type (node->v[i].subres->v[j]))
				{
					case 110:	// named value = X resource
					{
						char *n = node->v[i].subres->v[j].name;
						if (strcmp (n, "fg") == 0)
							n = "foreground";
						if (strcmp (n, "bg") == 0)
							n = "background";
						if (strcmp (n, "m") == 0
							|| strcmp (n, "a") == 0
							|| strcmp (n, "sensitive") == 0)
							break;
						if (strcmp (n, "checked") == 0)
						{
							/*
							note_widget_flag (btn, XmNset,
											  node->v[i].subres->v[j].value);
							 */
							break;
						}
						if (strcmp (n, "active") == 0)
						{
							/*
							note_widget_flag (btn, XmNsensitive,
											  node->v[i].subres->v[j].value);
							 */
							break;
						}
						/*
						XtVaSetValues (btn, XtVaTypedArg,
									   n,
									   XtRString,
									   node->v[i].subres->v[j].value,
									   strlen (node->v[i].subres->v[j].value) + 1,
									   NULL);
						 */
					}
						break;
				}
				
//				XtManageChild (btn);
			}
			break;
			
		case 10:			/* unnamed value */
			n = 0;
			if (node->v[i].value[0] == '@')
			{
//				if (strcmp (node->v[i].value, "@layerview") == 0)
//					insert_layerview_buttons (menu);
//				if (strcmp (node->v[i].value, "@layerpick") == 0)
//					insert_layerpick_buttons (menu);
//				if (strcmp (node->v[i].value, "@routestyles") == 0)
//					lesstif_insert_style_buttons (menu);
			}
			else if (strcmp (node->v[i].value, "-") == 0)
			{
				item = [NSMenuItem separatorItem];
				[menu addItem: item];
			}
			else if (i > 0)
			{
				title = [NSString stringWithCString: node->v[i].value encoding: NSUTF8StringEncoding];
				item = [[NSMenuItem alloc] initWithTitle: title action: @selector(menuItemSelected:) keyEquivalent: @""];
				[item setRepresentedObject: [NSValue valueWithPointer: node->v[i].subres]];
				[menu addItem: item];
			}
 
			break;
	}
	
}
															

@end
