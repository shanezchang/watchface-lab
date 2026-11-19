#import <_UIKitPrivate/UIResponder.h>
#import <_UIKitPrivate/UIView.h>

NS_HEADER_AUDIT_BEGIN(nullability, sendability)

@class UINavigationController, UINavigationItem;

UIKIT_EXTERN NS_SWIFT_UI_ACTOR
@interface UIViewController : UIResponder
@property (nullable, nonatomic, copy) NSString *title;
@property (nullable, nonatomic, readonly) UINavigationController *navigationController;
@property (nonatomic, readonly, strong) UINavigationItem *navigationItem;
@property (null_resettable, nonatomic, strong) UIView *view;
- (void)viewDidLoad;
- (void)viewWillAppear:(BOOL)animated;
- (void)viewDidDisappear:(BOOL)animated;
- (void)presentViewController:(UIViewController *)viewControllerToPresent animated:(BOOL)flag completion:(void (^ _Nullable)(void))completion NS_SWIFT_DISABLE_ASYNC;
- (void)dismissViewControllerAnimated:(BOOL)flag completion:(void (^ _Nullable)(void))completion NS_SWIFT_DISABLE_ASYNC;
@property (nonatomic, readonly) BOOL prefersStatusBarHidden;
@end

@interface UIViewController (UIContainerViewControllerProtectedMethods)
- (void)addChildViewController:(UIViewController *)childController;
- (void)removeFromParentViewController;
@end

@interface UIViewController (UIContainerViewControllerCallbacks)
- (void)willMoveToParentViewController:(nullable UIViewController *)parent;
- (void)didMoveToParentViewController:(nullable UIViewController *)parent;
@end

NS_HEADER_AUDIT_END(nullability, sendability)
