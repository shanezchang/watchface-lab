#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class SPExtensionConnection;

@interface SPCompanionLogger : NSObject
@property (class, nonatomic, readonly) SPCompanionLogger *sharedInstance;
@property (nullable, nonatomic, retain) SPExtensionConnection *extensionConnection;
@end

NS_ASSUME_NONNULL_END
