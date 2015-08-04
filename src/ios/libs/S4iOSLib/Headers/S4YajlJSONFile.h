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
 * All software created by the Initial Developer are Copyright (C) 2008-2012
 * the Initial Developer. All Rights Reserved.
 *
 * Original Author:
 *			Michael Papp, San Francisco, CA, USA
 *
 * ***** END LICENSE BLOCK ***** */

/* ***** FILE BLOCK ******
 *
 * Name:		S4YajlJSONFile.h
 * Module:		Data
 * Library:		S4 iOS Libraries
 *
 * ***** FILE BLOCK *****/


// ================================== Includes =========================================

#import <Foundation/Foundation.h>
#import "S4JSONFile.h"
#import "S4JSONParser.h"
#import "S4HttpConnection.h"


// =================================== Defines =========================================



// ================================== Typedefs =========================================



// =================================== Globals =========================================



// ============================= Forward Declarations ==================================



// ================================== Protocols ========================================



// ============================== Class S4YajlJSONFile =================================

@interface S4YajlJSONFile : S4JSONFile <S4JSONParserDelegate, S4HttpConnectionDelegate>
{
}

// Properties

// Class methods

// Instance methods
- (id)initWithParserOptions: (S4JSONParserOptions)parserOptions;

- (S4JSONParserError)parseData: (NSData *)data error: (NSError **)error;

- (BOOL)requestJSONfromURLStr: (NSString *)urlStr
				  forDelegate: (NSObject <S4JSONFileDelegate> *)delegate
					  timeout: (NSTimeInterval)requestTimeout
				  useWebCache: (BOOL)bUseCache
				queuePriority: (NSOperationQueuePriority)priority
			useAsyncCallbacks: (BOOL)useAsync;

- (BOOL)parseJSONfromFilePath: (NSString *)pathStr
				  forDelegate: (NSObject <S4JSONFileDelegate> *)delegate
				queuePriority: (NSOperationQueuePriority)priority
			useAsyncCallbacks: (BOOL)useAsync;

@end
