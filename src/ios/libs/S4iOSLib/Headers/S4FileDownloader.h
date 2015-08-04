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
 * Name:		S4FileDownloader.h
 * Module:		UI
 * Library:		S4 iOS Libraries
 *
 * ***** FILE BLOCK *****/


// ================================== Includes =========================================

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "S4CommonDefines.h"


// =================================== Defines =========================================



// ================================== Typedefs =========================================

typedef enum
{
	S4FileDownloaderNoError					= 0,
	S4FileDownloaderInvalidDataError		= 1,
	S4FileDownloaderAllocationError			= 2,
	S4FileDownloaderInvalidImageError		= 3,
	S4FileDownloaderUnknownError			= 4
} S4FileDownloaderError;


// =================================== Globals =========================================

S4_EXTERN_CONSTANT_NSSTR				S4ImageDownloaderErrorDomain;


// ============================= Forward Declarations ==================================

@class S4FileDownloader;


// ================================== Protocols ========================================

@protocol S4FileDownloaderDelegate <NSObject>

@required
// Called by the parser when parsing has begun
- (void)fileDownloader: (S4FileDownloader *)downloader
  completedForNumBytes: (NSNumber *)bytesRead
			   context: (id)userObject;

@optional
// Called by downloader as chunks of the file are written
- (void)fileDownloader: (S4FileDownloader *)downloader
	 percentDownloaded: (NSNumber *)percent
			   context: (id)userObject;

// Called by the retriever in the case of an error
- (void)fileDownloader: (S4FileDownloader *)downloader
	  didFailWithError: (NSError *)error
			   context: (id)userObject;

@end


// =========================== Class S4FileDownloader ==================================

@interface S4FileDownloader : NSObject
{
}

// Properties
@property (readwrite, weak, nonatomic) NSOperationQueue			*operationQueue;
@property (readonly, copy, nonatomic) NSString					*urlString;

// Class methods
+ (id)downloaderForFileAtURL: (NSString *)urlStr
					  toPath: (NSString *)path
					fileName: (NSString *)name
				withDelegate: (NSObject <S4FileDownloaderDelegate> *)delegate
				  useTmpFile: (BOOL)bUseTmpFile
					 context: (id)userObject
		 usingOperationQueue: (NSOperationQueue *)queue;

// Instance methods
- (BOOL)downloadFileAtURL: (NSString *)urlStr
				   toPath: (NSString *)path
				 fileName: (NSString *)name
			 withDelegate: (NSObject <S4FileDownloaderDelegate> *)delegate
			   useTmpFile: (BOOL)bUseTmpFile
				  context: (id)userObject;

@end
