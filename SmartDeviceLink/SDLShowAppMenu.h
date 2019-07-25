//
//  SDLOpenMenu.h
//  SmartDeviceLink
//
//  Created by Justin Gluck on 7/12/19.
//  Copyright © 2019 smartdevicelink. All rights reserved.
//

#import "SDLRPCRequest.h"

NS_ASSUME_NONNULL_BEGIN

/**
 *  Used by an app typically of navigation type to show the apps menu.
 */
@interface SDLShowAppMenu : SDLRPCRequest

- (instancetype)initWithMenuID:(UInt32)menuID;

/**
 * a Menu ID that identifies the sub menu to open. If not set the top level menu will be opened.
 */
@property (nullable, strong, nonatomic) NSNumber<SDLInt> *menuID;

@end

NS_ASSUME_NONNULL_END
