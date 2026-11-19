#import <NanoTimeKit/NanoTimeKit.h>
#import <_UIKitPrivate/_UIKitPrivate.h>

NS_ASSUME_NONNULL_BEGIN

@class FacePreviewViewController;

@protocol FacePreviewViewControllerDelegate <NSObject>
@optional
- (void)facePreviewViewController:(FacePreviewViewController *)viewController didSelectFaceBundle:(__kindof NTKFaceBundle *)faceBundle;
@end

@interface FacePreviewViewController : UIViewController
@property (nullable, nonatomic, assign) id<FacePreviewViewControllerDelegate> delegate;
- (instancetype)initWithFaceBundle:(__kindof NTKFaceBundle *)faceBundle;
+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;
- (instancetype)initWithNibName:(nullable NSString *)nibNameOrNil bundle:(nullable NSBundle *)nibBundleOrNil NS_UNAVAILABLE;
- (instancetype)initWithCoder:(NSCoder *)coder NS_UNAVAILABLE;
@end

NS_ASSUME_NONNULL_END
