#import <_UIKitPrivate/UIContentConfiguration.h>
#import <_UIKitPrivate/UIDefines.h>

NS_HEADER_AUDIT_BEGIN(nullability, sendability)

UIKIT_EXTERN NS_SWIFT_UI_ACTOR
@interface UIListContentConfiguration : NSObject <UIContentConfiguration, NSSecureCoding>

+ (instancetype)_defaultInsetGroupedCellConfiguration;

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

@property (nonatomic, copy, nullable) NSString *text;

@end

NS_HEADER_AUDIT_END(nullability, sendability)
