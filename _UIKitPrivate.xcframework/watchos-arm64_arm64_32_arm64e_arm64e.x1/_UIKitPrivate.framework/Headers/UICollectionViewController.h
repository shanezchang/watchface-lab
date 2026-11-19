#import <_UIKitPrivate/UIViewController.h>
#import <_UIKitPrivate/UICollectionView.h>
#import <_UIKitPrivate/UIDefines.h>

NS_HEADER_AUDIT_BEGIN(nullability, sendability)

UIKIT_EXTERN NS_SWIFT_UI_ACTOR
@interface UICollectionViewController : UIViewController <UICollectionViewDelegate, UICollectionViewDataSource>
@property (null_resettable, nonatomic, strong) __kindof UICollectionView *collectionView;
@end

NS_HEADER_AUDIT_END(nullability, sendability)
