//
//  CocoaMenu.h
//  PCB
//
//  Created by Daniel Parnell on 30/07/10.
//  Copyright 2010 Automagic Software Pty Ltd. All rights reserved.
//

#import <Cocoa/Cocoa.h>

@interface CocoaMenu : NSObject {
	NSMenu* mainMenu;
}

+(void) installMenus;
+(CocoaMenu*) instance;

@property(retain) IBOutlet NSMenu* mainMenu;

@end
