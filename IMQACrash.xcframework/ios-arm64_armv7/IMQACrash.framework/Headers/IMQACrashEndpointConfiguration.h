

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * Set the endpoints to send data to. 
 */
@interface IMQACrashEndpointConfiguration : NSObject

/**
 * Configures the endpoint to which events should be sent
 */
@property (copy, nonatomic) NSString *notify;

/**
 * Configures the endpoint to which sessions should be sent
 */
@property (copy, nonatomic) NSString *sessions;

- (instancetype)initWithNotify:(NSString *)notify
                      sessions:(NSString *)sessions;

@end

NS_ASSUME_NONNULL_END
