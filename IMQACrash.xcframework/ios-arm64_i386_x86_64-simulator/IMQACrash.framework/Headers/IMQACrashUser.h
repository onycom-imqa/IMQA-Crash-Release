

#import <Foundation/Foundation.h>

/**
 * Information about the current user of your application.
 */
@interface IMQACrashUser : NSObject

@property (readonly, nullable, nonatomic) NSString *id;

@property (readonly, nullable, nonatomic) NSString *name;

@property (readonly, nullable, nonatomic) NSString *email;

@end
