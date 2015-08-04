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
 * Name:		S4FileProgressDownloader.h
 * Module:		Network
 * Library:		S4 iOS Libraries
 *
 * ***** FILE BLOCK *****/


// ================================== Includes =========================================

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "S4HttpConnection.h"


// =================================== Defines =========================================



// ================================== Typedefs =========================================

typedef enum
{
	UndeterminedViewType		= 0,
	ActivityIndicatorViewType	= 1,
	ProgressViewType			= 2
} S4FileDownloaderUIViewType;


// ================================== Globals =========================================



// ============================= Forward Declarations =================================

@class S4FileProgressDownloader;


// ================================== Protocols ========================================

@protocol S4FileProgressLoaderDelegate <NSObject>

@required
- (void)downloader: (S4FileProgressDownloader *)progressDownloader startedDownloadOfFile: (NSString *)fileName;
- (void)downloader: (S4FileProgressDownloader *)progressDownloader updatedProgressForFile: (NSString *)fileName atPercentage: (float)percentDownloaded;
- (void)downloader: (S4FileProgressDownloader *)progressDownloader completedDownloadOfFile: (NSString *)fileName;
- (void)downloader: (S4FileProgressDownloader *)progressDownloader didFailForFile: (NSString *)fileName withError: (NSError *)error;

@optional
- (void)downloader: (S4FileProgressDownloader *)progressDownloader usingUpdateViewOfType: (S4FileDownloaderUIViewType)type;

@end



// ========================== S4FileProgressDownloader Class ===========================

@interface S4FileProgressDownloader : NSObject <S4HttpConnectionDelegate>
{
}

@property (nonatomic, strong) UIActivityIndicatorView					*activityIndicatorView;
@property (nonatomic, strong) UIProgressView							*progressView;


- (BOOL)downloadFile: (NSString *)fileName
			  toPath: (NSString *)dstFilePath
		  fromURLStr: (NSString *)urlStr
		 forDelegate: (NSObject <S4FileProgressLoaderDelegate> *)delegate
		  useTmpFile: (BOOL)bUseTmpFile;

- (void)httpConnection: (S4HttpConnection *)connection failedWithError: (NSError *)error;
- (void)httpConnection: (S4HttpConnection *)connection completedWithData: (NSMutableData *)data;
- (BOOL)httpConnection: (S4HttpConnection *)connection receivedData: (NSData *)data;

@end
