#import "LucenePlugin.h"
#import "LCFSDirectory.h"
#import "LCIndexSearcher.h"
#import "LCTerm.h"
#import "LCTermQuery.h"
#import "LCHits.h"
#import "LCHit.h"
#import "LCHitIterator.h"
#import "LCTopDocs.h"
#import "LCScoreDoc.h"
#import <Cordova/CDV.h>

@implementation LucenePlugin

- (void)searchIndex:(CDVInvokedUrlCommand*)command
{
    CDVPluginResult* pluginResult = nil;
    NSDictionary* params = [command.arguments objectAtIndex:0];
    

    if (params != nil) {
        NSString* token = [params objectForKey:@"token"];
        NSString* field = [params objectForKey:@"field"];
        NSString* indexFolder = [params objectForKey:@"indexFolder"];
        NSNumber* maxResult = [params objectForKey:@"maxResult"];
        
        LCFSDirectory *rd = [[LCFSDirectory alloc] initWithPath: indexFolder create: NO];
        LCIndexSearcher *searcher = [[LCIndexSearcher alloc] initWithDirectory: rd];
        
        LCTerm *t = [[LCTerm alloc] initWithField: field text: token];
        
        LCTermQuery *tq = [[LCTermQuery alloc] initWithTerm: t];
        
        LCTopDocs *topDocs = [searcher searchQuery: tq filter:nil maximum:maxResult];
        NSArray *iterator = [topDocs scoreDocuments];
        
        
        NSMutableArray* docs =[[NSMutableArray alloc] init];
        
        for (LCScoreDoc *scoreDoc in iterator)
        {
            NSMutableDictionary* doc = [[NSMutableDictionary alloc] init];
            LCDocument* document = [searcher document:[scoreDoc document]];
            NSEnumerator *enumerator = [document fieldEnumerator];
            for (LCField *field in enumerator) {
                [doc setObject:[document stringForField: field.name] forKey:field.name];
            }
            
            [docs addObject:doc];
        }
        
        int nbHits = [topDocs totalHits];
        NSMutableDictionary* result = [[NSMutableDictionary alloc] init];
        [result setObject:[NSNumber numberWithInt:nbHits] forKey:@"nbHits"];
        [result setObject:docs forKey:@"docs"];
        
        pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsDictionary:result];
    } else {
        pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_ERROR];
    }
    
    [self.commandDelegate sendPluginResult:pluginResult callbackId:command.callbackId];
}

@end