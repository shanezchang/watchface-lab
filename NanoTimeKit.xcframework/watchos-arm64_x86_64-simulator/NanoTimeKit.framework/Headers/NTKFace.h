#import <Foundation/Foundation.h>
#import <_ClockKitPrivate/CLKDevice.h>

NS_HEADER_AUDIT_BEGIN(nullability, sendability)

@interface NTKFace : NSObject
+ (BOOL)isRestrictedForDevice:(CLKDevice *)device;
@end

NS_HEADER_AUDIT_END(nullability, sendability)
