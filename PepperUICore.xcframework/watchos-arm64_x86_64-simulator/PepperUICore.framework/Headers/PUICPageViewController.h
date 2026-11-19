#import <_UIKitPrivate/UIViewController.h>
#import <PepperUICore/PUICPageViewControllerDelegate.h>

NS_ASSUME_NONNULL_BEGIN

@interface PUICPageViewController : UIViewController
@property (nullable, nonatomic, assign) id<PUICPageViewControllerDelegate> delegate;
@property (nonatomic, copy) NSArray<UIViewController *> *viewControllers;
@property (nonatomic, readonly) NSInteger currentIndex;
- (instancetype)initWithNavigationOrientation:(NSUInteger)navigationOrientation titleBehavior:(NSInteger)titleBehavior shouldPreloadChildViewControllers:(BOOL)shouldPreloadChildViewControllers pageTransform:(NSInteger)pageTransform;
@end

NS_ASSUME_NONNULL_END
