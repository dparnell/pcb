//
//  PCBAppDelegate.m
//  PCB
//
//  Created by Daniel Parnell on 26/07/10.
//  Copyright (c) 2010 __MyCompanyName__. All rights reserved.
//


#import "PCBAppDelegate.h"
#import "CocoaLibrary.h"
#import "file.h"

@implementation PCBAppDelegate

@synthesize window;

- (void)applicationDidFinishLaunching:(NSNotification *)aNotification {
	[CocoaLibrary showLibrary];

	NSString* tut = [NSString stringWithFormat: @"%@/tutorial/tut1.pcb", [[NSBundle mainBundle] resourcePath]];
	LoadPCB((char*)[tut cStringUsingEncoding: NSUTF8StringEncoding]);
}

@end

