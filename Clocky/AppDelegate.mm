#import "AppDelegate.h"
#import "SceneDelegate.h"
#import "Swizzler.h"

@interface AppDelegate ()
@property (nonatomic) BOOL hasReceivedNonClockKitEvent;
@property (nonatomic) BOOL launchedSuspendedNotInDock;
@property (nullable, nonatomic, retain, readwrite) SPExtensionConnection *extensionConnection;
@end

@implementation AppDelegate

+ (void)load {
    swizzler::NTKFaceDescriptor::isAvailableForDevice::swizzle();
    swizzler::NTKFace::isRestrictedForDevice::swizzle();
}

- (void)dealloc {
    _extensionConnection.delegate = nil;
    [_extensionConnection release];
    [super dealloc];
}

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary<UIApplicationLaunchOptionsKey,id> * _Nullable)launchOptions {
    NSString *bundleIdentifier = NSBundle.mainBundle.bundleIdentifier;
    if (bundleIdentifier == nil) {
        NSLog(@"Cannot initialize the WatchKit connection without a bundle identifier");
        return NO;
    }
    SPExtensionConnection *connection = [[SPExtensionConnection alloc] init];
    connection.delegate = self;
    connection.inSuspendedLaunch = YES;
    [connection setUpNativeAppWithServerIdentifer:bundleIdentifier];
    self.extensionConnection = connection;
    [connection release];

    NSURL *scCacheURL = [[NSFileManager.defaultManager URLsForDirectory:NSLibraryDirectory inDomains:NSUserDomainMask].firstObject URLByAppendingPathComponent:@"Saved Application State" isDirectory:YES];
    [NSFileManager.defaultManager removeItemAtURL:scCacheURL error:NULL];

    return YES;
}

- (UISceneConfiguration *)application:(UIApplication *)application configurationForConnectingSceneSession:(UISceneSession *)connectingSceneSession options:(UISceneConnectionOptions *)options {
    UISceneConfiguration *configuration = [connectingSceneSession.configuration copy];
    configuration.delegateClass = [SceneDelegate class];
    return [configuration autorelease];
}

- (void)applicationDidBecomeActive:(UIApplication *)application {
    // noop
}

- (void)applicationWillEnterForeground:(UIApplication *)application {
    // noop
}

- (void)didReceiveNonClockKitEvent {
    NSString * _Nullable identifier = NSBundle.mainBundle.bundleIdentifier;
    if (identifier == nil || self.extensionConnection == nil) {
        NSLog(@"Cannot connect the WatchKit extension");
        return;
    }
    [self.extensionConnection connectWithIdentifier:identifier completion:^{}];
}

- (id _Nullable)extendLaunchTest {
    return [self.extensionConnection extendLaunchTest];
}

- (void)applicationWillSuspend:(UIApplication *)application {
    // noop
}

- (UIWindow * _Nullable)window {
    return nil;
}

- (void)handleWatchActions:(NSSet<NSObject *> *)watchActions completion:(void (^)(void))completion {
    completion();
}

- (void)extensionConnection:(SPExtensionConnection *)extensionConnection directXPCSetupDidFailWithError:(NSError *)error {
    NSLog(@"WatchKit connection setup failed: %@", error);
}

- (void)extensionConnectionApplicationDidEndSuspendedLaunch:(SPExtensionConnection *)extensionConnection {
    // noop
}

@end
