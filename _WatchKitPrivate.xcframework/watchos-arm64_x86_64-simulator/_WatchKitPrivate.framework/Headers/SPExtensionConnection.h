#import <Foundation/Foundation.h>
#import <_WatchKitPrivate/SPExtensionConnectionDelegate.h>

NS_ASSUME_NONNULL_BEGIN

@class SPRemoteInterface;

@interface SPExtensionConnection : NSObject
@property (nullable, nonatomic, assign) id<SPExtensionConnectionDelegate> delegate;
@property (nonatomic) BOOL inSuspendedLaunch;
@property (nonatomic, readonly) NSString *clientIdentifier;
@property (nonatomic, readonly) SPRemoteInterface *inProcessRemoteInterface;
- (void)setUpNativeAppWithServerIdentifer:(NSString *)identifier;
- (void)connectWithIdentifier:(NSString *)identifier completion:(void (^)(void))completion;
- (void)didFinishLaunching:(BOOL)success;
- (void)didActivate;
- (void)appWillEnterForeground;
- (nullable NSObject *)extendLaunchTest;
@end

NS_ASSUME_NONNULL_END
