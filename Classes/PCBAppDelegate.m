//
//  PCBAppDelegate.m
//  PCB
//
//  Created by Daniel Parnell on 26/07/10.
//  Copyright (c) 2010 Automagic Software Pty Ltd. All rights reserved.
//


#import "PCBAppDelegate.h"
#import "CocoaLibrary.h"
#import "file.h"
#import "CocoaMenu.h"

@implementation PCBAppDelegate

@synthesize window;

- (void)applicationDidFinishLaunching:(NSNotification *)aNotification {
	[CocoaLibrary showLibrary];
	[CocoaMenu installMenus];
	
//	NSString* tut = [NSString stringWithFormat: @"%@/tutorial/tut1.pcb", [[NSBundle mainBundle] resourcePath]];
//	LoadPCB((char*)[tut cStringUsingEncoding: NSUTF8StringEncoding]);
//	LoadPCB("/Users/daniel/Documents/board.pcb");
}


- (BOOL)application:(NSApplication *)theApplication openFile:(NSString *)filename {
	LoadPCB((char*)[filename cStringUsingEncoding: NSUTF8StringEncoding]);
	return YES;
}

@end

