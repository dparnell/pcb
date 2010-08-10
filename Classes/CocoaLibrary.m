//
//  CocoaLibrary.m
//  PCB
//
//  Created by Daniel Parnell on 30/07/10.
//  Copyright (c) 2010 Automagic Software Pty Ltd. All rights reserved.
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
@synthesize previewView;

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
		NSMutableDictionary* dir = nil;
		NSMutableArray* dirItems = nil;
		
		NSString* dirName = [NSString stringWithCString: menu->directory encoding: NSUTF8StringEncoding];
		for(NSMutableDictionary* d in newItems) {
			if ([dirName isEqualToString: [d objectForKey: @"name"]]) {
				dir = d;
				break;
			}
		}
		
		if (dir==nil) {
			dirItems = [NSMutableArray array];
			dir = [NSMutableDictionary dictionaryWithObjectsAndKeys:
				   [NSString stringWithCString: menu->directory 
									  encoding: NSUTF8StringEncoding], @"name",
				   dirItems, @"children",
				   nil
				   ];
			
			[newItems insertObject: dir atIndex: 0];
		} else {
			dirItems = [dir objectForKey: @"children"];
		}

		
		NSMutableArray* libItems = [NSMutableArray array];
		if (!menu->directory)	/* Shouldn't happen */
			menu->directory = strdup("???");
		
		ENTRY_LOOP (menu);
		{
			[libItems insertObject:[NSMutableDictionary dictionaryWithObjectsAndKeys:
									[NSString stringWithCString: entry->ListEntry 
													   encoding: NSUTF8StringEncoding], @"name",
									[NSValue valueWithPointer: menu], @"menu",
									[NSValue valueWithPointer: entry], @"entry",
									nil
									]
						   atIndex: 0];
		}
		END_LOOP;

		[dirItems addObject: [NSMutableDictionary dictionaryWithObjectsAndKeys: 
							  [NSString stringWithCString: menu->Name 
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

#pragma mark -
#pragma mark properties
#pragma mark -

- (NSArray*) selectedItem {
	return selectedItem;
}

- (void) setSelectedItem:(NSArray *)paths {
	
	[paths retain];
	[selectedItem release];
	selectedItem = paths;
	
	
	if ([paths count]>0) {
		NSIndexPath* path = [paths objectAtIndex: 0];
		NSArray* current = items;
		NSDictionary* item = nil;
		int L = [path length];
		for(int i=0; i<L; i++) {
			item = [current objectAtIndex: [path indexAtPosition: i]];
			current = [item objectForKey: @"children"];
		}
		
		if (item && current==nil) {
			// we've found a leaf node
			LibraryEntryType *entry = (LibraryEntryType *)[[item objectForKey: @"entry"] pointerValue];
			
			if(entry) {
				if (entry->Template == (char *) -1)
				{
					if (LoadElementToBuffer (PASTEBUFFER, entry->AllocatedMemory, True)) {
						SetMode (PASTEBUFFER_MODE);
					}
				} else {
					/* Otherwise, it's a m4 element and we need to create a string of
					 |  macro arguments to be passed to the library command in
					 |  LoadElementToBuffer()
					 */
					NSString* m4_args = [NSString stringWithFormat: @"'%s' '%s' '%s'", EMPTY (entry->Template),
										 EMPTY (entry->Value), EMPTY (entry->Package)];;
					
					if (LoadElementToBuffer (PASTEBUFFER, (char*)[m4_args cStringUsingEncoding: NSUTF8StringEncoding], False))
						SetMode (PASTEBUFFER_MODE);
				}
				
				previewView.element = PASTEBUFFER->Data->Element;
			}		
		}		
		
	}
}

@end
