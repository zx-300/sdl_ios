//
//  SDLPermissionFilter.h
//  SmartDeviceLink-iOS
//
//  Created by Joel Fischer on 11/18/15.
//  Copyright © 2015 smartdevicelink. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "SDLPermissionConstants.h"
#import "SDLPermissionElement.h"


NS_ASSUME_NONNULL_BEGIN

@interface SDLPermissionFilter : NSObject <NSCopying>

/**
 *  An identifier for the permission filter to allow it to be removed at a later time.
 */
@property (copy, nonatomic, readonly) SDLPermissionObserverIdentifier identifier;

/**
 *  The type of this filter group.
 */
@property (assign, nonatomic, readonly) SDLPermissionGroupType groupType;

/**
 *  The block that will be called on status changes to this filter group.
 */
@property (copy, nonatomic, readonly) SDLPermissionsChangedHandler handler;

/**
 *  The block that will be called on status changes to RPC permission status objects
 */
@property (copy, nonatomic, readonly) SDLRPCPermissionStatusChangedHandler rpcPermissionStatusHandler;

/**
 *  All of the permission elements in this filter group.
 */
@property (copy, nonatomic, readonly) NSArray<SDLPermissionElement *> *permissionElements;

/**
 *  Create a new permission filter group.
 *
 *  @param rpcNames  The names of the RPCs to watch permissions of.
 *  @param groupType The type of notifications to be sent for this filter group.
 *  @param handler  The block observer to be called when changes occur.
 *
 *  @return An instance of `SDLPermissionFilter`.
 */
- (instancetype)initWithRPCNames:(NSArray<SDLPermissionElement *> *)rpcNames groupType:(SDLPermissionGroupType)groupType permissionsHandler:(nullable SDLPermissionsChangedHandler)handler rpcPermissionStatusHandler:(nullable SDLRPCPermissionStatusChangedHandler)permissionStatusHandler NS_DESIGNATED_INITIALIZER;

/**
 *  Create a new permission filter group.
 *
 *  @param rpcNames  The names of the RPCs to watch permissions of.
 *  @param groupType The type of notifications to be sent for this filter group.
 *  @param handler  The block observer to be called when changes occur.
 *
 *  @return An instance of `SDLPermissionFilter`.
 */
+ (instancetype)filterWithRPCNames:(NSArray<SDLPermissionElement *> *)rpcNames groupType:(SDLPermissionGroupType)groupType permissionsHandler:(nullable SDLPermissionsChangedHandler)handler rpcPermissionStatusHandler:(nullable SDLRPCPermissionStatusChangedHandler)permissionStatusHandler NS_SWIFT_UNAVAILABLE("Use the initializer");

/**
 *  Whether the current filter is equivalent with another filter or not.
 *
 *  @param otherFilter The other filter to test equivalence with.
 *
 *  @return YES if this filter is equivalent with `otherFilter`, NO otherwise.
 */
- (BOOL)isEqualToFilter:(SDLPermissionFilter *)otherFilter;

/**
 *  Converts an array of SDLPermissionElement objects to and array of SDLPermissionRPCName objects
 *
 *  @param permissionElements The permission elements to convert.
 *
 *  @return An array of SDLPermissionRPCName objects
 */
- (NSArray<SDLPermissionRPCName> *)rpcNamesFromPermissionElements:(NSArray<SDLPermissionElement *> *)permissionElements;

@end

NS_ASSUME_NONNULL_END
