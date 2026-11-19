#import "FaceCategory.h"

@interface FaceCategory ()
@property (nonatomic, copy, readwrite) NSString *name;
@property (nonatomic, copy, readwrite) NSArray<__kindof NTKFaceBundle *> *faceBundles;
@end

@implementation FaceCategory

- (instancetype)initWithName:(NSString *)name faceBundles:(NSArray<__kindof NTKFaceBundle *> *)faceBundles {
    self = [super init];
    if (self != nil) {
        self.name = name;
        self.faceBundles = faceBundles;
    }
    return self;
}

- (void)dealloc {
    [_name release];
    [_faceBundles release];
    [super dealloc];
}

@end
