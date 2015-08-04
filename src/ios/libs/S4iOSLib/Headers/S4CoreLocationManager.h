/* ***** BEGIN LICENSE BLOCK *****
 * Version: MPL 1.1
 *
 * The contents of this file are subject to the Mozilla Public License Version
 * 1.1 (the "License"); you may not use this file except in compliance with
 * the License. You may obtain a copy of the License at
 * http://www.mozilla.org/MPL/
 *
 * Software distributed under the License is distributed on an "AS IS" basis,
 * WITHOUT WARRANTY OF ANY KIND, either express or implied. See the License
 * for the specific language governing rights and limitations under the
 * License.
 *
 * The Original Code is the S4 iOS Libraries.
 *
 * The Initial Developer of the Original Code is
 * Michael Papp dba SeaStones Software Company.
 * All software created by the Initial Developer are Copyright (C) 2008-2011
 * the Initial Developer. All Rights Reserved.
 *
 * Original Author:
 *			Michael Papp, San Francisco, CA, USA
 *
 * ***** END LICENSE BLOCK ***** */

/* ***** FILE BLOCK ******
 *
 * Name:		S4CoreLocationManager.h
 * Module:		GeoLocation
 * Library:		S4 iOS Libraries
 *
 * ***** FILE BLOCK *****/


// ================================== Includes =========================================

#import <Foundation/Foundation.h>
#import <CoreLocation/CLErrorDomain.h>
#import <CoreLocation/CLError.h>
#import <CoreLocation/CLLocation.h>
#import <CoreLocation/CLLocationManager.h>
#import <CoreLocation/CLLocationManagerDelegate.h>
#import "S4DelgateArray.h"


// =================================== Defines =========================================



// ================================== Typedefs =========================================

typedef enum
{
	kHighestAccuracy		= 0,
	kHighAccuracy			= 1,
	kMediumAccuracy			= 2,
	kLowAccuracy			= 4,
	kLowestAccuracy			= 8,
	kDefaultAccuracy		= 16
}	LocationAccuracy;


// ================================== Globals =========================================



// ============================= Forward Declarations =================================

@class S4CoreLocationManager;


// ================================== Protocols ========================================

@protocol S4CoreLocationMgrDelegate <NSObject>

@required
- (void)coreLocManager: (S4CoreLocationManager *)clManager newLocationUpdate: (CLLocation *)newLocation;
- (void)coreLocManager: (S4CoreLocationManager *)clManager newError: (NSString *)errorString;

@optional
- (void)coreLocManager: (S4CoreLocationManager *)clManager newHeadingUpdate: (CLHeading *)newHeading;

@end


// ============================= S4CoreLocationManager Class ============================

@interface S4CoreLocationManager : NSObject <CLLocationManagerDelegate>
{
}

// Properties
@property (readonly, copy, nonatomic) CLLocation						*lastLocation;
@property (readwrite, nonatomic, assign) BOOL							shouldDisplayHeadingCalDialog;

// Class methods
+ (S4CoreLocationManager *)getInstance;

// Instance methods
- (void)startUpdatesWithAccuracy: (LocationAccuracy)newAccuracy;
- (void)stopUpdates;
- (void)setAccuracy: (LocationAccuracy)newAccuracy;
- (BOOL)locationServicesAvailable;
- (BOOL)addDelegate: (NSObject <S4CoreLocationMgrDelegate> *)newDelegate;
- (BOOL)removeDelegate: (NSObject <S4CoreLocationMgrDelegate> *)removeDelegate;
- (void)resetLastLocation;

// CLLocationManager delegate methods
- (void)locationManager: (CLLocationManager *)manager didUpdateToLocation: (CLLocation *)newLocation fromLocation: (CLLocation *)oldLocation;
- (void)locationManager: (CLLocationManager *)manager didFailWithError: (NSError *)error;
- (void)locationManager: (CLLocationManager *)manager didUpdateHeading: (CLHeading *)newHeading;
- (BOOL)locationManagerShouldDisplayHeadingCalibration: (CLLocationManager *)manager;

@end
