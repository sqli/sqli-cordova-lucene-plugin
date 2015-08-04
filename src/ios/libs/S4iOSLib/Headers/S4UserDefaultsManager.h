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
 * Name:		S4UserDefaultsManager.h
 * Module:		Data
 * Library:		S4 iOS Libraries
 *
 * ***** FILE BLOCK *****/


// ================================== Includes =========================================

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>


// =================================== Defines =========================================



// ================================== Typedefs =========================================



// =================================== Globals =========================================



// ============================= Forward Declarations ==================================



// ================================== Protocols ========================================



// =========================== Class S4UserDefaultsManager =============================

@interface S4UserDefaultsManager : NSObject
{
}

// class methods
+ (S4UserDefaultsManager *)getInstance;
+ (BOOL)registerDefaultsFromFileAtPath: (NSString *)userDefaultsPath;

// instance methods
// registration methods
- (void)registerBooleanDefault: (BOOL)bValue forKey: (NSString *)key;
- (void)registerDoubleDefault: (double)dValue forKey: (NSString *)key;
- (void)registerFloatDefault: (float)value forKey: (NSString *)key;
- (void)registerIntegerDefault: (NSInteger)iValue forKey: (NSString *)key;
- (void)registerObjectDefault: (id)object forKey: (NSString *)key;
- (void)registerNSCodingObjectDefault: (id)object forKey: (NSString *)key;

// Call the various registration methods above and then
//  call this method to complete the process.  Passing
//  YES to reset will overwrite existing default values.
- (BOOL)registerDefaultsAndResetAllValues: (BOOL)reset;

/**************************************************************************************/
// NOTES:
//  NSUserDefaults only supports the following native types:
//		NSArray
//		NSData
//		NSDate
//		NSDictionary
//		NSNumber
//		NSString
/**************************************************************************************/

// getters and setters
- (NSMutableArray *)arrayForKey: (NSString *)key;
- (BOOL)setArray: (NSArray *)value forKey: (NSString *)key;

- (BOOL)boolForKey: (NSString *)key;
- (BOOL)setBool: (BOOL)bValue forKey: (NSString *)key;

- (NSMutableData *)dataForKey: (NSString *)key;
- (BOOL)setData: (NSData *)value forKey: (NSString *)key;

- (NSDate *)dateForKey: (NSString *)key;
- (BOOL)setDate: (NSDate *)value forKey: (NSString *)key;

- (NSMutableDictionary *)dictionaryForKey: (NSString *)key;
- (BOOL)setDictionary: (NSDictionary *)value forKey: (NSString *)key;

- (double)doubleForKey: (NSString *)key;
- (BOOL)setDouble: (double)dValue forKey: (NSString *)key;

- (float)floatForKey: (NSString *)key;
- (BOOL)setFloat: (float)fValue forKey: (NSString *)key;

- (NSInteger)integerForKey: (NSString *)key;
- (BOOL)setInteger: (NSInteger)iValue forKey: (NSString *)key;

- (NSMutableString *)stringForKey: (NSString *)key;
- (BOOL)setString: (NSString *)value forKey: (NSString *)key;

- (id)objectForKey: (NSString *)key;
- (BOOL)setObject: (id)value forKey: (NSString *)key;

// ANY NSObject-derived class that conforms to NSCoding protocol
//  can be stored in NSUserDefaults using these methods
- (id)getNSCodingObjectForKey: (NSString *)key;
- (BOOL)setNSCodingObject: (id)object forKey: (NSString *)key;

// convenience methods
- (UIColor *)colorForKey: (NSString *)key;
- (BOOL)setColor: (UIColor *)cValue forKey: (NSString *)key;

// store the image NSData in the key, use this method to create an image
- (UIImage *)imageForKey: (NSString *)key;

- (NSNumber *)numberForKey: (NSString *)key;
- (BOOL)setNumber: (NSNumber *)value forKey: (NSString *)key;

- (BOOL)removeKey: (NSString *)key;

// keychain methods
- (NSString *)getKeychainValueForKey: (NSString *)key
						   forSharer: (NSString *)sharerId
						 accessGroup: (NSString *)accessGroupOrNil
							   error: (NSError **)errorOrNil;

- (void)setKeychainValue: (NSString *)value
				  forKey: (NSString *)key 
			   forSharer: (NSString *)sharerId 
			 accessGroup: (NSString *)accessGroupOrNil 
				   error: (NSError **)errorOrNil;

- (void)removeKeychainValueForKey: (NSString *)key 
						forSharer: (NSString *)sharerId 
					  accessGroup: (NSString *)accessGroupOrNil 
							error: (NSError **)errorOrNil;

@end
