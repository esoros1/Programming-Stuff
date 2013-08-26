//
//  Coin.m
//  Pkt Change
//
//  Created by Eric Soros on 3/19/13.
//  Copyright (c) 2013 Jake Tobin. All rights reserved.
//

#import "Coin.h"

@implementation Coin

@synthesize diameterInMM;
@synthesize center_x_touch;
@synthesize center_y_touch;
@synthesize radius;
@synthesize center_x;
@synthesize center_y;
@synthesize coinValue;
@synthesize red_blue_ratio;
@synthesize red_green_ratio;


- (id) initWithRadius:(float)rad centerX:(float)centerX centerY:(float)centerY
{
    self.radius = rad;
    self.center_x = centerX;
    self.center_y = centerY;
    
    
    return self;
}

- (NSString *) description
{
    return [NSString stringWithFormat:@"Radius %d : - Center X : %d - Center Y : %d - Value %@\n", (int)radius, (int)center_x, (int)center_y, [self coinValueString]];
}

- (NSString *) coinValueString
{
    
    if(coinValue == Quarter)
    {
        return @"Quarter";
    }
    
    if(coinValue == Nickel)
    {
        return @"Nickel";
    }

    if(coinValue == Dime)
    {
        return @"Dime";
    }

    if(coinValue == Penny)
    {
        return @"Penny";
    }
    
    if(coinValue == Unknown)
    {
        return @"Unkown";
    }
}

@end
