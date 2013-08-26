//
//  CoinFinder.h
//  Pkt Change
//
//  Created by Eric Soros on 3/18/13.
//  Copyright (c) 2013 Jake Tobin. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Coin.h"

@interface CoinFinder : NSObject
{
    UIImage * imageToProcess;
    cv::Mat _mat;
    float mmPerPixel;
}

@property NSArray * CoinsFound;

- (UIImage *) getCoinsInImage;

- (UIImage *)imageWithCVMat:(const cv::Mat&)cvMat;

- (void) drawCirclesAroundCoinsInPictureWithCoins:(NSArray *) Coins;

- (bool) isPenny:(Coin *) coin withPicture:(cv::Mat&) cvMat;

- (void) setTouchCoordinatesForCoin:(Coin *) coin;

- (void) assignValueToCoinBasedOnDiameter:(Coin *) coin;

- (UIImage *) getImageToProcess;

- (UIImage *) getImageFromCVMat;

- (void) setImageToProcess:(UIImage *) image;

- (void) setMmPerPixel:(float) mm;

- (NSInteger) getValueOfCoinsInImage;

- (void) pennyDetectionWithCoins: (NSArray *) coins;

- (void) getColorRatiosFromCoin:(Coin *) coin outputRedGreen:(float&) red_green outputRedBlue:(float&) red_blue;

@end
