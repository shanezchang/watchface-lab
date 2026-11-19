#import <Foundation/Foundation.h>
#import <_UIKitPrivate/UIDefines.h>

@class UICollectionViewCell;

NS_HEADER_AUDIT_BEGIN(nullability, sendability)

typedef void(^UICollectionViewCellRegistrationConfigurationHandler)(__kindof UICollectionViewCell * _Nonnull cell, NSIndexPath * _Nonnull indexPath, id _Nonnull item);

UIKIT_EXTERN NS_SWIFT_UI_ACTOR
@interface UICollectionViewCellRegistration : NSObject

+ (instancetype)registrationWithCellClass:(Class)cellClass configurationHandler:(UICollectionViewCellRegistrationConfigurationHandler)configurationHandler;

@end

NS_HEADER_AUDIT_END(nullability, sendability)
