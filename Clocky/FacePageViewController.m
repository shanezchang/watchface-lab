#import "FacePageViewController.h"
#import "FacePreviewViewController.h"

@interface FacePageViewController () <PUICPageViewControllerDelegate, FacePreviewViewControllerDelegate>
@property (nonatomic, retain, direct) FaceCategory *category;
@end

@implementation FacePageViewController

- (instancetype)initWithCategory:(FaceCategory *)category {
    self = [super initWithNavigationOrientation:0 titleBehavior:0 shouldPreloadChildViewControllers:NO pageTransform:1];
    if (self != nil) {
        self.category = category;
        self.delegate = self;
        [self configurePages];
    }
    return self;
}

- (void)configurePages __attribute__((objc_direct)) {
    NSMutableArray<UIViewController *> *pages = [[NSMutableArray alloc] initWithCapacity:self.category.faceBundles.count];
    for (__kindof NTKFaceBundle *bundle in self.category.faceBundles) {
        FacePreviewViewController *page = [[FacePreviewViewController alloc] initWithFaceBundle:bundle];
        page.delegate = self;
        [pages addObject:page];
        [page release];
    }
    self.viewControllers = pages;
    [pages release];
}

- (void)dealloc {
    self.delegate = nil;
    [_category release];
    [super dealloc];
}

- (void)viewDidLoad {
    [super viewDidLoad];
    [self configureNavigation];
}

- (void)configureNavigation __attribute__((objc_direct)) {
    self.title = self.category.name;
    UIBarButtonItem *dismissButton = [[UIBarButtonItem alloc] initWithBarButtonSystemItem:UIBarButtonSystemItemCancel target:self action:@selector(didSelectDismiss:)];
    self.navigationItem.rightBarButtonItem = dismissButton;
    [dismissButton release];
}

- (void)didSelectDismiss:(UIBarButtonItem *)sender {
    [self dismissViewControllerAnimated:YES completion:nil];
}

- (void)facePreviewViewController:(FacePreviewViewController *)viewController didSelectFaceBundle:(__kindof NTKFaceBundle *)faceBundle {
    id<FacePageViewControllerDelegate> delegate = self.faceSelectionDelegate;
    if ([delegate respondsToSelector:@selector(facePageViewController:didSelectFaceBundle:)]) {
        [delegate facePageViewController:self didSelectFaceBundle:faceBundle];
    }
}

- (void)pageViewController:(PUICPageViewController *)pageViewController didChangeToIndex:(NSInteger)index {
    // noop
}

@end
