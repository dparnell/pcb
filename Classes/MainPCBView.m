//
//  MainPCBView.m
//  PCB
//
//  Created by Daniel Parnell on 1/08/10.
//  Copyright 2010 Automagic Software Pty Ltd. All rights reserved.
//

#import "MainPCBView.h"
#import "CocoaHID.h"

#import "action.h"
#import "crosshair.h"

@implementation MainPCBView

- (void)drawWithHID:(NSRect)dirtyRect {
	BoxType region;

	[[NSColor windowBackgroundColor] set];
	[NSBezierPath fillRect: dirtyRect];

	region.X1 = dirtyRect.origin.x;
	region.Y1 = dirtyRect.origin.y;
	region.X2 = dirtyRect.origin.x+dirtyRect.size.width;
	region.Y2 = dirtyRect.origin.y+dirtyRect.size.height;
	
	hid_expose_callback ([CocoaHID HID], &region, 0);	
}

- (BOOL) acceptsFirstResponder {
	return YES;
}

- (void)mouseEntered:(NSEvent *)theEvent {
	NSPoint where = [NSEvent mouseLocation];
	where = [[self window] convertScreenToBase: where];
	where = [self convertPointFromBase: where];
	
	EventMoveCrosshair (where.x, where.y);	
	RestoreCrosshair(YES); 
}

- (void)mouseExited:(NSEvent *)theEvent {
	HideCrosshair(YES);
}

- (void)mouseMoved:(NSEvent *)theEvent {
	NSPoint where = [NSEvent mouseLocation];
	where = [[self window] convertScreenToBase: where];
	where = [self convertPointFromBase: where];
	
	NSLog(@"%f %f", where.x, where.y);
	
	EventMoveCrosshair (where.x, where.y);	
}

@end
