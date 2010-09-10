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
#import "hid_resource.h"

@implementation MainPCBView

- (void)drawWithHID:(NSRect)dirtyRect {
	BoxType region;

	CrosshairOff(YES);
	
	[[NSColor windowBackgroundColor] set];
	[NSBezierPath fillRect: dirtyRect];

	region.X1 = dirtyRect.origin.x;
	region.Y1 = dirtyRect.origin.y;
	region.X2 = dirtyRect.origin.x+dirtyRect.size.width;
	region.Y2 = dirtyRect.origin.y+dirtyRect.size.height;
	
	hid_expose_callback ([CocoaHID HID], &region, 0);	

	if(mouseDown) {
		mouseDown = NO;
		do_mouse_action(button, mods);			
	}
	if(mouseUp) {
		mouseUp = NO;
		do_mouse_action(button, mods | M_Release);	
	}
	if(mouseMoved) {
		mouseMoved = NO;
		EventMoveCrosshair (where.x, where.y);	
	}
	
	DrawMark(YES);
	CrosshairOn(YES);		
}

- (BOOL) acceptsFirstResponder {
	return YES;
}

- (void)mouseMoved:(NSEvent *)theEvent {
	where = [NSEvent mouseLocation];
	where = [[self window] convertScreenToBase: where];
	where = [self convertPointFromBase: where];
	
	mouseMoved = YES;	
	[self setNeedsDisplay: YES];
}

- (void) modsForEvent:(NSEvent*) theEvent {
	mods = 0;
	
	lastModifierFlags = [theEvent modifierFlags];
	
	if(lastModifierFlags & NSShiftKeyMask) {
		mods |= M_Shift;
	}
	if(lastModifierFlags & NSControlKeyMask) {
		mods |= M_Ctrl;
	}
	if(lastModifierFlags & NSCommandKeyMask) {
		mods |= M_Alt;
	}
}

- (void)mouseDown:(NSEvent *)theEvent {
	[self modsForEvent: theEvent];
	mouseDown = YES;
	button = [theEvent buttonNumber]+1;
	
	[self setNeedsDisplay: YES];
}

- (void)mouseUp:(NSEvent *)theEvent {
	[self modsForEvent: theEvent];
	mouseUp = YES;
	button = [theEvent buttonNumber]+1;
	
	[self setNeedsDisplay: YES];
}

- (void) mouseDragged:(NSEvent *)theEvent {
	[self mouseMoved: theEvent];
	[self autoscroll: theEvent];
}

- (BOOL)acceptsFirstMouse:(NSEvent *)theEvent {
	return YES;
}

@end
