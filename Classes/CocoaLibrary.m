//
//  CocoaLibrary.m
//  PCB
//
//  Created by Daniel Parnell on 30/07/10.
//  Copyright (c) 2010 __MyCompanyName__. All rights reserved.
//

#import "CocoaLibrary.h"
#import "global.h"
#import "hid.h"
#import "buffer.h"
#import "data.h"
#import "set.h"

static int
LibraryShow (int argc, char **argv, int x, int y)
{
	[CocoaLibrary showLibrary];
    return 0;
}

static int
LibraryChanged (int argc, char **argv, int x, int y)
{
	
    return 0;
}

static const char libraryshow_syntax[] =
"LibraryShow()";

static const char libraryshow_help[] =
"Displays the library window.";

HID_Action cocoa_library_action_list[] = {
    {"LibraryChanged", 0, LibraryChanged,
        librarychanged_help, librarychanged_syntax},
    {"LibraryShow", 0, LibraryShow,
        libraryshow_help, libraryshow_syntax},
};

REGISTER_ACTIONS (cocoa_library_action_list)

static CocoaLibrary* instance = nil;

@implementation CocoaLibrary

@synthesize items;

+ (void) showLibrary {
	if (instance==nil) {
		instance = [[[CocoaLibrary alloc] initWithWindowNibName: @"LibraryWindow"] retain];
	}
	
	[instance showWindow: nil];
}

+ (void) libraryChanged {
	if (instance) {
		[instance updateLibraryModel];
	}
}

- (id)initWithWindow:(NSWindow *)window {
    if ((self = [super initWithWindow:window])) {
        // Initialization code here.
    }
    
    return self;
}

- (void)dealloc {
    // Clean-up code here.
    
    [super dealloc];
}

- (void)windowDidLoad {
    [super windowDidLoad];
    
	[instance updateLibraryModel];
}

- (void) updateLibraryModel {
	[self willChangeValueForKey: @"items"];
	NSMutableArray* newItems = [NSMutableArray array];
	
	MENU_LOOP (&Library);
	{
		NSMutableArray* libItems = [NSMutableArray array];
		if (!menu->directory)	/* Shouldn't happen */
			menu->directory = strdup("???");
		
		NSLog(@"%s", menu->directory);
		ENTRY_LOOP (menu);
		{
			NSLog(@"\t%s", entry->ListEntry);
			[libItems addObject: [NSMutableDictionary dictionaryWithObjectsAndKeys:
								  [NSString stringWithCString: entry->ListEntry 
													 encoding: NSUTF8StringEncoding], @"name",
								  [NSValue valueWithPointer: menu], @"menu",
								  [NSValue valueWithPointer: entry], @"entry",
								  nil
								  ]];
		}
		END_LOOP;

		[newItems addObject: [NSMutableDictionary dictionaryWithObjectsAndKeys: 
							  [NSString stringWithCString: menu->directory 
												 encoding: NSUTF8StringEncoding], @"name",
							  libItems, @"children",
							  nil
							  ]];
	}
	END_LOOP;
	
	[items release];
	items = [newItems retain];
	
	[self didChangeValueForKey: @"items"];
}

@end
