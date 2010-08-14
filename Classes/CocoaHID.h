//
//  CocoaHID.h
//  PCB
//
//  Created by Daniel Parnell on 29/07/10.
//  Copyright (c) 2010 Automagic Software Pty Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "global.h"
#import "MainPCBView.h"

extern int lastModifierFlags;

@interface CocoaHID : NSObject {
@private
	MainPCBView* mainView;
	NSScrollView* scrollView;	
}

+(HID*) HID;
+(void) drawToView:(NSView*)aView;
+(void) finishedDrawing;
+(CocoaHID*) instance;

- (void) PCBChanged;
- (void) pointCursor;
- (NSTimer*) scheduleTimerFor:(void*)callback withInterval:(unsigned long) milliseconds andUserData:(hidval)data;

- (IBAction) zoomIn:(id)sender;
- (IBAction) zoomOut:(id)sender;

@property(retain) IBOutlet MainPCBView* mainView;
@property(retain) IBOutlet NSScrollView* scrollView;

@end
