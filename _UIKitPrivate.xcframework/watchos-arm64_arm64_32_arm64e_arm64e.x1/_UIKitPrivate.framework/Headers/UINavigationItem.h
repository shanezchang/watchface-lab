#import <Foundation/Foundation.h>
#import <_UIKitPrivate/UIDefines.h>

NS_HEADER_AUDIT_BEGIN(nullability, sendability)

@class UIBarButtonItem;

UIKIT_EXTERN NS_SWIFT_UI_ACTOR
@interface UINavigationItem : NSObject
@property (nullable, nonatomic, strong) UIBarButtonItem *rightBarButtonItem;
@end

NS_HEADER_AUDIT_END(nullability, sendability)
