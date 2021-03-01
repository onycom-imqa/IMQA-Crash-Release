
#import <Foundation/Foundation.h>

#ifndef NS_DESIGNATED_INITIALIZER
#if __has_attribute(objc_designated_initializer)
#define NS_DESIGNATED_INITIALIZER __attribute__((objc_designated_initializer))
#else
#define NS_DESIGNATED_INITIALIZER
#endif
#endif

/**
 * Types of breadcrumbs
 */
typedef NS_ENUM(NSUInteger, IQCBreadcrumbType) {
    /**
     *  Any breadcrumb sent via IMQACrash.leaveBreadcrumb()
     */
    IQCBreadcrumbTypeManual,
    /**
     *  A call to IMQACrash.notify() (internal use only)
     */
    IQCBreadcrumbTypeError,
    /**
     *  A log message
     */
    IQCBreadcrumbTypeLog,
    /**
     *  A navigation action, such as pushing a view controller or dismissing an alert
     */
    IQCBreadcrumbTypeNavigation,
    /**
     *  A background process, such performing a database query
     */
    IQCBreadcrumbTypeProcess,
    /**
     *  A network request
     */
    IQCBreadcrumbTypeRequest,
    /**
     *  Change in application or view state
     */
    IQCBreadcrumbTypeState,
    /**
     *  A user event, such as authentication or control events
     */
    IQCBreadcrumbTypeUser,
};

/**
 * Types of breadcrumbs which can be reported
 */
typedef NS_OPTIONS(NSUInteger, IQCEnabledBreadcrumbType) {
    IQCEnabledBreadcrumbTypeNone       = 0,
    IQCEnabledBreadcrumbTypeState      = 1 << 1,
    IQCEnabledBreadcrumbTypeUser       = 1 << 2,
    IQCEnabledBreadcrumbTypeLog        = 1 << 3,
    IQCEnabledBreadcrumbTypeNavigation = 1 << 4,
    IQCEnabledBreadcrumbTypeRequest    = 1 << 5,
    IQCEnabledBreadcrumbTypeProcess    = 1 << 6,
    IQCEnabledBreadcrumbTypeError      = 1 << 7,
    IQCEnabledBreadcrumbTypeAll = IQCEnabledBreadcrumbTypeState
                                | IQCEnabledBreadcrumbTypeUser
                                | IQCEnabledBreadcrumbTypeLog
                                | IQCEnabledBreadcrumbTypeNavigation
                                | IQCEnabledBreadcrumbTypeRequest
                                | IQCEnabledBreadcrumbTypeProcess
                                | IQCEnabledBreadcrumbTypeError,
};

/**
 * A short log message, representing an action that occurred in your app, to aid with debugging.
 */
@class IMQACrashBreadcrumb;

@interface IMQACrashBreadcrumb : NSObject

/**
 * The date when the breadcrumb was left
 */
@property(readonly, nullable) NSDate *timestamp;

/**
 * The type of breadcrumb
 */
@property(readwrite) IQCBreadcrumbType type;

/**
 * The description of the breadcrumb
 */
@property(readwrite, copy, nonnull) NSString *message;

/**
 * Diagnostic data relating to the breadcrumb.
 * 
 * The dictionary should be a valid JSON object.
 */
@property(readwrite, copy, nonnull) NSDictionary *metadata;

@end
