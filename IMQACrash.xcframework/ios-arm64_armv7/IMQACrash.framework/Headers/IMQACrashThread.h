

#import <Foundation/Foundation.h>

typedef NS_OPTIONS(NSUInteger, IQCThreadType) {
    IQCThreadTypeCocoa NS_SWIFT_NAME(cocoa) = 0,
    IQCThreadTypeReactNativeJs = 1 << 1
};

@class IMQACrashStackframe;

/**
 * A representation of thread information recorded as part of a IMQACrashEvent.
 */
@interface IMQACrashThread : NSObject

/**
 * A unique ID which identifies this thread
 */
@property (copy, nullable, nonatomic) NSString *id;

/**
 * The name which identifies this thread
 */
@property (copy, nullable, nonatomic) NSString *name;

/**
 * Whether the error being reported happened in this thread
 */
@property (readonly, nonatomic) BOOL errorReportingThread;

/**
 * Sets a representation of this thread's stacktrace
 */
@property (copy, nonnull, nonatomic) NSArray<IMQACrashStackframe *> *stacktrace;

/**
 * Determines the type of thread based on the originating platform
 * (intended for internal use only)
 */
@property IQCThreadType type;

@end
