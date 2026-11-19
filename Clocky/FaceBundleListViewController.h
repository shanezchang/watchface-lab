#import <PepperUICore/PepperUICore.h>
#import <NanoTimeKit/NanoTimeKit.h>

NS_ASSUME_NONNULL_BEGIN

@class FaceBundleListViewController;

@protocol FaceBundleListViewControllerDelegate <NSObject>
@optional
- (void)faceBundleListViewController:(FaceBundleListViewController *)viewController didSelectFaceBundle:(__kindof NTKFaceBundle *)faceBundle;
@end

@interface FaceBundleListViewController : PUICListCollectionViewController
@property (nullable, nonatomic, assign) id<FaceBundleListViewControllerDelegate> delegate;
@end

NS_ASSUME_NONNULL_END
