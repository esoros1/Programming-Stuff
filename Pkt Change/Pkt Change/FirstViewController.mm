//
//  FirstViewController.m
//  Pkt Change
//
//  Created by Jake Tobin on 3/9/13.
//  Copyright (c) 2013 Jake Tobin. All rights reserved.
//

#import "FirstViewController.h"
#import "ImageStore.h"
#import "NSData+Base64.h"
#import "CoinFinder.h"
#import "CoinTableViewController.h"
#import "CameraOverlayViewController.h"

@interface FirstViewController ()

@end

@implementation FirstViewController

//                              UIPickerView delegate / data source methods
/////////////////////////////////////////////////////////////////////////////////////////////////////////

- (NSInteger) numberOfComponentsInPickerView:(UIPickerView *)pickerView
{
    return 1;
}

- (NSInteger) pickerView:(UIPickerView *)pickerView numberOfRowsInComponent:(NSInteger)component
{
    return 4;
}

- (NSString *) pickerView:(UIPickerView *)pickerView titleForRow:(NSInteger)row forComponent:(NSInteger)component
{
    NSString * result;
    
    if(row == 0)
    {
        result = @"Penny";
    }
    else if (row == 1)
    {
        result = @"Nickel";
        
    }
    else if ( row == 2)
    {
        result = @"Dime";
    }
    else
    {
        result = @"Quarter";
    }
    
    return result;
}

- (void) pickerView:(UIPickerView *)pickerView didSelectRow:(NSInteger)row inComponent:(NSInteger)component
{
    //implement later.
    //probably gonna have a string that holds the value of the last value that the picker has selected
    if(row == 0)
    {
        lastPickerItemChosen = @"Penny";
    }
    if(row == 1)
    {
        lastPickerItemChosen = @"Nickel";
    }
    if(row == 2)
    {
        lastPickerItemChosen = @"Dime";
    }
    if (row ==3)
    {
        lastPickerItemChosen = @"Quarter";
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////


//this get's called when the done button is pressed when the picker comes up
- (void) onPickerDonePress:(id)sender
{
    //this can be done on the main thread and sync.
    //it doesn't take long at all.
    [self calculateTotal];
    [self showChangeResultAlert:totalValue];
}

- (void) onPickerCancelPress:(id)sender
{
    pickerToolBar.hidden = YES;
    pickerView.hidden = YES;
}

- (void)viewDidLoad
{
    
    [super viewDidLoad];
	// Do any additional setup after loading the view, typically from a nib.
    
    //set up getting motion data
    motionManager = [[CMMotionManager alloc] init];
    
    //register the tap recognizer
    UITapGestureRecognizer * singleFingerTap = [[UITapGestureRecognizer alloc] initWithTarget:self action:(@selector(tap:))];
    [imageView addGestureRecognizer:singleFingerTap];
    imageView.userInteractionEnabled = YES;

    //make a single instance of the coin finder
    coinFinder = [[CoinFinder alloc] init];
    
    //hide the picker view and toolbar
    pickerView.hidden = YES;
    pickerToolBar.hidden = YES;
    pickerView.dataSource = self;
    pickerView.delegate = self;
}

//this is called when the user touched anywhere inside the ImageView
- (void) tap:(UITapGestureRecognizer *) recognizer
{
    lastLocationTouched = [recognizer locationInView:imageView];
    
    //only show the picker view if the touched on an a coin
       if([self isLocationCoin:lastLocationTouched] && totalValue == 0)
    {
        pickerView.hidden = NO;
        pickerToolBar.hidden = NO;
    
        //the deafult item chosen is penny
        if (lastPickerItemChosen == Nil)
        {
            lastPickerItemChosen = @"Penny";
        }
    }
}

//is the location touched a coin?
- (BOOL) isLocationCoin:(CGPoint)location
{
    int hitBoxHieght = 5;
    
    for(int i = 0; i < [coins count]; ++i)
    {
        float center_x = [[coins objectAtIndex:i] center_x_touch];
        float center_y  =[[coins objectAtIndex:i] center_y_touch];
        
        if(center_x > location.x - hitBoxHieght && center_x < location.x+ hitBoxHieght)
        {
            if(center_y > location.y - hitBoxHieght && center_y < location.y + hitBoxHieght)
            {
                return YES;
            }
        }

    }
    
    return NO;
}


//get the diameter of the coin based on the string that is based it
// Dime, Nickel, Quarter, or Penny
- (float) getDiameterOfCoinFromString:(NSString *)coinStr
{
    float result = -1;
    
    if(coinStr == @"Penny")
    {
        result =  19.05;
    }
    if(coinStr == @"Dime")
    {
        result = 17.91;
    }
    if(coinStr == @"Nickel")
    {
        result = 21.21;
    }
    if(coinStr == @"Quarter")
    {
        result = 24.26;
    }
    
    return result;
}



//calculate the value of the coins in the picture
- (void) calculateTotal
{
    //hide the pickerview stuff
    pickerToolBar.hidden = YES;
    pickerView.hidden = YES;
    
    float mmperpixel;
    
    int hitBoxHieght = 10;
    
    //float aspect_ratio = image.size.height / image.size.width;
    
    //find out which coin was picked on and use that to calculate the value of all othe other coins
    for(int i = 0; i < [coins count]; ++i)
    {
        float center_x = [[coins objectAtIndex:i] center_x_touch];
        float center_y  =[[coins objectAtIndex:i] center_y_touch];
        
        if(center_x > lastLocationTouched.x - hitBoxHieght && center_x < lastLocationTouched.x+ hitBoxHieght)
        {
            if(center_y > lastLocationTouched.y - hitBoxHieght && center_y < lastLocationTouched.y + hitBoxHieght)
            {
                //they touched a quarter, so let's figure out the mm per pixel
                printf("You touched on a %s \n", [[[coins objectAtIndex:i] coinValueString] UTF8String]  );
                
                float radius = [[coins objectAtIndex:i] radius];
                mmperpixel = [self getDiameterOfCoinFromString:lastPickerItemChosen] / radius;
                
                printf("mm per pixel: %.6f\n", mmperpixel);
                
            }
        }
        
    }
    
    totalValue = [self calculateValueWithMMinPxel:mmperpixel];
    printf("value %d\n", totalValue);
    [coinFinder drawCirclesAroundCoinsInPictureWithCoins:coins];
    [imageView setImage:[coinFinder getImageFromCVMat]];
    
    //[self showChangeResultAlert:value];


}
-(int) calculateValueWithMMinPxel:(float)mmperpixel
{
    
    //assign the value to all of the coins in the picture
    int value = 0;
    
    for(int i = 0; i < [coins count]; ++i)
    {
        Coin * coin = [coins objectAtIndex:i];
        
        float diameter = coin.radius *  mmperpixel;
        coin.diameterInMM = diameter;
        
        if(coin.coinValue != Penny)
        {
            [coinFinder assignValueToCoinBasedOnDiameter:coin];
            printf("%s Diameter %.2f\n", [[coin coinValueString] UTF8String], [coin diameterInMM]);
            
            switch (coin.coinValue)
            {
                case Quarter:
                    value += 25;
                    break;
                case Nickel:
                    value += 5;
                    break;
                case Dime:
                    value += 10;
                    break;
            }
        }
        else
        {
            value += 1;
        }
    }
    
    return value;
}


- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (IBAction)submitClicked:(id)sender {
    
    
    ///////////////////////////////////////
    UIActivityIndicatorView *spinner = [[UIActivityIndicatorView alloc] initWithActivityIndicatorStyle:UIActivityIndicatorViewStyleWhiteLarge];
    spinner.center = CGPointMake(160, 240);
    spinner.hidesWhenStopped = YES;
    [self.view addSubview:spinner];
    [spinner startAnimating];
    
    ////////////////////////////////////////
    
    
    /*    HACK ALERT      !!!!!!!!!!!!!
     
     We have to tell it to wait for a dealy because we want the spinner to show up, 
     which means we need to wait for the run loop to go around again so it will animate before
     we start blocking.
     
     We should probably move this over to another thread at another time
     */
    [self performSelector:@selector(startProcessImage:) withObject:spinner afterDelay:0.0];
   
    
    ///////////////////////////////////////
    //[spinner stopAnimating];
    
}

- (void) startProcessImage:(UIActivityIndicatorView *) alert
{
    [coinFinder setImageToProcess:image];
    image = [coinFinder getCoinsInImage];
    
    [imageView setImage:image];
    
    coins = coinFinder.CoinsFound;
    
    //if any of the coins are pennies, then we can skip the calibration and go straight to the calculating
    for(int i = 0; i < [coins count]; ++i)
    {
        Coin * tempCoin = [coins objectAtIndex:i];
        if (tempCoin.coinValue == Penny)
        {
            //do the calculation and then break
            float mminpixel = [self getDiameterOfCoinFromString:[tempCoin coinValueString]] / tempCoin.radius;
            totalValue = [self calculateValueWithMMinPxel:mminpixel];
            [coinFinder drawCirclesAroundCoinsInPictureWithCoins:coins];
            [imageView setImage:[coinFinder getImageFromCVMat]];
            [self showChangeResultAlert:totalValue];
            
            
            break;
        }
    }

    [alert stopAnimating];
}


- (void)dealloc{
    NSLog(@"hello");
}

- (IBAction)takePicture:(id)sender {
    
    UIAlertView * alert = [[UIAlertView alloc] initWithTitle:@"Information"
                                               message:@"For best results, hold camera as flat as possible"
                                                    delegate:self
                                               cancelButtonTitle:@"OK"
                                               otherButtonTitles:nil, nil];
    
    [alert show];
    
    
    UIImagePickerController *imagePicker =
    [[UIImagePickerController alloc] init];
    // If our device has a camera, we want to take a picture, otherwise, we
    // just pick from photo library
    if ([UIImagePickerController
         isSourceTypeAvailable:UIImagePickerControllerSourceTypeCamera]) {
        [imagePicker setSourceType:UIImagePickerControllerSourceTypeCamera];
    } else {
        [imagePicker setSourceType:UIImagePickerControllerSourceTypePhotoLibrary];
    }
    // This line of code will generate 2 warnings right now, ignore them
    
    [imagePicker setDelegate:self];
    
    imagePicker.cameraOverlayView = [[[self storyboard] instantiateViewControllerWithIdentifier:@"OverlayController"] view];
    
    //CameraOverlayViewController * overlayViewController = [[CameraOverlayViewController alloc] init];
   // overlayViewController.view = [[[self storyboard] instantiateViewControllerWithIdentifier:@"OverlayController"] view];
    
    imagePicker.cameraOverlayView = [[[self storyboard] instantiateViewControllerWithIdentifier:@"OverlayController"] view];
    imagePicker.cameraOverlayView.bounds = CGRectMake(100, 100, 128, 128);
    
    NSMutableDictionary * info = [[NSMutableDictionary alloc] init];
    [info setObject:[imagePicker view] forKey:@"view"];
    
    [NSTimer scheduledTimerWithTimeInterval:1.0 target:self selector:@selector(getMotionValues:) userInfo:info repeats:YES];
    
    
    motionManager.deviceMotionUpdateInterval = 0.05; //20hz
    [motionManager startDeviceMotionUpdates];
    
    // Place image picker on the screen
    [self presentModalViewController:imagePicker animated:YES];
    // The image picker will be retained by ItemDetailViewController
    // until it has been dismissed
}

- (IBAction)album:(id)sender {
    UIImagePickerController *imagePicker =
    [[UIImagePickerController alloc]init];
    if([UIImagePickerController
        isSourceTypeAvailable:UIImagePickerControllerSourceTypePhotoLibrary])
    {
        [imagePicker setSourceType:UIImagePickerControllerSourceTypePhotoLibrary];
    }
    // This line of code will generate 2 warnings right now, ignore them
    [imagePicker setDelegate:self];
    // Place image picker on the screen
    [self presentModalViewController:imagePicker animated:YES];
    // The image picker will be retained by ItemDetailViewController
    // until it has been dismissed
    
    //tell the motion manager to start collection data.
        
}

- (void)imagePickerController:(UIImagePickerController *)picker
didFinishPickingMediaWithInfo:(NSDictionary *)info{
    // Get picked image from info dictionary
    image = [info objectForKey:UIImagePickerControllerOriginalImage];
    // Put that image onto the screen in our image view
    [imageView setImage:image];
    // Take image picker off the screen -
    // you must call this dismiss method
    [self dismissModalViewControllerAnimated:YES];

    //clean up all of the timers and tell the phone to stop collection position data
    [motionManager stopDeviceMotionUpdates];
}

//show the alert for how much change was found in the picture
-(void) showChangeResultAlert:(NSInteger)result
{
    
    UIAlertView * alert = [[UIAlertView alloc] init];
    alert.alertViewStyle = UIAlertViewStyleDefault;
    [alert setTitle:@"Total"];
    [alert setMessage:[NSString stringWithFormat:@"%d cents", result]];
    [alert setDelegate:self];
    [alert addButtonWithTitle:@"Ok"];
    [alert addButtonWithTitle:@"More"];
    [alert show];

}

- (void)alertView:(UIAlertView *)alertView clickedButtonAtIndex:(NSInteger)buttonIndex
{
    if (buttonIndex == 1)
    {
        CoinTableViewController * vc = (CoinTableViewController *)[[self storyboard] instantiateViewControllerWithIdentifier:@"CoinTable"];
        
        [vc setCoins:coins];
        
        vc.modalPresentationStyle = UIModalPresentationFormSheet;
        [self presentViewController:vc animated:YES completion:nil];
    }
}

//get values from the gyroscope and such
- (void) getMotionValues:(NSTimer *) timer;
{
    NSMutableDictionary * dict = [timer userInfo];
    
    UIView * view = [dict objectForKey:@"view"];
    
    [self performSelector:@selector(changeColor:) withObject:view afterDelay:0.0];
    
    printf("%f\n",(180/M_PI)*motionManager.deviceMotion.attitude.pitch);

}

- (void) changeColor:(UIView *)view
{
    [view setBackgroundColor:[UIColor redColor]];
}

@end
