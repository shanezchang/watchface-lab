#import <Foundation/Foundation.h>
#import <NanoTimeKit/NTKFaceBundle.h>

NS_HEADER_AUDIT_BEGIN(nullability, sendability)

@interface NTKFaceBundleLoader : NSObject
- (void)enumerateFaceBundleClassesIgnoringCache:(BOOL)ignoringCache withBlock:(void (NS_NOESCAPE ^)(__kindof NTKFaceBundle *faceBundle))block;
@end

NS_HEADER_AUDIT_END(nullability, sendability)
