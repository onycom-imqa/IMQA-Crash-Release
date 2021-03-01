

#import <Foundation/Foundation.h>

@class IMQACrashStackframe;

/**
 * Denote which platform or runtime the Error occurred in.
 */
typedef NS_OPTIONS(NSUInteger, IQCErrorType) {
    IQCErrorTypeCocoa NS_SWIFT_NAME(cocoa), // Swift won't bring in the zeroeth option by default
    IQCErrorTypeC NS_SWIFT_NAME(c), // Fix Swift auto-capitalisation
    IQCErrorTypeReactNativeJs
};

/**
 * An Error represents information extracted from an NSError, NSException, or other error source.
 */
@interface IMQACrashError : NSObject

/**
 * The class of the error generating the report
 */
@property (copy, nullable, nonatomic) NSString *errorClass;

/**
 * The message of or reason for the error generating the report
 */
@property (copy, nullable, nonatomic) NSString *errorMessage;

/**
 * Sets a representation of this error's stacktrace
 */
@property (copy, nonnull, nonatomic) NSArray<IMQACrashStackframe *> *stacktrace;

/**
 * The type of the captured error
 */
@property IQCErrorType type;

@end
