#import <Foundation/Foundation.h>
#import <_ClockKitPrivate/CLKDevice.h>
#import <NanoTimeKit/NTKFaceBundle.h>
#import <NanoTimeKit/NTKFaceBundleLoader.h>

NS_HEADER_AUDIT_BEGIN(nullability, sendability)

@interface NTKFaceBundleManager : NSObject
@property (class, nonatomic, readonly, strong) NTKFaceBundleManager *sharedManager;
@property (nonatomic, readonly, strong) NTKFaceBundleLoader *loader;
- (void)enumerateFaceBundlesOnDevice:(CLKDevice *)device withBlock:(void (NS_NOESCAPE ^)(__kindof NTKFaceBundle *faceBundle))block;
- (void)enumerateFaceBundlesOnDevice:(CLKDevice *)device includingLegacy:(BOOL)includingLegacy withBlock:(void (NS_NOESCAPE ^)(__kindof NTKFaceBundle *faceBundle))block;
@end

NS_HEADER_AUDIT_END(nullability, sendability)
