//
//  MainPCBView.m
//  PCB
//
//  Created by Daniel Parnell on 1/08/10.
//  Copyright 2010 Automagic Software Pty Ltd. All rights reserved.
//

#import "MainPCBView.h"
#import "CocoaHID.h"

@implementation MainPCBView

- (void)drawWithHID:(NSRect)dirtyRect {
	BoxType region;

	[[NSColor windowBackgroundColor] set];
	[NSBezierPath fillRect: dirtyRect];
	
	NSAffineTransform* transform = [NSAffineTransform transform];
	[transform scaleXBy: 0.002 yBy: 0.002];
	[transform concat];

	[transform invert];
	
	NSRect r;	
	r.origin = [transform transformPoint: dirtyRect.origin];
	r.size = [transform transformSize: dirtyRect.size];
	
	region.X1 = r.origin.x;
	region.Y1 = r.origin.y;
	region.X2 = r.origin.x+r.size.width;
	region.Y2 = r.origin.y+r.size.height;
	
	hid_expose_callback ([CocoaHID HID], &region, 0);	
}

@end
