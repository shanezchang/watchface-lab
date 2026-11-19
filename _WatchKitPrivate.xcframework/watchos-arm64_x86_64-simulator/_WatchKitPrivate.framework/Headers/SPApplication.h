#import <PepperUICore/PepperUICore.h>

NS_ASSUME_NONNULL_BEGIN

@interface SPApplication : PUICApplication
@property (class, nonatomic, readonly) SPApplication *sharedSPApplication;
@end

NS_ASSUME_NONNULL_END
