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
 * Name:		S4OperationsManager.h
 * Module:		Core
 * Library:		S4 iOS Libraries
 *
 * ***** FILE BLOCK *****/


// ================================== Includes =========================================

#import <Foundation/Foundation.h>
#import "S4OperationsHandler.h"


// =================================== Defines =========================================



// ================================== Typedefs =========================================



// =================================== Globals =========================================



// ============================= Forward Declarations ==================================



// ================================== Protocols ========================================



// =========================== Class S4OperationsManager ===============================

@interface S4OperationsManager : NSObject
{
}

//	Properties
@property (readwrite, assign, nonatomic) BOOL						networkQueueSuspended;
@property (readwrite, assign, nonatomic) BOOL						applicationQueueSuspended;
@property (readwrite, assign, nonatomic) NSInteger					networkQueueSize;
@property (readwrite, assign, nonatomic) NSInteger					applicationQueueSize;

//	Class methods
+ (S4OperationsManager *)getInstance;

//	Instance methods
- (BOOL)addBlockToNetworkQueue: (VoidNoArgsBlockType)block
				withMoreBlocks: (NSArray *)arrayOfBlocks
				 queuePriority: (NSOperationQueuePriority)priority
			   completionBlock: (VoidNoArgsBlockType)finishedBlock;

- (BOOL)addBlockToApplicationQueue: (VoidNoArgsBlockType)block
					withMoreBlocks: (NSArray *)arrayOfBlocks
					 queuePriority: (NSOperationQueuePriority)priority
				   completionBlock: (VoidNoArgsBlockType)finishedBlock;

// all arguments passed via array MUST be objects - will not handle primitive types
- (BOOL)addSelectorToNetworkQueue: (SEL)selector
						 onTarget: (id)target
					withArguments: (NSArray *)argArray
					queuePriority: (NSOperationQueuePriority)priority
				  completionBlock: (VoidNoArgsBlockType)finishedBlock;

- (BOOL)addSelectorToApplicationQueue: (SEL)selector
							 onTarget: (id)target
						withArguments: (NSArray *)argArray
						queuePriority: (NSOperationQueuePriority)priority
					  completionBlock: (VoidNoArgsBlockType)finishedBlock;

- (BOOL)addOperationToNetworkQueue: (NSOperation *)operation;
- (BOOL)addOperationToApplicationQueue: (NSOperation *)operation;

// network queue management
- (NSArray *)allNetworkOperations;
- (void)cancelAllNetworkOperations;
- (void)waitUntilNetworkQueueEmpties;

// application queue management
- (NSArray *)allApplicationOperations;
- (void)cancelAllApplicationOperations;
- (void)waitUntilApplicationQueueEmpties;

@end
