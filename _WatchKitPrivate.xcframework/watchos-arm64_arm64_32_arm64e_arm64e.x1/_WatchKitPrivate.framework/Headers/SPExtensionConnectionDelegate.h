#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class SPExtensionConnection;

@protocol SPExtensionConnectionDelegate <NSObject>
@optional
- (void)extensionConnection:(SPExtensionConnection *)extensionConnection directXPCSetupDidFailWithError:(NSError *)error;
- (void)extensionConnectionApplicationDidEndSuspendedLaunch:(SPExtensionConnection *)extensionConnection;
@end

NS_ASSUME_NONNULL_END
