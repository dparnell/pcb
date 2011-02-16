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
    int modalResult;
    
    NSButton* currentToolButton;
    
    NSBox* toolbarBox;
    
    NSButton* viaButton;
    NSButton* lineButton;
    NSButton* arcButton;
    NSButton* textButton;
    NSButton* rectButton;
    NSButton* polyButton;
    NSButton* bufButton;
    NSButton* delButton;
    NSButton* rotButton;
    NSButton* insButton;
    NSButton* thrmButton;
    NSButton* selButton;
    NSButton* lockButton;
}

+(HID*) HID;
+(void) drawToView:(NSView*)aView;
+(void) finishedDrawing;
+(CocoaHID*) instance;

- (void) PCBChanged;
- (void) pointCursor;
- (NSTimer*) scheduleTimerFor:(void*)callback withInterval:(unsigned long) milliseconds andUserData:(hidval)data;

- (char*) prompt:(char*)mesage withDefault:(char*)default_value;

- (IBAction) idle:(id)sender;

- (IBAction) needsRedraw:(id)sender;

- (IBAction) zoomIn:(id)sender;
- (IBAction) zoomOut:(id)sender;

- (IBAction) toobarButtonClicked:(NSButton*)sender;

@property(assign) IBOutlet MainPCBView* mainView;
@property(assign) IBOutlet NSScrollView* scrollView;

@property (assign) IBOutlet NSBox* toolbarBox;
@property (assign) IBOutlet NSButton *viaButton;
@property (assign) IBOutlet NSButton *lineButton;
@property (assign) IBOutlet NSButton *arcButton;
@property (assign) IBOutlet NSButton *textButton;
@property (assign) IBOutlet NSButton *rectButton;
@property (assign) IBOutlet NSButton *polyButton;
@property (assign) IBOutlet NSButton *bufButton;
@property (assign) IBOutlet NSButton *delButton;
@property (assign) IBOutlet NSButton *rotButton;
@property (assign) IBOutlet NSButton *insButton;
@property (assign) IBOutlet NSButton *thrmButton;
@property (assign) IBOutlet NSButton *selButton;
@property (assign) IBOutlet NSButton *lockButton;

@end
