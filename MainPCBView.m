//
//  MainPCBView.m
//  PCB
//
//  Created by Daniel Parnell on 1/08/10.
//  Copyright 2010 __MyCompanyName__. All rights reserved.
//

#import "MainPCBView.h"
#import "CocoaHID.h"

@implementation MainPCBView

- (void)drawWithHID:(NSRect)dirtyRect {
	BoxType region;

	NSAffineTransform* transform = [NSAffineTransform transform];
	[transform scaleXBy: 0.001 yBy: 0.001];
	[transform concat];

	NSRect r = [self convertRectFromBase: dirtyRect];
	
	region.X1 = r.origin.x;
	region.Y1 = r.origin.y;
	region.X2 = r.origin.x+r.size.width;
	region.Y2 = r.origin.y+r.size.height;
	
	hid_expose_callback ([CocoaHID HID], &region, 0);	
}

@end
