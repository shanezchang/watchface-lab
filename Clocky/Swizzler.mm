#import "Swizzler.h"
#include <objc/runtime.h>
#include <objc/message.h>

namespace swizzler {
    namespace NTKFaceDescriptor {
        namespace isAvailableForDevice {
            BOOL (* _Nullable original)(::NTKFaceDescriptor *self, SEL _cmd, CLKDevice *device);
            BOOL custom(::NTKFaceDescriptor *self, SEL _cmd, CLKDevice *device) {
                return YES;
            }
            void swizzle() {
                Method method = class_getInstanceMethod([::NTKFaceDescriptor class], @selector(isAvailableForDevice:));
                assert(method != NULL);
                original = reinterpret_cast<decltype(original)>(method_getImplementation(method));
                method_setImplementation(method, reinterpret_cast<IMP>(custom));
            }
        }
    }
    namespace NTKFace {
        namespace isRestrictedForDevice {
            BOOL (* _Nullable original)(Class self, SEL _cmd, CLKDevice *device);
            BOOL custom(Class self, SEL _cmd, CLKDevice *device) {
                return NO;
            }
            void swizzle() {
                [NTKFaceBundleManager.sharedManager.loader enumerateFaceBundleClassesIgnoringCache:NO withBlock:^(__kindof NTKFaceBundle *faceBundle) {
                    Class faceClass = faceBundle.faceClass;
                    Method method = class_getClassMethod(faceClass, @selector(isRestrictedForDevice:));
                    if (method != NULL) {
                        original = reinterpret_cast<decltype(original)>(method_getImplementation(method));
                        method_setImplementation(method, reinterpret_cast<IMP>(custom));
                    }
                }];
            }
        }
    }
}
