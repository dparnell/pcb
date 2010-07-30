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

static int
LibraryShow (int argc, char **argv, int x, int y)
{
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

@implementation CocoaLibrary

+ (void) initialize {
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
    
    // Implement this method to handle any initialization after your window controller's window has been loaded from its nib file.
}

@end
