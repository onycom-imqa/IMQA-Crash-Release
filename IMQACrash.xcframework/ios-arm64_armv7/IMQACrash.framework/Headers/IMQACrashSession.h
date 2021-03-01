

#import <Foundation/Foundation.h>

#import <IMQACrash/IMQACrashApp.h>
#import <IMQACrash/IMQACrashDevice.h>
#import <IMQACrash/IMQACrashUser.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * Represents a session of user interaction with your app.
 */
@interface IMQACrashSession : NSObject

@property (copy, nonatomic) NSString *id;

@property (strong, nonatomic) NSDate *startedAt;

@property (readonly, nonatomic) IMQACrashApp *app;

@property (readonly, nonatomic) IMQACrashDevice *device;

// =============================================================================
// MARK: - User
// =============================================================================

/**
 * The current user
 */
@property (readonly, nonnull, nonatomic) IMQACrashUser *user;

/**
 *  Set user metadata
 *
 *  @param userId ID of the user
 *  @param name   Name of the user
 *  @param email  Email address of the user
 */
- (void)setUser:(nullable NSString *)userId withEmail:(nullable NSString *)email andName:(nullable NSString *)name;

@end

NS_ASSUME_NONNULL_END
