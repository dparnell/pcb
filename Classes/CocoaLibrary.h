//
//  CocoaLibrary.h
//  PCB
//
//  Created by Daniel Parnell on 30/07/10.
//  Copyright (c) 2010 __MyCompanyName__. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import "LibraryPreviewView.h"

@interface CocoaLibrary : NSWindowController {
@private
    NSArray* items;
	NSArray* selectedItem;
	LibraryPreviewView* previewView;
}

+ (void) showLibrary;
+ (void) libraryChanged;

- (void) updateLibraryModel;

@property(readonly) NSArray* items;
@property(retain) NSArray* selectedItem;
@property(retain) IBOutlet LibraryPreviewView* previewView;

@end
