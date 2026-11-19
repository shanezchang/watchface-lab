#import <Foundation/Foundation.h>
#import <_ClockKitPrivate/CLKDevice.h>

NS_HEADER_AUDIT_BEGIN(nullability, sendability)

@interface NTKFaceDescriptor : NSObject
- (BOOL)isAvailableForDevice:(CLKDevice *)device;
@end

NS_HEADER_AUDIT_END(nullability, sendability)
