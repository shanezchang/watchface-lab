#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface SPRemoteInterface : NSObject
@property (nonatomic, copy) NSString *appClientIdentifier;
@property (nonatomic) BOOL afterWillEnterForeground;
- (void)performDidFinishLaunchingCompletions;
- (void)performAfterApplicationDidFinishLaunching:(void (^)(void))completion;
@end

NS_ASSUME_NONNULL_END
