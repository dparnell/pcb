//
//  LibraryPreviewView.h
//  PCB
//
//  Created by Daniel Parnell on 30/07/10.
//  Copyright 2010 Automagic Software Pty Ltd. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import "CocoaPCBView.h"

@interface LibraryPreviewView : CocoaPCBView {
	ElementTypePtr element;
}

@property(assign) ElementTypePtr element;

@end
