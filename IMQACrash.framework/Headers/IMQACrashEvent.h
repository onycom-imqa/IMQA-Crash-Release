//
//  IMQACrashEvent.h
//  IMQACrash
//
//  Created by Simon Maynard on 11/26/14.
//
//

#import <Foundation/Foundation.h>

#import <IMQACrash/IMQACrashMetadataStore.h>

@class IMQACrashConfiguration;
@class IMQACrashHandledState;
@class IMQACrashSession;
@class IMQACrashBreadcrumb;
@class IMQACrashAppWithState;
@class IMQACrashDeviceWithState;
@class IMQACrashMetadata;
@class IMQACrashThread;
@class IMQACrashError;
@class IMQACrashUser;

/**
 * Represents the importance of a particular event.
 */
typedef NS_ENUM(NSUInteger, IQCSeverity) {
    IQCSeverityError,
    IQCSeverityWarning,
    IQCSeverityInfo,
};

/**
 * Represents an occurrence of an error, along with information about the state of the app and device.
 */
@interface IMQACrashEvent : NSObject <IMQACrashMetadataStore>

// -----------------------------------------------------------------------------
// MARK: - Properties
// -----------------------------------------------------------------------------

/**
 *  A loose representation of what was happening in the application at the time
 *  of the event
 */
@property(readwrite, copy, nullable) NSString *context;

/**
 *  The severity of the error generating the report
 */
@property(readwrite) IQCSeverity severity;

/**
 * Information extracted from the error that caused the event. The list contains
 * at least one error that represents the root cause, with subsequent elements populated
 * from the cause.
 */
@property(readwrite, copy, nonnull) NSArray<IMQACrashError *> *errors;

/**
 *  Customized hash for grouping this report with other errors
 */
@property(readwrite, copy, nullable) NSString *groupingHash;
/**
 *  Breadcrumbs from user events leading up to the error
 */
@property(readwrite, copy, nonnull) NSArray<IMQACrashBreadcrumb *> *breadcrumbs;

/**
 * A per-event override for the apiKey.
 * - The default value of nil results in the IMQACrashConfiguration apiKey being used.
 * - Writes are not persisted to IMQACrashConfiguration.
 */
@property(readwrite, copy, nullable, nonatomic) NSString *apiKey;

/**
 *  Device information such as OS name and version
 */
@property(readonly, nonnull) IMQACrashDeviceWithState *device;

/**
 *  App information such as the name, version, and bundle ID
 */
@property(readonly, nonnull) IMQACrashAppWithState *app;

/**
 * Whether the event was a crash (i.e. unhandled) or handled error in which the system
 * continued running.
 */
@property(readwrite) BOOL unhandled;

/**
 * Thread traces for the error that occurred, if collection was enabled.
 */
@property(readwrite, copy, nonnull) NSArray<IMQACrashThread *> *threads;

/**
 * The original object that caused the error in your application. This value will only be populated for
 * non-fatal errors which did not terminate the process, and will contain an NSError or NSException.
 *
 * Manipulating this field does not affect the error information reported to the
 * IMQACrash dashboard. Use event.errors to access and amend the representation of
 * the error that will be sent.
 */
@property(strong, nullable, nonatomic) id originalError;


// =============================================================================
// MARK: - User
// =============================================================================

/**
 * The current user
 */
@property(readonly, nonatomic, nonnull) IMQACrashUser *user;

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

@end
