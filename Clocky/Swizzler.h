#import <NanoTimeKit/NanoTimeKit.h>

NS_ASSUME_NONNULL_BEGIN

namespace swizzler {
    namespace NTKFaceDescriptor {
        namespace isAvailableForDevice {
            extern BOOL (* _Nullable original)(::NTKFaceDescriptor *self, SEL _cmd, CLKDevice *device);
            BOOL custom(::NTKFaceDescriptor *self, SEL _cmd, CLKDevice *device);
            void swizzle();
        }
    }
    namespace NTKFace {
        namespace isRestrictedForDevice {
            extern BOOL (* _Nullable original)(Class self, SEL _cmd, CLKDevice *device);
            BOOL custom(Class self, SEL _cmd, CLKDevice *device);
            void swizzle();
        }
    }
}

NS_ASSUME_NONNULL_END
