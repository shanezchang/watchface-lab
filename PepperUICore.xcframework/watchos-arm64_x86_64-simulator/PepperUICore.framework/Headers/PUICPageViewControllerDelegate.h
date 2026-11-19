#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class PUICPageViewController;

@protocol PUICPageViewControllerDelegate <NSObject>
@optional
- (void)pageViewController:(PUICPageViewController *)pageViewController didChangeToIndex:(NSInteger)index;
@end

NS_ASSUME_NONNULL_END
