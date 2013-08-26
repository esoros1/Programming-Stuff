//
//  FirstViewController.h
//  Pkt Change
//
//  Created by Jake Tobin on 3/9/13.
//  Copyright (c) 2013 Jake Tobin. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "CoinFinder.h"
#import <CoreMotion/CoreMotion.h>

@interface FirstViewController : UIViewController <UIImagePickerControllerDelegate , UINavigationControllerDelegate, UIPickerViewDelegate, UIPickerViewDataSource>
{
    IBOutlet UIImageView *imageView;
    IBOutlet UIPickerView * pickerView;
    IBOutlet UIToolbar * pickerToolBar;
    
    UIImage *image;
    NSArray * coins;
    CoinFinder * coinFinder;

    NSString * lastPickerItemChosen;
    CGPoint lastLocationTouched;

    CMMotionManager * motionManager;
    
    int totalValue;
}

- (IBAction) onPickerCancelPress:(id)sender;

- (IBAction)submitClicked:(id)sender;

- (IBAction)takePicture:(id)sender;

- (IBAction)album:(id)sender;

- (IBAction) onPress: (id)sender;

- (IBAction) onPickerDonePress:(id)sender;

- (void) showChangeResultAlert:(NSInteger) result;

- (void) calculateTotal;

- (float) getDiameterOfCoinFromString:(NSString *) coinStr;

- (BOOL) isLocationCoin:(CGPoint) location;

- (void) startProcessImage:(UIActivityIndicatorView *) alert;

- (int) calculateValueWithMMinPxel:(float) mmperpixel;

- (void)alertView:(UIAlertView *)alertView clickedButtonAtIndex:(NSInteger)buttonIndex;

- (void) getMotionValues:(NSTimer *) timer;

- (void) changeColor:(UIView *) view;

@end


