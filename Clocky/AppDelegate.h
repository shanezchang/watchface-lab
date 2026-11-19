#import <_UIKitPrivate/_UIKitPrivate.h>
#import <_WatchKitPrivate/_WatchKitPrivate.h>

NS_ASSUME_NONNULL_BEGIN

@interface AppDelegate : UIResponder <UIApplicationDelegate, SPExtensionConnectionDelegate>
@property (nullable, nonatomic, retain, readonly) SPExtensionConnection *extensionConnection;
@end

NS_ASSUME_NONNULL_END
