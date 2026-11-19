#import <_UIKitPrivate/UIBarItem.h>

NS_HEADER_AUDIT_BEGIN(nullability, sendability)

typedef NS_ENUM(NSInteger, UIBarButtonSystemItem) {
    UIBarButtonSystemItemDone,
    UIBarButtonSystemItemCancel,
};

UIKIT_EXTERN NS_SWIFT_UI_ACTOR
@interface UIBarButtonItem : UIBarItem
- (instancetype)initWithBarButtonSystemItem:(UIBarButtonSystemItem)systemItem target:(nullable id)target action:(nullable SEL)action;
@end

NS_HEADER_AUDIT_END(nullability, sendability)
