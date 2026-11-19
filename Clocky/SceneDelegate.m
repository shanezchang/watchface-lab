#import "SceneDelegate.h"
#import "FaceViewController.h"
#import "AppDelegate.h"

@implementation SceneDelegate

- (void)dealloc {
    [_window release];
    [super dealloc];
}

- (void)scene:(UIScene *)scene willConnectToSession:(UISceneSession *)session options:(UISceneConnectionOptions *)connectionOptions {
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        AppDelegate *delegate = (AppDelegate *)SPApplication.sharedSPApplication.delegate;
        SPExtensionConnection *connection = delegate.extensionConnection;
        if (connection == nil) {
            NSLog(@"WatchKit connection is unavailable during scene initialization");
            return;
        }
        SPCompanionLogger.sharedInstance.extensionConnection = connection;
        [connection didFinishLaunching:YES];
        SPRemoteInterface *remoteInterface = connection.inProcessRemoteInterface;
        remoteInterface.appClientIdentifier = connection.clientIdentifier;
        [remoteInterface performDidFinishLaunchingCompletions];
    });

    UIWindow *window = [[UIWindow alloc] initWithWindowScene:(UIWindowScene *)scene];

    FaceViewController *rootViewController = [[FaceViewController alloc] init];
    window.rootViewController = rootViewController;
    [rootViewController release];

    self.window = window;
    [window makeKeyAndVisible];
    [window release];
}

- (void)sceneDidBecomeActive:(UIScene *)scene {
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        AppDelegate *delegate = (AppDelegate *)SPApplication.sharedSPApplication.delegate;
        SPExtensionConnection *connection = delegate.extensionConnection;
        [connection didActivate];
        [connection.inProcessRemoteInterface performAfterApplicationDidFinishLaunching:^{}];
    });
}

- (void)sceneWillEnterForeground:(UIScene *)scene {
    AppDelegate *delegate = (AppDelegate *)SPApplication.sharedSPApplication.delegate;
    SPExtensionConnection *connection = delegate.extensionConnection;
    [connection appWillEnterForeground];
    connection.inProcessRemoteInterface.afterWillEnterForeground = YES;
    [connection.inProcessRemoteInterface performAfterApplicationDidFinishLaunching:^{}];
}

- (void)sceneDidEnterBackground:(UIScene *)scene {
    AppDelegate *delegate = (AppDelegate *)SPApplication.sharedSPApplication.delegate;
    SPExtensionConnection *connection = delegate.extensionConnection;
    [connection appWillEnterForeground];
    connection.inProcessRemoteInterface.afterWillEnterForeground = NO;
}

@end
