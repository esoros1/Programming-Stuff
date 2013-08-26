//
//  CoinFinder.m
//  Pkt Change
//
//  Created by Eric Soros on 3/18/13.
//  Copyright (c) 2013 Jake Tobin. All rights reserved.
//

#import "CoinFinder.h"
#import "Coin.h"
#include <vector>

@implementation CoinFinder

@synthesize CoinsFound;

//do the image processing
- (UIImage *) getCoinsInImage
{
    
    cv::Mat src_gray;
    
    //the UIIMage gets created with 4 channels, but we need 3 to do the pixel recognition. 
    cv::cvtColor(_mat, src_gray, CV_BGR2GRAY );
    
    cv::GaussianBlur(src_gray, src_gray, cv::Size(9,9), 0);
    
    std::vector<cv::Vec3f> circles;
    NSMutableArray * coins = [[NSMutableArray alloc] init];
    NSMutableArray * pennies = [[NSMutableArray alloc] init];
    
    /// Apply the Hough Transform to find the circles
    cv::HoughCircles( src_gray, circles, CV_HOUGH_GRADIENT, 2, //Inverse ratio
                 100, //Minimum distance between the centers of the detected circles
                 110, //Higher threshold for canny edge detector
                 210, //Threshold at the center detection stage
                 80, //min radius
                 300);
    

    //draw circles
    for( size_t i = 0; i < circles.size(); i++ )
    {
        cv::Point center(cvRound(circles[i][0]), cvRound(circles[i][1]));
        int radius = cvRound(circles[i][2]);
        
        printf("radius %d  ::  %d\n", i, radius );
        
        // circle center
        //circle( cvMat, center, 3, cv::Scalar(255,0,0), -1, 8, 0 );
        // circle outline
        circle( _mat, center, radius, cv::Scalar(0 , 255,0), 3, 8, 0 );
                
        Coin * coinToAdd = [[Coin alloc] initWithRadius:radius centerX:center.x centerY:center.y];
        bool coinIsPenny = [self isPenny:coinToAdd withPicture:_mat];
        if(coinIsPenny)
        {
            coinToAdd.coinValue = Penny;
            circle( _mat, center, radius, cv::Scalar(225 , 255,0), 3, 8, 0 );
            [pennies addObject:coinToAdd];
        }
        else
        {
            [coins addObject:coinToAdd];
        }
    
        //calculate the center of the picture using coordinates of the iphone screen
        [self setTouchCoordinatesForCoin:coinToAdd];
    }

    //[self assignValuesToCoins:coins];
    [coins addObjectsFromArray:pennies];
    [self drawCirclesAroundCoinsInPictureWithCoins:coins];
    self.CoinsFound = coins;
    
    //do penny detection on all of the coins
    
    [self pennyDetectionWithCoins:coins];
    
    
    return [self imageWithCVMat:_mat];
}

/*
Attempt number 2 at doing penny detection
here's the idea.

 We are going to generate the average red_blue and red_green ratio for all of the coins
 If the ratio is above the average, than it is probably a penny. (it will be if the picture has any pennys in it)
 So then we take the highest ratio which will be a penny to set the scale, and use that to weed out anything
 that was detected as a penny that isn't a penny (such as quartes). 
 
 */
- (void) pennyDetectionWithCoins:(NSArray *)coins
{
    float red_green_average = 0.0;
    float red_blue_average = 0.0;
    
    for (Coin * coin in coins)
    {
        float red_green_temp = 0.0;
        float red_blue_temp  = 0.0;
        
        
        [self getColorRatiosFromCoin:coin outputRedGreen:red_green_temp outputRedBlue:red_blue_temp];
        printf("red_green %.2f, red_blue %.2f\n", red_green_temp, red_blue_temp );
    
        coin.red_blue_ratio = red_blue_temp;
        coin.red_green_ratio = red_green_temp;
        
        red_blue_average += red_blue_temp;
        red_green_average += red_green_temp;
    }

    red_green_average = red_green_average / [coins count];
    red_blue_average = red_blue_average / [coins count];
    
    printf("Average Red Green %.2f, Average Red Blue %.2f\n" , red_green_average  , red_blue_average );

    
    //use the highest value to set the scale, THIS ASSUMES THAT IT HAS A PENNY
    float red_green_temp = 0.0;
    Coin * highestCoin;
    for(Coin * coin in coins)
    {
        if(coin.red_green_ratio > red_green_temp)
        {
            red_green_temp = coin.red_green_ratio;
            highestCoin = coin;
        }
    }
    
    //Assume the highest coin is a penny (it should be if there is a penny in the picture)
    //we are going to use this to set the scale, and then use the scale to weed out any false positives
    float mmperpixel = 19.05 / highestCoin.radius;
    
    for(Coin * coin in coins)
    {
        if(coin.red_blue_ratio > red_blue_average && coin.red_green_ratio > red_green_average && coin.radius * mmperpixel < 21)
        {
            coin.coinValue = Penny;
        }
    }
    
}

//get the average red_green ratio and red_blue ratio from all of the pixels in the coin
- (void) getColorRatiosFromCoin:(Coin *)coin outputRedGreen:(float &)red_green outputRedBlue:(float &)red_blue
{
    
    //go through all of the pixels in the coin, and get the average red-blue and red-green ratio
    int pixelCount = 0;
    
    float redGreenRatio = 0.0;
    float redBlueRatio = 0.0;
    
    float center_x = coin.center_x;
    float center_y = coin.center_y;
    float radius = coin.radius;
    
    //get the corners of the rectangle
    CGPoint top_left, top_right, bottom_left, bottom_right;
    
    top_left.x = center_x - radius;
    top_left.y = center_y - radius;
    
    bottom_left.x = center_x - radius;
    bottom_left.y = center_y + radius;
    
    top_right.x = center_x + radius;
    top_right.y  = center_y - radius;
    
    bottom_right.x = center_x + radius;
    bottom_right.y = center_y + radius;
    
    //we are going to draw a rectangle around the coin using the radius and center, and check all
    //of the points inside the retangle to see if they are inside the cirlce
    
    for(int i = (int)top_left.x; i < (int)top_right.x; ++i)
    {
        for(int j = (int)top_left.y; j < (int)bottom_left.y; ++j)
        {
            //get the distance from the center
            float distanceFromCenter = ((i - center_x) * (i - center_x) ) + ((j-center_y) * (j-center_y));
            //multiplication is a lot faster than sqrt
            if(distanceFromCenter < (radius * radius))
            {
                
                int redPixel =  _mat.at<cv::Vec3b>(j,i)[0];
                int bluePixel = _mat.at<cv::Vec3b>(j,i)[1];
                int greenPixel = _mat.at<cv::Vec3b>(j,i)[2];
                
                if(redPixel != 0 && greenPixel != 0 && bluePixel != 0)
                {
                    redGreenRatio += (float)redPixel / (float) greenPixel;
                    redBlueRatio += (float) redPixel / (float) bluePixel;
                }
                
                pixelCount++;
            }
        }
    }
    
    redBlueRatio /=  pixelCount;
    redGreenRatio /= pixelCount;

    red_blue = redBlueRatio;
    red_green = redGreenRatio;
    
    
}


//return a UIImage from a cv mat
-(UIImage *) imageWithCVMat:(const cv::Mat &)cvMat
{
    
    NSData *data = [NSData dataWithBytes:cvMat.data length:cvMat.elemSize() * cvMat.total()];
    
    CGColorSpaceRef colorSpace;
    
    if (cvMat.elemSize() == 1) {
        colorSpace = CGColorSpaceCreateDeviceGray();
    } else {
        colorSpace = CGColorSpaceCreateDeviceRGB();
    }
    
    CGDataProviderRef provider = CGDataProviderCreateWithCFData((__bridge CFDataRef)data);
    
    CGImageRef imageRef = CGImageCreate(cvMat.cols,                                     // Width
                                        cvMat.rows,                                     // Height
                                        8,                                              // Bits per component
                                        8 * cvMat.elemSize(),                           // Bits per pixel
                                        cvMat.step[0],                                  // Bytes per row
                                        colorSpace,                                     // Colorspace
                                        kCGImageAlphaNone | kCGBitmapByteOrderDefault,  // Bitmap info flags
                                        provider,                                       // CGDataProviderRef
                                        NULL,                                           // Decode
                                        false,                                          // Should interpolate
                                        kCGRenderingIntentDefault);                     // Intent
    
    UIImage *image = [[UIImage alloc] initWithCGImage:imageRef];
    CGImageRelease(imageRef);
    CGDataProviderRelease(provider);
    CGColorSpaceRelease(colorSpace);
    
    return image;
}

//draw different colored circles around the detected coins in the image
-(void) drawCirclesAroundCoinsInPictureWithCoins:(NSArray *)Coins
{
    NSInteger numCoins = [Coins count];
    
    for(int i = 0; i < numCoins; ++i)
    {
        Coin * coin = [Coins objectAtIndex:i];
        
        if(coin.coinValue == Penny)
        {
            circle( _mat, cv::Point(coin.center_x, coin.center_y), coin.radius, cv::Scalar(0,0,255), 3, 8, 0 );
        }
        if(coin.coinValue == Dime)
        {
            circle( _mat, cv::Point(coin.center_x, coin.center_y), coin.radius, cv::Scalar(255,0,0), 3, 8, 0 );

        }
        if(coin.coinValue == Nickel)
        {
            circle( _mat, cv::Point(coin.center_x, coin.center_y), coin.radius, cv::Scalar(0,255,0), 3, 8, 0 );

        }
        if(coin.coinValue == Quarter)
        {
            circle( _mat, cv::Point(coin.center_x, coin.center_y), coin.radius, cv::Scalar(255,56,158), 3, 8, 0 );

        }
        if(coin.coinValue == Unknown)
        {
            circle( _mat, cv::Point(coin.center_x, coin.center_y), coin.radius, cv::Scalar(0,0,0), 3, 8, 0 );

        }
    }
}

//detect if the coin in the picture is a penny
//the picture is stored as RED BLUE GREEN
//let's see what min and max ratio does?
- (bool) isPenny:(Coin *)coin withPicture:(cv::Mat &)cvMat
{
    /*
    
    int pixelCount = 0;
    
    float redGreenRatio = 0.0;
    float redBlueRatio = 0.0;
    
    float center_x = coin.center_x;
    float center_y = coin.center_y;
    float radius = coin.radius;
    
    //get the corners of the rectangle
    CGPoint top_left, top_right, bottom_left, bottom_right;
    
    top_left.x = center_x - radius;
    top_left.y = center_y - radius;
    
    bottom_left.x = center_x - radius;
    bottom_left.y = center_y + radius;
    
    top_right.x = center_x + radius;
    top_right.y  = center_y - radius;
    
    bottom_right.x = center_x + radius;
    bottom_right.y = center_y + radius;
    
    for(int i = (int)top_left.x; i < (int)top_right.x; ++i)
    {
        for(int j = (int)top_left.y; j < (int)bottom_left.y; ++j)
        {
            //get the distance from the center
            float distanceFromCenter = ((i - center_x) * (i - center_x) ) + ((j-center_y) * (j-center_y));
            //multiplication is a lot faster than sqrt
            if(distanceFromCenter < (radius * radius))
            {
                //get the average green and red pixel colors
                
                int redPixel =  cvMat.at<cv::Vec3b>(j,i)[0];
                int bluePixel = cvMat.at<cv::Vec3b>(j,i)[1];
                int greenPixel = cvMat.at<cv::Vec3b>(j,i)[2];
                
                if(redPixel != 0 && greenPixel != 0 && bluePixel != 0)
                {
                    redGreenRatio += (float)redPixel / (float) greenPixel;
                    redBlueRatio += (float) redPixel / (float) bluePixel;
                }
                
                //cvMat.at<cv::Vec3b>(j, i)[0] = 255;
                //cvMat.at<cv::Vec3b>(j, i)[1] = 255;
                //cvMat.at<cv::Vec3b>(j, i)[2] = 255;
                pixelCount++;
            }
        }
    }
    
    redBlueRatio /=  pixelCount;
    redGreenRatio /= pixelCount;
    
    printf("Red-Green :%.6f  Red-Blue:%.6f  \n", redGreenRatio, redBlueRatio );
    
    return  redGreenRatio > 1.79 && redBlueRatio > 1.3;
*/
    return NO;
}

//calculate and set where the center of each of the coins is going to be on the iphone screen, so we known if the user touched on a coin
//in the picture
/*
 
 So here's how it works. In landscape mode, the aspect ratio is .75.
 This means that the Width wll take up the entire view, and the height will have to be shurnk (aka it won't take up the entire view).
 
 The 11.07 and 11.06 are the ratios between the size of the picture from the camera and the size of the image on the screen.
 
 We have to add 80 because that's the offset of the Image from the top of the ImageView, which will actually respond to the touhch event.
 
 It seems that the image processing turn every image so that it is landscape, so this should work with every image
 
 */
- (void) setTouchCoordinatesForCoin:(Coin *) coin
{
    
    //TODO Move this away from hard coded numbers so it works on iPad / iPhone 5
    
    coin.center_x_touch = coin.center_x / 11.07;

    coin.center_y_touch = (coin.center_y / 11.06) + 80;    
}


//we are going to assign the coins there value based on the diameter of the coin
//no pennies allwoed
- (void) assignValueToCoinBasedOnDiameter:(Coin *)coin
{
    float diameter = coin.diameterInMM;
    
    if(diameter > 22.25)
    {
        coin.coinValue = Quarter;
    }
    else if(diameter > 20 && diameter < 23)
    {
        coin.coinValue = Nickel;
    }
    else if (diameter > 10 && diameter < 20)
    {
        coin.coinValue = Dime;
    }
    
    //I'll add ranges for shit that is questionable later on.

}

//getter and setter for the UIImage that we are processing.
//notice that the setter for the UIImage also sets the cv mat that is used internally
- (UIImage *) getImageToProcess
{
    return imageToProcess;
}

- (void) setImageToProcess:(UIImage *)image
{
    imageToProcess = image;
    
    //create a cvMat based on the image for internal processing use.
    //conver uiimage to mat
    CGColorSpaceRef colorSpace = CGImageGetColorSpace(image.CGImage);
    CGFloat cols, rows;
    
    //if portrait
    if(image.imageOrientation == UIImageOrientationUp || image.imageOrientation == UIImageOrientationDown)
    {
        cols = image.size.width;
        rows = image.size.height;
    }
    //if landscape
    else
    {
        cols = image.size.height;
        rows = image.size.width;
    }
    
    cv::Mat cvMat(rows, cols, CV_8UC4); // 8 bits per component, 4 channels
    
    CGContextRef contextRef = CGBitmapContextCreate(cvMat.data,                 // Pointer to  data
                                                    cols,                       // Width of bitmap
                                                    rows,                       // Height of bitmap
                                                    8,                          // Bits per component
                                                    cvMat.step[0],              // Bytes per row
                                                    colorSpace,                 // Colorspace
                                                    kCGImageAlphaNoneSkipLast |
                                                    kCGBitmapByteOrderDefault); // Bitmap info flags
    
    CGContextDrawImage(contextRef, CGRectMake(0, 0, cols, rows), image.CGImage);
    CGContextRelease(contextRef);
    CGColorSpaceRelease(colorSpace);
    
    //the UIIMage gets created with 4 channels, but we need 3 to do the pixel recognition.
    cv::cvtColor(cvMat, cvMat, CV_RGBA2RGB);
    
    _mat = cvMat;

}

//set the mm per mpixel of the image that we are processing.
//This allows us to get the diameter of all the coins and use that to find the value
- (void) setMmPerPixel:(float)mm
{
    mmPerPixel = mm;
}

//return the image as represented by the internal CV mat
- (UIImage *) getImageFromCVMat
{
    return [self imageWithCVMat:_mat];
}


@end
