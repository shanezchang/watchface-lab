#import <_UIKitPrivate/UIView.h>
#import <_UIKitPrivate/UIDefines.h>
#import <_UIKitPrivate/UIContentConfiguration.h>

NS_HEADER_AUDIT_BEGIN(nullability, sendability)

UIKIT_EXTERN NS_SWIFT_UI_ACTOR
@interface UICollectionReusableView : UIView
@end

UIKIT_EXTERN NS_SWIFT_UI_ACTOR
@interface UICollectionViewCell : UICollectionReusableView
@property (nonatomic, copy, nullable) id<UIContentConfiguration> contentConfiguration;
@end

NS_HEADER_AUDIT_END(nullability, sendability)
