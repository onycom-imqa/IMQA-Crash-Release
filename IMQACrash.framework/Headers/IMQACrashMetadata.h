
#import <Foundation/Foundation.h>

#import <IMQACrash/IMQACrashMetadataStore.h>

/// :nodoc:
@interface IMQACrashMetadata : NSObject <IMQACrashMetadataStore>
- (instancetype _Nonnull)initWithDictionary:(NSDictionary *_Nonnull)dict;
@end
