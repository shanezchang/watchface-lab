#import <_UIKitPrivate/UIResponder.h>
#import <_UIKitPrivate/UIAppearance.h>

NS_HEADER_AUDIT_BEGIN(nullability, sendability)

typedef NS_OPTIONS(NSUInteger, UIViewAutoresizing) {
    UIViewAutoresizingNone                 = 0,
    UIViewAutoresizingFlexibleLeftMargin   = 1 << 0,
    UIViewAutoresizingFlexibleWidth        = 1 << 1,
    UIViewAutoresizingFlexibleRightMargin  = 1 << 2,
    UIViewAutoresizingFlexibleTopMargin    = 1 << 3,
    UIViewAutoresizingFlexibleHeight       = 1 << 4,
    UIViewAutoresizingFlexibleBottomMargin = 1 << 5
};

@class UIColor, UIGestureRecognizer;

UIKIT_EXTERN NS_SWIFT_UI_ACTOR
@interface UIView : UIResponder
@property (nullable, nonatomic, copy) UIColor *backgroundColor UI_APPEARANCE_SELECTOR;
@property (nonatomic, getter=isUserInteractionEnabled) BOOL userInteractionEnabled;
@end

@interface UIView (UIViewGeometry)
@property (nonatomic) CGRect frame;
@property (nonatomic) CGRect bounds;
@property (nonatomic) UIViewAutoresizing autoresizingMask;
@end

@interface UIView (UIViewHierarchy)
- (void)removeFromSuperview;
- (void)addSubview:(UIView *)view;
@end

@interface UIView (UIViewGestureRecognizers)
- (void)addGestureRecognizer:(UIGestureRecognizer *)gestureRecognizer;
@end

NS_HEADER_AUDIT_END(nullability, sendability)
