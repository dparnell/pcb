//
//  CocoaHID.h
//  PCB
//
//  Created by Daniel Parnell on 29/07/10.
//  Copyright (c) 2010 __MyCompanyName__. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "global.h"
#import "MainPCBView.h"

@interface CocoaHID : NSObject {
@private
	MainPCBView* mainView;
}

+(HID*) HID;
+(void) drawToView:(NSView*)aView;
+(void) finishedDrawing;
+(CocoaHID*) instance;

- (void) PCBChanged;

@property(retain) IBOutlet MainPCBView* mainView;

@end
