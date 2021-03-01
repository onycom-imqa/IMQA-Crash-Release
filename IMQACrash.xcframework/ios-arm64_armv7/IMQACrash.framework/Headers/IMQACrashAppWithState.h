
#import <Foundation/Foundation.h>

#import <IMQACrash/IMQACrashApp.h>

/**
 * Stateful information set by the notifier about your app can be found on this class. These values
 * can be accessed and amended if necessary.
 */
@interface IMQACrashAppWithState : IMQACrashApp

/**
 * The number of milliseconds the application was running before the event occurred
 */
@property (strong, nullable, nonatomic) NSNumber *duration;

/**
 * The number of milliseconds the application was running in the foreground before the
 * event occurred
 */
@property (strong, nullable, nonatomic) NSNumber *durationInForeground;

/**
 * Whether the application was in the foreground when the event occurred
 */
@property (nonatomic) BOOL inForeground;

@end
