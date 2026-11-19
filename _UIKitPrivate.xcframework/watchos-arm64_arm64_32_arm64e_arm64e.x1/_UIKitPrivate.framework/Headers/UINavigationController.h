#import <_UIKitPrivate/UIViewController.h>

NS_HEADER_AUDIT_BEGIN(nullability, sendability)

@interface UINavigationController : UIViewController
- (instancetype)initWithRootViewController:(UIViewController *)rootViewController;
- (void)pushViewController:(UIViewController *)viewController animated:(BOOL)animated;
@end

NS_HEADER_AUDIT_END(nullability, sendability)
