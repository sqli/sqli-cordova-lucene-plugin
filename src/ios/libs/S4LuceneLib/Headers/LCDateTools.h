#ifndef __LUCENE_DOCUMENT_DATE_TOOLS__
#define __LUCENE_DOCUMENT_DATE_TOOLS__

#include <Foundation/Foundation.h>

/** Define the resolution of data to be stored */
typedef enum _LCResolution {
	LCResolution_YEAR = 1,
	LCResolution_MONTH,
	LCResolution_DAY,
	LCResolution_HOUR,
	LCResolution_MINUTE,
	LCResolution_SECOND,
	LCResolution_MILLISECOND
} LCResolution;

/** Convert between NSString and NSDate */
@interface NSString (LuceneKit_Document_Date)

/** Convert a NSDate to NSString in GMT with resolution */
+ (id)stringWithCalendarDate: (NSDate *)date resolution: (LCResolution)resolution;

/** Convert a NSString to NSTimeInterval */
- (NSTimeInterval)timeIntervalSince1970;

/** Convert a NSString in GMT to NSDate */
- (NSDate *)calendarDate;

@end


/** NSCalendarData with resolution */
@interface NSDate (LuceneKit_Document_Date)

/** Convert NSCalendarData to resolution */
- (NSDate *)dateWithResolution: (LCResolution) resolution;

/** Convert NSTimeInterval to resolution */
- (NSTimeInterval)timeIntervalSince1970WithResolution: (LCResolution)resolution;
@end

#endif /* __LUCENE_DOCUMENT_DATE_TOOLS__ */

