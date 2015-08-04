//
//  S4PropertiesDocument.h
//  IDG iPad Reader Applications
//
//  Created by Michael Papp on 10-24-2011
//  Copyright 2011-2012 Macworld Publishing Inc. All rights reserved.
//


#import <Foundation/Foundation.h>








@interface S4PropertiesDocument : NSObject <NSCoding>
{
}

// Properties
@property (readonly, strong, nonatomic) NSMutableDictionary			*propertiesDictionary;

// Class methods
+ (NSDate *)dateFromJsonString: (NSString *)dateString;

// Instance methods
- (id)initWithDictionary: (NSDictionary *)propsDictionary;
- (void)encodeWithCoder: (NSCoder *)encoder;
- (id)initWithCoder: (NSCoder *)decoder;
- (void)updatePropertiesFromDictionary: (NSDictionary *)propsDictionary fromFetch: (BOOL)wasFetched;

@end
