#import <Foundation/Foundation.h>
#import <_ClockKitPrivate/CLKDevice.h>
#import <NanoTimeKit/NTKFace.h>

NS_HEADER_AUDIT_BEGIN(nullability, sendability)

@interface NTKFaceBundle : NSObject
@property (class, nonatomic, readonly, nullable) NSString *identifier;
@property (nonatomic, readonly) Class faceClass;
- (nullable __kindof NTKFace *)defaultFaceForDevice:(CLKDevice *)device;
- (nullable NSString *)galleryTitleForDevice:(CLKDevice *)device;
@end

NS_HEADER_AUDIT_END(nullability, sendability)
