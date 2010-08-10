//
//  LibraryPreviewView.m
//  PCB
//
//  Created by Daniel Parnell on 30/07/10.
//  Copyright 2010 Automagic Software Pty Ltd. All rights reserved.
//

#import "LibraryPreviewView.h"
#import "CocoaHID.h"
#import "data.h"

@implementation LibraryPreviewView

@synthesize element;

- (void)drawWithHID:(NSRect)dirtyRect {	
	NSRect r = [self bounds];
	[[NSColor whiteColor] set];
	[NSBezierPath fillRect: r];
	
	if(element) {
		float width = element->BoundingBox.X2 - element->BoundingBox.X1;
		float height = element->BoundingBox.Y2 - element->BoundingBox.Y1;
		
		float sx = r.size.width/(width*2);
		float sy = r.size.height/(height*2);
		float scale;
		
		if(sx>sy) {
			scale = sy;
		} else {
			scale = sx;
		}
		
		NSAffineTransform* transform = [NSAffineTransform transform];
		[transform scaleXBy: scale yBy: scale];		
		[transform translateXBy: -Settings.PinoutOffsetX-element->BoundingBox.X1+width/2.0  yBy: -Settings.PinoutOffsetY-element->BoundingBox.Y1+height/2.0];
		[transform concat];

		hid_expose_callback ([CocoaHID HID], NULL, element);
		
	}
}

- (ElementTypePtr) element {
	return element;
}

- (void) setElement:(ElementTypePtr)newElement {
	element = newElement;

	[self setNeedsDisplay: YES];
}

@end
