#import <NanoTimeKit/NanoTimeKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface FaceCategory : NSObject
@property (nonatomic, copy, readonly) NSString *name;
@property (nonatomic, copy, readonly) NSArray<__kindof NTKFaceBundle *> *faceBundles;
- (instancetype)initWithName:(NSString *)name faceBundles:(NSArray<__kindof NTKFaceBundle *> *)faceBundles;
+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;
@end

NS_ASSUME_NONNULL_END
