#import <_UIKitPrivate/_UIKitPrivate.h>
#import <NanoTimeKit/NTKFace.h>

NS_HEADER_AUDIT_BEGIN(nullability, sendability)

@interface NTKFaceViewController : UIViewController
- (instancetype)initWithFace:(NTKFace *)face configuration:(void (NS_NOESCAPE ^ _Nullable)(NTKFaceViewController *faceViewController))configuration;
@end

NS_HEADER_AUDIT_END(nullability, sendability)
