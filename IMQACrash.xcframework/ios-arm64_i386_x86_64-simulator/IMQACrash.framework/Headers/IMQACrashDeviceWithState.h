

#import <Foundation/Foundation.h>

#import <IMQACrash/IMQACrashDevice.h>

/**
 * Stateful information set by the notifier about the device on which the event occurred can be
 * found on this class. These values can be accessed and amended if necessary.
 */
@interface IMQACrashDeviceWithState : IMQACrashDevice

/**
 * The number of free bytes of storage available on the device
 */
@property (strong, nullable, nonatomic) NSNumber *freeDisk;

/**
 * The number of free bytes of memory available on the device
 */
@property (strong, nullable, nonatomic) NSNumber *freeMemory;

/**
 * The orientation of the device when the event occurred
 */
@property (copy, nullable, nonatomic) NSString *orientation;

/**
 * The timestamp on the device when the event occurred
 */
@property (strong, nullable, nonatomic) NSDate *time;


@property (strong, nullable, nonatomic) NSNumber *memusable;
@property (strong, nullable, nonatomic) NSNumber *memtotal;
@property (strong, nullable, nonatomic) NSNumber *memfree;
@property (strong, nullable, nonatomic) NSString *cpuusage;


@end
