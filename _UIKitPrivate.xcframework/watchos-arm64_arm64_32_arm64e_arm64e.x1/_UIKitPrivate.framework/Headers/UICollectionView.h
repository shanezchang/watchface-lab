#import <_UIKitPrivate/UIScrollView.h>
#import <_UIKitPrivate/UIDefines.h>

NS_HEADER_AUDIT_BEGIN(nullability, sendability)

@class UICollectionView, UICollectionViewCell, UICollectionViewCellRegistration;

@protocol UICollectionViewDataSource <NSObject>
@required

- (NSInteger)collectionView:(UICollectionView *)collectionView numberOfItemsInSection:(NSInteger)section;

- (__kindof UICollectionViewCell *)collectionView:(UICollectionView *)collectionView cellForItemAtIndexPath:(NSIndexPath *)indexPath;

@optional

- (NSInteger)numberOfSectionsInCollectionView:(UICollectionView *)collectionView;

@end

@protocol UICollectionViewDelegate <UIScrollViewDelegate>
@optional

- (void)collectionView:(UICollectionView *)collectionView didSelectItemAtIndexPath:(NSIndexPath *)indexPath;

@end

UIKIT_EXTERN NS_SWIFT_UI_ACTOR
@interface UICollectionView : UIScrollView
- (__kindof UICollectionViewCell *)dequeueConfiguredReusableCellWithRegistration:(UICollectionViewCellRegistration *)registration forIndexPath:(NSIndexPath *)indexPath item:(id)item;
@end

NS_HEADER_AUDIT_END(nullability, sendability)
