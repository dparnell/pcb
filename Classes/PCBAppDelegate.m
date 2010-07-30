//
//  PCBAppDelegate.m
//  PCB
//
//  Created by Daniel Parnell on 26/07/10.
//  Copyright (c) 2010 __MyCompanyName__. All rights reserved.
//


#import "PCBAppDelegate.h"
#import "CocoaLibrary.h"

@implementation PCBAppDelegate

@synthesize window;

- (void)applicationDidFinishLaunching:(NSNotification *)aNotification {

	[CocoaLibrary showLibrary];
}

@end

