#import <PepperUICore/PepperUICore.h>
#import "FaceCategory.h"

NS_ASSUME_NONNULL_BEGIN

@class FacePageViewController;

@protocol FacePageViewControllerDelegate <NSObject>
@optional
- (void)facePageViewController:(FacePageViewController *)viewController didSelectFaceBundle:(__kindof NTKFaceBundle *)faceBundle;
@end

@interface FacePageViewController : PUICPageViewController
@property (nullable, nonatomic, assign) id<FacePageViewControllerDelegate> faceSelectionDelegate;
- (instancetype)initWithCategory:(FaceCategory *)category;
+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;
- (instancetype)initWithNibName:(nullable NSString *)nibNameOrNil bundle:(nullable NSBundle *)nibBundleOrNil NS_UNAVAILABLE;
- (instancetype)initWithCoder:(NSCoder *)coder NS_UNAVAILABLE;
@end

NS_ASSUME_NONNULL_END
