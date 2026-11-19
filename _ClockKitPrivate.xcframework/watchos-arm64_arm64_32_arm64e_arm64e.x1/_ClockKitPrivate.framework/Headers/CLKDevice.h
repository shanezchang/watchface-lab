#import <Foundation/Foundation.h>

NS_HEADER_AUDIT_BEGIN(nullability, sendability)

@interface CLKDevice : NSObject
@property (class, nonatomic, readonly, strong) CLKDevice *currentDevice;
@end

NS_HEADER_AUDIT_END(nullability, sendability)
