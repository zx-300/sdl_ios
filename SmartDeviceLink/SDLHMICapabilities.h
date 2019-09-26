//
//  SDLHMICapabilities.h
//  SmartDeviceLink-iOS

#import "SDLRPCStruct.h"

NS_ASSUME_NONNULL_BEGIN

/**
 Contains information about the HMI capabilities.

 Since SDL 3.0
**/
@interface SDLHMICapabilities : SDLRPCStruct

/**
 Availability of built in Nav. True: Available, False: Not Available
 
 Boolean value. Optional.

 Since SDL 3.0
 */
@property (nullable, copy, nonatomic) NSNumber<SDLBool> *navigation;

/**
 Availability of built in phone. True: Available, False: Not Available
 
 Boolean value. Optional.

 Since SDL 3.0
 */
@property (nullable, copy, nonatomic) NSNumber<SDLBool> *phoneCall;

/**
 Availability of built in video streaming. True: Available, False: Not Available

 Boolean value. Optional.

 Since SDL 4.5
 */
@property (nullable, copy, nonatomic) NSNumber<SDLBool> *videoStreaming;

/**
 Availability of built in remote control. True: Available, False: Not Available

 Boolean value. Optional.

 Since SDL 4.5
**/
@property (nullable, copy, nonatomic) NSNumber<SDLBool> *remoteControl;

@end

NS_ASSUME_NONNULL_END
