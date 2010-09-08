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

	[[NSColor windowBackgroundColor] set];
	[NSBezierPath fillRect: dirtyRect];

	region.X1 = dirtyRect.origin.x;
	region.Y1 = dirtyRect.origin.y;
	region.X2 = dirtyRect.origin.x+dirtyRect.size.width;
	region.Y2 = dirtyRect.origin.y+dirtyRect.size.height;
	
	hid_expose_callback ([CocoaHID HID], &region, 0);	
	DrawMark(YES);
//	DrawAttached(NO);
	CrosshairOn(YES);
}

- (BOOL) acceptsFirstResponder {
	return YES;
}

- (void)mouseEntered:(NSEvent *)theEvent {
	NSPoint where = [NSEvent mouseLocation];
	where = [[self window] convertScreenToBase: where];
	where = [self convertPointFromBase: where];
	
	[self lockFocus];
	[CocoaHID drawToView: self];
	EventMoveCrosshair (where.x, where.y);	
	RestoreCrosshair(YES); 
	[CocoaHID finishedDrawing];
	[self unlockFocus];
}

- (void)mouseExited:(NSEvent *)theEvent {
	[self lockFocus];
	[CocoaHID drawToView: self];
	HideCrosshair(YES);
	[CocoaHID finishedDrawing];
	[self unlockFocus];
}

- (void)mouseMoved:(NSEvent *)theEvent {
	NSPoint where = [NSEvent mouseLocation];
	where = [[self window] convertScreenToBase: where];
	where = [self convertPointFromBase: where];
	
//	NSLog(@"%f %f", where.x, where.y);
	
	[self lockFocus];
	[CocoaHID drawToView: self];
	CrosshairOff(YES);
	EventMoveCrosshair (where.x, where.y);	
	CrosshairOn(YES);
	[CocoaHID finishedDrawing];
	[self unlockFocus];
}

- (int) modsForEvent:(NSEvent*) theEvent {
	int mods = 0;
	
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

	return mods;
}

- (void)mouseDown:(NSEvent *)theEvent {
	int mods = [self modsForEvent: theEvent];
	
	[self lockFocus];
	[CocoaHID drawToView: self];
	HideCrosshair (YES);
	do_mouse_action([theEvent buttonNumber]+1, mods);	
	RestoreCrosshair(YES);
	[CocoaHID finishedDrawing];
	[self unlockFocus];
}

- (void)mouseUp:(NSEvent *)theEvent {
	int mods = [self modsForEvent: theEvent];
	
	[self lockFocus];
	[CocoaHID drawToView: self];
	HideCrosshair (YES);
	do_mouse_action([theEvent buttonNumber]+1, mods | M_Release);	
	RestoreCrosshair(YES);
	[CocoaHID finishedDrawing];
	[self unlockFocus];
}

- (void) mouseDragged:(NSEvent *)theEvent {
	[self mouseMoved: theEvent];
	
	BoxType region;
	NSRect dirtyRect = [self bounds];
	
//	NSLog(@"%f %f %f %f", dirtyRect.origin.x, dirtyRect.origin.y, dirtyRect.size.width, dirtyRect.size.height);
	
	[[NSColor windowBackgroundColor] set];
	[NSBezierPath fillRect: dirtyRect];
	
	region.X1 = dirtyRect.origin.x;
	region.Y1 = dirtyRect.origin.y;
	region.X2 = dirtyRect.origin.x+dirtyRect.size.width;
	region.Y2 = dirtyRect.origin.y+dirtyRect.size.height;
		
	NSPoint where = [NSEvent mouseLocation];
	where = [[self window] convertScreenToBase: where];
	where = [self convertPointFromBase: where];
	
	//	NSLog(@"%f %f", where.x, where.y);
	
	[self lockFocus];
	[CocoaHID drawToView: self];
	CrosshairOff(YES);
	EventMoveCrosshair (where.x, where.y);	
	hid_expose_callback ([CocoaHID HID], &region, 0);	
	CrosshairOn(YES);
	[CocoaHID finishedDrawing];
	[self unlockFocus];
}

@end
