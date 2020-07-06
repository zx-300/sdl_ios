/*
 * Copyright (c) 2020, SmartDeviceLink Consortium, Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * Redistributions of source code must retain the above copyright notice, this
 * list of conditions and the following disclaimer.
 *
 * Redistributions in binary form must reproduce the above copyright notice,
 * this list of conditions and the following
 * disclaimer in the documentation and/or other materials provided with the
 * distribution.
 *
 * Neither the name of the SmartDeviceLink Consortium Inc. nor the names of
 * its contributors may be used to endorse or promote products derived
 * from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#import "SDLTurnSignal.h"
#import "SDLElectronicParkBrakeStatus.h"
#import "SDLWiperStatus.h"
#import "SDLVehicleDataEventStatus.h"
#import "SDLPRNDL.h"
#import "SDLRPCNotification.h"
#import "SDLComponentVolumeStatus.h"

@class SDLHeadLampStatus;
@class SDLBodyInformation;
@class SDLMyKey;
@class SDLTireStatus;
@class SDLECallInfo;
@class SDLDeviceStatus;
@class SDLClusterModeStatus;
@class SDLBeltStatus;
@class SDLAirbagStatus;
@class SDLGPSData;
@class SDLEmergencyEvent;
@class SDLFuelRange;

NS_ASSUME_NONNULL_BEGIN

/**
 * Callback for the periodic and non periodic vehicle data read function.
 *
 * @since SDL 2.0.0
 */
@interface SDLOnVehicleData : SDLRPCNotification

/**
 The car current GPS coordinates
 */
@property (strong, nonatomic, nullable) SDLGPSData *gps;

/**
 The vehicle speed in kilometers per hour
 */
@property (strong, nonatomic, nullable) NSNumber<SDLFloat> *speed;

/**
 The number of revolutions per minute of the engine.
 */
@property (strong, nonatomic, nullable) NSNumber<SDLInt> *rpm;

/**
 The fuel level in the tank (percentage)
 */
@property (strong, nonatomic, nullable) NSNumber<SDLFloat> *fuelLevel;

/**
 The fuel level state
 */
@property (strong, nonatomic, nullable) SDLComponentVolumeStatus fuelLevel_State;

/**
 The estimate range in KM the vehicle can travel based on fuel level and consumption

 Optional, Array of length 0 - 100, of SDLFuelRange
 */
@property (strong, nonatomic, nullable) NSArray<SDLFuelRange *> *fuelRange;

/**
 The instantaneous fuel consumption in microlitres
 */
@property (strong, nonatomic, nullable) NSNumber<SDLFloat> *instantFuelConsumption;

/**
 The external temperature in degrees celsius.
 */
@property (strong, nonatomic, nullable) NSNumber<SDLFloat> *externalTemperature;

/**
 The Vehicle Identification Number
 */
@property (strong, nonatomic, nullable) NSString *vin;

/**
 The current gear shift state of the user's vehicle
 */
@property (strong, nonatomic, nullable) SDLPRNDL prndl;

/**
 The current pressure warnings for the user's vehicle
 */
@property (strong, nonatomic, nullable) SDLTireStatus *tirePressure;

/**
 Odometer reading in km
 */
@property (strong, nonatomic, nullable) NSNumber<SDLInt> *odometer;

/**
 The status of the seat belts
 */
@property (strong, nonatomic, nullable) SDLBeltStatus *beltStatus;

/**
 The body information including power modes
 */
@property (strong, nonatomic, nullable) SDLBodyInformation *bodyInformation;

/**
 The IVI system status including signal and battery strength
 */
@property (strong, nonatomic, nullable) SDLDeviceStatus *deviceStatus;

/**
 The status of the brake pedal
 */
@property (strong, nonatomic, nullable) SDLVehicleDataEventStatus driverBraking;

/**
 The status of the wipers
 */
@property (strong, nonatomic, nullable) SDLWiperStatus wiperStatus;

/**
 Status of the head lamps
 */
@property (strong, nonatomic, nullable) SDLHeadLampStatus *headLampStatus;

/**
 The estimated percentage (0% - 100%) of remaining oil life of the engine
 */
@property (strong, nonatomic, nullable) NSNumber<SDLFloat> *engineOilLife;

/**
 Torque value for engine (in Nm) on non-diesel variants
 */
@property (strong, nonatomic, nullable) NSNumber<SDLFloat> *engineTorque;

/**
 Accelerator pedal position (percentage depressed)
 */
@property (strong, nonatomic, nullable) NSNumber<SDLFloat> *accPedalPosition;

/**
 Current angle of the steering wheel (in deg)
 */
@property (strong, nonatomic, nullable) NSNumber<SDLFloat> *steeringWheelAngle;

/**
 Emergency Call notification and confirmation data
 */
@property (strong, nonatomic, nullable) SDLECallInfo *eCallInfo;

/**
 The status of the air bags
 */
@property (strong, nonatomic, nullable) SDLAirbagStatus *airbagStatus;

/**
 Information related to an emergency event (and if it occurred)
 */
@property (strong, nonatomic, nullable) SDLEmergencyEvent *emergencyEvent;

/**
 The status modes of the cluster
 */
@property (strong, nonatomic, nullable) SDLClusterModeStatus *clusterModeStatus;

/**
 Information related to the MyKey feature
 */
@property (strong, nonatomic, nullable) SDLMyKey *myKey;

/**
 The status of the electronic parking brake
 */
@property (strong, nonatomic, nullable) SDLElectronicParkBrakeStatus electronicParkBrakeStatus;

/**
 The status of the turn signal
 */
@property (strong, nonatomic, nullable) SDLTurnSignal turnSignal;

/**
 The cloud app vehicle ID
 */
@property (strong, nonatomic, nullable) NSString *cloudAppVehicleID;

/**
 Sets the OEM custom vehicle data state for any given OEM custom vehicle data name.
 
 @param vehicleDataName The name of the OEM custom vehicle data item.
 @param vehicleDataState An object containing the OEM custom vehicle data item.

  Added in SmartDeviceLink 6.0
 */
- (void)setOEMCustomVehicleData:(NSString *)vehicleDataName withVehicleDataState:(NSObject *)vehicleDataState NS_SWIFT_NAME(setOEMCustomVehicleData(name:state:));

/**
 Gets the OEM custom vehicle data item for any given OEM custom vehicle data name.
 
 @param vehicleDataName The name of the OEM custom vehicle data item.
 @return An OEM custom vehicle data object for the given vehicle data name.

  Added in SmartDeviceLink 6.0
 */
- (nullable NSObject *)getOEMCustomVehicleData:(NSString *)vehicleDataName;

/**
 * To indicate whether driver hands are off the steering wheel
 *
 * @since SDL 6.2.0
 */
@property (strong, nonatomic, nullable) NSNumber<SDLBool> *handsOffSteering;

@end

NS_ASSUME_NONNULL_END
