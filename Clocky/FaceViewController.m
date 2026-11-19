// Derived from Clocky 1.1.2. Modified for Watch Face Lab on 2026-11-19.
#import "FaceViewController.h"
#import "FaceBundleListViewController.h"
#import "Defines.h"
#import <NanoTimeKit/NanoTimeKit.h>

@interface FaceViewController () <FaceBundleListViewControllerDelegate>
@property (nullable, nonatomic, retain, direct) NTKFaceViewController *faceViewController;
@end

@implementation FaceViewController

- (void)dealloc {
    [_faceViewController release];
    [super dealloc];
}

- (BOOL)prefersStatusBarHidden {
    return YES;
}

- (void)viewDidLoad {
    [super viewDidLoad];
    self.view.backgroundColor = UIColor.systemBackgroundColor;
    [self showInitialFace];
    [self configureLongPressGesture];
}

- (void)showInitialFace __attribute__((objc_direct)) {
    CLKDevice *device = CLKDevice.currentDevice;
    [NSUserDefaults.standardUserDefaults registerDefaults:@{selectedFaceIdentifierKey(): @"com.apple.NTKZeusFaceBundle.NTKZeusAnalogFaceBundle"}];
    NSString * _Nullable selectedFaceIdentifier = [NSUserDefaults.standardUserDefaults stringForKey:selectedFaceIdentifierKey()];

    __block __kindof NTKFaceBundle * _Nullable firstBundle = nil;
    __block __kindof NTKFaceBundle * _Nullable matchedBundle = nil;

    [NTKFaceBundleManager.sharedManager enumerateFaceBundlesOnDevice:device includingLegacy:YES withBlock:^(__kindof NTKFaceBundle *faceBundle) {
        if (firstBundle == nil) {
            firstBundle = [faceBundle retain];
        }
        if (selectedFaceIdentifier != nil && matchedBundle == nil) {
            NSString * _Nullable identifier = [[faceBundle class] identifier];
            if ([identifier isEqualToString:selectedFaceIdentifier]) {
                matchedBundle = [faceBundle retain];
            }
        }
    }];

    __kindof NTKFaceBundle * _Nullable initialBundle = matchedBundle != nil ? matchedBundle : firstBundle;
    if (initialBundle != nil) {
        [self showFaceFromBundle:initialBundle];
    }
    [matchedBundle release];
    [firstBundle release];
}

- (void)configureLongPressGesture __attribute__((objc_direct)) {
    UILongPressGestureRecognizer *longPressGestureRecognizer = [[UILongPressGestureRecognizer alloc] initWithTarget:self action:@selector(didTriggerLongPressGestureRecognizer:)];
    [self.view addGestureRecognizer:longPressGestureRecognizer];
    [longPressGestureRecognizer release];
}

- (void)showFaceFromBundle:(__kindof NTKFaceBundle *)faceBundle __attribute__((objc_direct)) {
    if (self.faceViewController != nil) {
        [self.faceViewController willMoveToParentViewController:nil];
        [self.faceViewController.view removeFromSuperview];
        [self.faceViewController removeFromParentViewController];
        self.faceViewController = nil;
    }

    CLKDevice *device = CLKDevice.currentDevice;
    __kindof NTKFace * _Nullable face = [faceBundle defaultFaceForDevice:device];
    if (face == nil) {
        NSLog(@"No default face for bundle: %@", faceBundle);
        return;
    }

    NTKFaceViewController *faceViewController = [[NTKFaceViewController alloc] initWithFace:face configuration:nil];
    [self addChildViewController:faceViewController];
    faceViewController.view.frame = self.view.bounds;
    faceViewController.view.autoresizingMask = UIViewAutoresizingFlexibleWidth | UIViewAutoresizingFlexibleHeight;
    [self.view addSubview:faceViewController.view];
    [faceViewController didMoveToParentViewController:self];

    self.faceViewController = faceViewController;
    [faceViewController release];
}

- (void)didTriggerLongPressGestureRecognizer:(UILongPressGestureRecognizer *)sender {
    if (sender.state != UIGestureRecognizerStateBegan) return;

    FaceBundleListViewController *listViewController = [[FaceBundleListViewController alloc] init];
    listViewController.delegate = self;
    PUICNavigationController *navigationController = [[PUICNavigationController alloc] initWithRootViewController:listViewController];
    [self presentViewController:navigationController animated:YES completion:nil];
    [navigationController release];
    [listViewController release];
}

#pragma mark - FaceBundleListViewControllerDelegate

- (void)faceBundleListViewController:(FaceBundleListViewController *)viewController didSelectFaceBundle:(__kindof NTKFaceBundle *)faceBundle {
    NSString * _Nullable identifier = [[faceBundle class] identifier];
    if (identifier != nil) {
        [NSUserDefaults.standardUserDefaults setObject:identifier forKey:selectedFaceIdentifierKey()];
    }

    [self showFaceFromBundle:faceBundle];
    [viewController dismissViewControllerAnimated:YES completion:nil];
}

@end
