//
//  CocoaDialogs.m
//  PCB
//
//  Created by Daniel Parnell on 21/09/10.
//  Copyright 2010 Automagic Software Pty Ltd. All rights reserved.
//

#import "CocoaDialogs.h"
#import "Cocoa/Cocoa.h"
#import "CocoaHID.h"

#import "config.h"
#import "global.h"
#import "hidint.h"

static const char load_syntax[] =
"Load()\n"
"Load(Layout|LayoutToBuffer|ElementToBuffer|Netlist|Revert)";

static const char load_help[] =
"Load layout data from a user-selected file.";

/* %start-doc actions Load
 
 This action is a GUI front-end to the core's @code{LoadFrom} action
 (@pxref{LoadFrom Action}).  If you happen to pass a filename, like
 @code{LoadFrom}, then @code{LoadFrom} is called directly.  Else, the
 user is prompted for a filename to load, and then @code{LoadFrom} is
 called with that filename.
 
 %end-doc */

static int
Load (int argc, char **argv, int x, int y)
{
	const char *function;
	char *name;
	NSString* pattern;
	NSOpenPanel* openDialog;
	
	if (argc > 1)
		return hid_actionv ("LoadFrom", argc, argv);
	
	function = argc ? argv[0] : "Layout";
	
	
	if (strcasecmp (function, "Netlist") == 0)
		pattern = @"*.net";
	else if (strcasecmp (function, "ElementToBuffer") == 0)
		pattern = @"*.fp";
	else
		pattern = @"*.pcb";
	
	openDialog = [NSOpenPanel openPanel];
	[openDialog setAllowedFileTypes: [NSArray arrayWithObject: pattern]];
	
	if([openDialog runModal]==NSFileHandlingPanelOKButton) {
		name = (char*)[[openDialog filename] cStringUsingEncoding: NSUTF8StringEncoding];
		hid_actionl ("LoadFrom", function, name, NULL);
	}
	
	
	
	return 0;
}

HID_Action cocoa_dialog_action_list[] = {
	{"Load", 0, Load,
		load_help, load_syntax},
/*	
	{"LoadVendor", 0, LoadVendor,
		loadvendor_help, loadvendor_syntax},
	{"Save", 0, Save,
		save_help, save_syntax},
	{"DoWindows", 0, DoWindows,
		dowindows_help, dowindows_syntax},
	{"PromptFor", 0, PromptFor,
		promptfor_help, promptfor_syntax},
	{"Confirm", 0, ConfirmAction},
	{"About", 0, About,
		about_help, about_syntax},
	{"Print", 0, Print,
		print_help, print_syntax},
	{"PrintCalibrate", 0, PrintCalibrate,
		printcalibrate_help, printcalibrate_syntax},
	{"Export", 0, Export,
		export_help, export_syntax},
	{"AdjustSizes", 0, AdjustSizes,
		adjustsizes_help, adjustsizes_syntax},
	{"EditLayerGroups", 0, EditLayerGroups,
		editlayergroups_help, editlayergroups_syntax},
 */
};

REGISTER_ACTIONS (cocoa_dialog_action_list)


@implementation CocoaDialogs

@end
