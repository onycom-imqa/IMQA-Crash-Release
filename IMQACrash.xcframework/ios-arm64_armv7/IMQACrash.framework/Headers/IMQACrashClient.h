

#import <Foundation/Foundation.h>

#import <IMQACrash/IMQACrashConfiguration.h>
#import <IMQACrash/IMQACrashMetadata.h>
#import <IMQACrash/IMQACrashMetadataStore.h>

@class IMQACrashSessionTracker;

/**
 * The IMQACrashClient is not intended to be used directly.
 * 
 * Use the static access provided by the IMQACrash class instead.
 */
@interface IMQACrashClient : NSObject<IMQACrashMetadataStore>

/**
 * Initializes the client with the provided configuration.
 */
- (instancetype _Nonnull)initWithConfiguration:(IMQACrashConfiguration *_Nonnull)configuration;

// =============================================================================
// MARK: - Notify
// =============================================================================

/** Send a custom or caught exception to IMQACrash.
 *
 * The exception will be sent to IMQACrash in the background allowing your
 * app to continue running.
 *
 * @param exception  The exception.
 */
- (void)notify:(NSException *_Nonnull)exception;

/**
 *  Send a custom or caught exception to IMQACrash
 *
 *  @param exception The exception
 *  @param block     A block for optionally configuring the error report
 */
- (void)notify:(NSException *_Nonnull)exception
         block:(IMQACrashOnErrorBlock _Nullable)block;

/**
 *  Send an error to IMQACrash
 *
 *  @param error The error
 */
- (void)notifyError:(NSError *_Nonnull)error;

/**
 *  Send an error to IMQACrash
 *
 *  @param error The error
 *  @param block A block for optionally configuring the error report
 */
- (void)notifyError:(NSError *_Nonnull)error
              block:(IMQACrashOnErrorBlock _Nullable)block;

// =============================================================================
// MARK: - Breadcrumbs
// =============================================================================

/**
 * Leave a "breadcrumb" log message, representing an action that occurred
 * in your app, to aid with debugging.
 *
 * @param message  the log message to leave
 */
- (void)leaveBreadcrumbWithMessage:(NSString *_Nonnull)message;

/**
 *  Leave a "breadcrumb" log message each time a notification with a provided
 *  name is received by the application
 *
 *  @param notificationName name of the notification to capture
 */
- (void)leaveBreadcrumbForNotificationName:(NSString *_Nonnull)notificationName;

/**
 * Leave a "breadcrumb" log message, representing an action that occurred
 * in your app, to aid with debugging, along with additional metadata and
 * a type.
 *
 * @param message The log message to leave.
 * @param metadata Additional metadata included with the breadcrumb.
 * @param type A IQCBreadcrumbTypeValue denoting the type of breadcrumb.
 */
- (void)leaveBreadcrumbWithMessage:(NSString *_Nonnull)message
                          metadata:(NSDictionary *_Nullable)metadata
                           andType:(IQCBreadcrumbType)type
NS_SWIFT_NAME(leaveBreadcrumb(_:metadata:type:));

// =============================================================================
// MARK: - Session
// =============================================================================

/**
 * Starts tracking a new session.
 *
 * By default, sessions are automatically started when the application enters the foreground.
 * If you wish to manually call startSession at
 * the appropriate time in your application instead, the default behaviour can be disabled via
 * autoTrackSessions.
 *
 * Any errors which occur in an active session count towards your application's
 * stability score. You can prevent errors from counting towards your stability
 * score by calling pauseSession and resumeSession at the appropriate
 * time in your application.
 *
 * @see pauseSession:
 * @see resumeSession:
 */
- (void)startSession;

/**
 * Stops tracking a session.
 *
 * When a session is stopped, errors will not count towards your application's
 * stability score. This can be advantageous if you do not wish these calculations to
 * include a certain type of error, for example, a crash in a background service.
 * You should disable automatic session tracking via autoTrackSessions if you call this method.
 *
 * A stopped session can be resumed by calling resumeSession,
 * which will make any subsequent errors count towards your application's
 * stability score. Alternatively, an entirely new session can be created by calling startSession.
 *
 * @see startSession:
 * @see resumeSession:
 */
- (void)pauseSession;

/**
 * Resumes a session which has previously been stopped, or starts a new session if none exists.
 *
 * If a session has already been resumed or started and has not been stopped, calling this
 * method will have no effect. You should disable automatic session tracking via
 * autoTrackSessions if you call this method.
 *
 * It's important to note that sessions are stored in memory for the lifetime of the
 * application process and are not persisted on disk. Therefore calling this method on app
 * startup would start a new session, rather than continuing any previous session.
 *
 * You should call this at the appropriate time in your application when you wish to
 * resume a previously started session. Any subsequent errors which occur in your application
 * will be reported to IMQACrash and will count towards your application's stability score.
 *
 * @see startSession:
 * @see pauseSession:
 *
 * @return true if a previous session was resumed, false if a new session was started.
 */
- (BOOL)resumeSession;

// =============================================================================
// MARK: - onSession
// =============================================================================

/**
* Add a callback that would be invoked before a session is sent to IMQACrash.
*
* @param block The block to be added.
*/
- (void)addOnSessionBlock:(IMQACrashOnSessionBlock _Nonnull)block
    NS_SWIFT_NAME(addOnSession(block:));

/**
 * Remove a callback that would be invoked before a session is sent to IMQACrash.
 *
 * @param block The block to be removed.
 */
- (void)removeOnSessionBlock:(IMQACrashOnSessionBlock _Nonnull )block
    NS_SWIFT_NAME(removeOnSession(block:));

// =============================================================================
// MARK: - Other methods
// =============================================================================

/**
 * Retrieves the context - a general summary of what was happening in the application
 */
 @property (copy, nullable) NSString *context;

/**
 * @return YES if IMQACrash has been started and the previous launch crashed
 */
- (BOOL)appDidCrashLastLaunch;

// =============================================================================
// MARK: - User
// =============================================================================

/**
 * The current user
 */
- (IMQACrashUser *_Nonnull)user;

/**
 *  Set user metadata
 *
 *  @param userId ID of the user
 *  @param name   Name of the user
 *  @param email  Email address of the user
 */
- (void)setUser:(NSString *_Nullable)userId
      withEmail:(NSString *_Nullable)email
        andName:(NSString *_Nullable)name;

// =============================================================================
// MARK: - onBreadcrumb
// =============================================================================

/**
 *  Add a callback to be invoked when a breadcrumb is captured by IMQACrash, to
 *  change the breadcrumb contents as needed
 *
 *  @param block A block which returns YES if the breadcrumb should be captured
 */
- (void)addOnBreadcrumbBlock:(IMQACrashOnBreadcrumbBlock _Nonnull)block
    NS_SWIFT_NAME(addOnBreadcrumb(block:));

/**
 * Remove the callback that would be invoked when a breadcrumb is captured.
 *
 * @param block The block to be removed.
 */
- (void)removeOnBreadcrumbBlock:(IMQACrashOnBreadcrumbBlock _Nonnull)block
    NS_SWIFT_NAME(removeOnBreadcrumb(block:));

@end
