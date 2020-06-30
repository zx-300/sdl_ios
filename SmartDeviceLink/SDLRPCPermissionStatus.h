//
//  SDLRPCPermissionStatus.h
//  SmartDeviceLink
//
//  Created by James Lapinski on 6/29/20.
//  Copyright © 2020 smartdevicelink. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "SDLRPCFunctionNames.h"

NS_ASSUME_NONNULL_BEGIN

@interface SDLRPCPermissionStatus : NSObject

/**
 Name of the individual RPC.

 Required
 */
@property (strong, nonatomic, readonly) SDLRPCFunctionName rpcName;

/**
 * Whether or not the RPC is allowed.
 */
@property (assign, nonatomic, readonly, getter=isRPCAllowed) BOOL rpcAllowed;

/**
 * Holds a dictionary of RPC parameters and their permission status
 */
@property (strong, nonatomic, nullable, readonly) NSMutableDictionary<NSString *, NSNumber *> *rpcParameters;

/**
 *  Initializes a SDLRPCPermissionStatus object.
 *
 *  @param rpcName The name of the RPC.
 *  @param isRPCAllowed The permission status for the RPC.
 *  @param rpcParameters A dictionary that containers parameter permission status information.
 *
 *  @return An instance of the SDLRPCPermissionStatus class.
 */
- (instancetype)initWithRPCName:(SDLRPCFunctionName)rpcName isRPCAllowed:(BOOL)isRPCAllowed rpcParameters:(nullable NSDictionary<NSString *, NSNumber *> *)rpcParameters;

@end

NS_ASSUME_NONNULL_END
