#import <Cordova/CDV.h>

@interface LucenePlugin : CDVPlugin

- (void)searchIndex:(CDVInvokedUrlCommand*)command;

@end
