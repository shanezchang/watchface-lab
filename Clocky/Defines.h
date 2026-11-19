#import <Foundation/Foundation.h>

#ifdef __cplusplus
#define CLKY_EXTERN  extern "C" __attribute__((visibility ("default")))
#else
#define CLKY_EXTERN  extern __attribute__((visibility ("default")))
#endif

NS_ASSUME_NONNULL_BEGIN

CLKY_EXTERN NSString * selectedFaceIdentifierKey(void);

NS_ASSUME_NONNULL_END
