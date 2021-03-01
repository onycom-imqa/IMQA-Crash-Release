
#import <Foundation/Foundation.h>

#import <IMQACrash/IQC_KSCrashReportWriter.h>
#import <IMQACrash/IMQACrashBreadcrumb.h>
#import <IMQACrash/IMQACrashEvent.h>
#import <IMQACrash/IMQACrashMetadata.h>
#import <IMQACrash/IMQACrashMetadataStore.h>
#import <IMQACrash/IMQACrashPlugin.h>

@class IMQACrashUser;
@class IMQACrashEndpointConfiguration;
@class IMQACrashErrorTypes;

NS_ASSUME_NONNULL_BEGIN

/**
 * Controls whether IMQACrash should capture and serialize the state of all threads at the time
 * of an error.
 */
typedef NS_ENUM(NSInteger, IQCThreadSendPolicy) {

    /**
     * Threads should be captured for all events.
     */
    IQCThreadSendPolicyAlways = 0,

    /**
     * Threads should be captured for unhandled events only.
     */
    IQCThreadSendPolicyUnhandledOnly = 1,

    /**
     * Threads should never be captured.
     */
    IQCThreadSendPolicyNever = 2
};

/**
 *  A configuration block for modifying an error report
 *
 *  @param event the error report to be modified
 */
typedef BOOL (^IMQACrashOnErrorBlock)(IMQACrashEvent *_Nonnull event);

/**
 *  A handler for modifying data before sending it to IMQACrash.
 *
 * onSendErrorBlocks will be invoked on a dedicated
 * background queue, which will be different from the queue where the block was originally added.
 *
 *  @param event The event report.
 *
 *  @return YES if the event should be sent
 */
typedef BOOL (^IMQACrashOnSendErrorBlock)(IMQACrashEvent *_Nonnull event);

/**
 *  A configuration block for modifying a captured breadcrumb
 *
 *  @param breadcrumb The breadcrumb
 */
typedef BOOL (^IMQACrashOnBreadcrumbBlock)(IMQACrashBreadcrumb *_Nonnull breadcrumb);

/**
 * A configuration block for modifying a session. Intended for internal usage only.
 *
 * @param session The session about to be delivered
 */
typedef BOOL (^IMQACrashOnSessionBlock)(IMQACrashSession *_Nonnull session);

// =============================================================================
// MARK: - IMQACrashConfiguration
// =============================================================================

/**
 * Contains user-provided configuration, including API key and endpoints.
 */
@interface IMQACrashConfiguration : NSObject <IMQACrashMetadataStore>

/**
 * Create a new configuration from the main bundle's infoDictionary, using keys nested under
 * the "IMQACrash" key.
 *
 * @return a IMQACrashConfiguration containing the options set in the plist file
 */
+ (instancetype)loadConfig;

/**
 * Initializes a new configuration object with the provided API key.
 */
- (instancetype)initWithApiKey:(nullable NSString *)apiKey NS_DESIGNATED_INITIALIZER NS_SWIFT_NAME(init(_:));

/**
 * Required declaration to suppress a superclass designated-initializer error
 */
- (instancetype)init NS_UNAVAILABLE NS_SWIFT_UNAVAILABLE("Use initWithApiKey:");

// -----------------------------------------------------------------------------
// MARK: - Properties
// -----------------------------------------------------------------------------

/**
 *  The API key of a IMQACrash project
 */
@property (copy, nonatomic) NSString *apiKey;

/**
 *  The release stage of the application, such as production, development, beta
 *  et cetera
 */
@property (copy, nullable, nonatomic) NSString *releaseStage;

/**
 *  Release stages which are allowed to notify IMQACrash
 */
@property (copy, nullable, nonatomic) NSSet<NSString *> *enabledReleaseStages;

/**
 * Sets which values should be removed from any Metadata objects before
 * sending them to IMQACrash. Use this if you want to ensure you don't send
 * sensitive data such as passwords, and credit card numbers to our
 * servers. Any keys which contain a match will be filtered.
 *
 * By default, redactedKeys is set to ["password"]. Both string literals and regex
 * values can be supplied to this property.
 */
@property (copy, nullable, nonatomic) NSSet<id> *redactedKeys;

/**
 * A set of strings and / or NSRegularExpression objects that determine which errors should
 * be discarded based on their `errorClass`.
 *
 * Comparisons are case sensitive.
 *
 * OnError / OnSendError blocks will not be called for discarded errors.
 *
 * Some examples of errorClass are: Objective-C exception names like "NSRangeException",
 * signal names like "SIGABRT", mach exception names like "EXC_BREAKPOINT", and Swift
 * error names like "Fatal error".
 */
@property (copy, nullable, nonatomic) NSSet<id> *discardClasses;

/**
 *  A general summary of what was occuring in the application
 */
@property (copy, nullable, nonatomic) NSString *context;

/**
 *  The version of the application
 */
@property (copy, nullable, nonatomic) NSString *appVersion;

/**
 *  The URL session used to send requests to IMQACrash.
 */
@property(readwrite, strong, nonnull) NSURLSession *session;

/**
 * Controls whether IMQACrash should capture and serialize the state of all threads at the time
 * of an error.
 *
 * By default sendThreads is set to IQCThreadSendPolicyAlways. This can be set to
 * IQCThreadSendPolicyNever to disable or IQCThreadSendPolicyUnhandledOnly
 * to only do so for unhandled errors.
 */
@property IQCThreadSendPolicy sendThreads;

/**
 *  Optional handler invoked when an error or crash occurs
 */
@property void (*_Nullable onCrashHandler)
    (const IQC_KSCrashReportWriter *_Nonnull writer);

/**
 *  YES if uncaught exceptions and other crashes should be reported automatically
 */
@property BOOL autoDetectErrors;

/**
 * Determines whether app sessions should be tracked automatically. By default this value is true.
 * If this value is updated after +[IMQACrash start] is called, only subsequent automatic sessions
 * will be captured.
 */
@property BOOL autoTrackSessions;

/**
 * The types of breadcrumbs which will be captured. By default, this is all types.
 */
@property IQCEnabledBreadcrumbType enabledBreadcrumbTypes;

/**
 * The app's bundleVersion, set from the CFBundleVersion.  Equivalent to `versionCode` on Android.
 */
@property (copy, nullable, nonatomic) NSString *bundleVersion;

@property (copy, nullable, nonatomic) NSString *appType;

/**
 * Sets the maximum number of events which will be stored. Once the threshold is reached,
 * the oldest events will be deleted.
 *
 * By default, 32 events are persisted.
 */
@property (nonatomic) NSUInteger maxPersistedEvents;

/**
 * Sets the maximum number of sessions which will be stored. Once the threshold is reached,
 * the oldest sessions will be deleted.
 *
 * By default, 128 sessions are persisted.
 */
@property (nonatomic) NSUInteger maxPersistedSessions;

/**
 * Sets the maximum number of breadcrumbs which will be stored. Once the threshold is reached,
 * the oldest breadcrumbs will be deleted.
 *
 * By default, 25 breadcrumbs are stored: this can be amended up to a maximum of 100.
 */
@property NSUInteger maxBreadcrumbs;

/**
 * Whether User information should be persisted to disk between application runs.
 * Defaults to True.
 */
@property BOOL persistUser;

// -----------------------------------------------------------------------------
// MARK: - Methods
// -----------------------------------------------------------------------------

/**
 * A class defining the types of error that are reported. By default,
 * all properties are true.
 */
@property (strong, nonatomic) IMQACrashErrorTypes *enabledErrorTypes;

/**
 * Please note that it is recommended that you set both endpoints. If the notify endpoint is
 * missing, an assertion will be thrown. If the session endpoint is missing, a warning will be
 * logged and sessions will not be sent automatically.
 */
@property (strong, nonatomic) IMQACrashEndpointConfiguration *endpoints;

// =============================================================================
// MARK: - User
// =============================================================================

/**
 * The current user
 */
@property(readonly, retain, nonnull, nonatomic) IMQACrashUser *user;

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
// MARK: - onSession
// =============================================================================

/**
 *  Add a callback to be invoked before a session is sent to IMQACrash.
 *
 *  @param block A block which can modify the session
 */
- (void)addOnSessionBlock:(IMQACrashOnSessionBlock _Nonnull)block
    NS_SWIFT_NAME(addOnSession(block:));

/**
 * Remove a callback that would be invoked before a session is sent to IMQACrash.
 *
 * @param block The block to be removed.
 */
- (void)removeOnSessionBlock:(IMQACrashOnSessionBlock _Nonnull)block
    NS_SWIFT_NAME(removeOnSession(block:));

// =============================================================================
// MARK: - onSend
// =============================================================================

/**
 *  Add a callback to be invoked before a report is sent to IMQACrash, to
 *  change the report contents as needed
 *
 *  @param block A block which returns YES if the report should be sent
 */
- (void)addOnSendErrorBlock:(IMQACrashOnSendErrorBlock _Nonnull)block
    NS_SWIFT_NAME(addOnSendError(block:));

/**
 * Remove the callback that would be invoked before an event is sent.
 *
 * @param block The block to be removed.
 */
- (void)removeOnSendErrorBlock:(IMQACrashOnSendErrorBlock _Nonnull)block
    NS_SWIFT_NAME(removeOnSendError(block:));

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

- (void)addPlugin:(id<IMQACrashPlugin> _Nonnull)plugin;

@end

NS_ASSUME_NONNULL_END
