//
//  Coin.h
//  Pkt Change
//
//  Created by Eric Soros on 3/19/13.
//  Copyright (c) 2013 Jake Tobin. All rights reserved.
//

#import <Foundation/Foundation.h>

//wrapper enum for the coin valuea
typedef enum
{
    Unknown,
    Quarter,
    Nickel,
    Dime,
    Penny
    
    
} CoinValues;

@interface Coin : NSObject
{

}

@property float diameterInMM;

@property float center_x_touch;
@property float center_y_touch;

@property float red_green_ratio;
@property float red_blue_ratio;

@property float radius;
@property float center_x;
@property float center_y;
@property CoinValues coinValue;

-(id) initWithRadius:(float) radius centerX:(float)centerX centerY:(float)centerY;

-(void) setRadius:(float) radius;

-(NSString *) coinValueString;


@end
