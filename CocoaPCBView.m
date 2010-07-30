//
//  CocoaPCBView.m
//  PCB
//
//  Created by Daniel Parnell on 30/07/10.
//  Copyright 2010 Automagic Software Pty Ltd. All rights reserved.
//

#import "CocoaPCBView.h"
#import "CocoaHID.h"

@implementation CocoaPCBView

- (id)initWithFrame:(NSRect)frame {
    self = [super initWithFrame:frame];
    if (self) {
        // Initialization code here.
    }
    return self;
}

- (void)drawWithHID:(NSRect)dirtyRect {
}

- (BOOL) isFlipped {
	return YES;
}

- (void)drawRect:(NSRect)dirtyRect {
	[CocoaHID drawToView: self];
	[self drawWithHID: dirtyRect];
	[CocoaHID finishedDrawing];
}

@end
