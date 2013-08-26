//
//  CoinTableViewController.m
//  Pkt Change
//
//  Created by Eric Soros on 4/15/13.
//  Copyright (c) 2013 Jake Tobin. All rights reserved.
//

#import "CoinTableViewController.h"
#import "Coin.h"
@interface CoinTableViewController ()

@end

@implementation CoinTableViewController

@synthesize tableView;

- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil
{
    self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];
    if (self) {
        // Custom initialization     
    
       
    
    }
    return self;
}

- (void)viewDidLoad
{
    [super viewDidLoad];
	// Do any additional setup after loading the view.
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}


- (IBAction)onDismissPress:(id)sender
{
    [self dismissViewControllerAnimated:YES completion:nil];
}


//table view protocol stuff

//how many sections in the table
- (NSInteger) numberOfSectionsInTableView:(UITableView *)tableView
{
    return 4;
}

//how many rows in the table
- (NSInteger) tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section
{
    if(section == 0)
    {
        return [pennies count];
    }
    if(section == 1)
    {
        return [nickels count];
    }
    if(section == 2)
    {
        return [dimes count];
    }
    if(section == 3)
    {
        return [quarters count];
    }
}


//return the cell for the certain row
- (UITableViewCell *) tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath
{
    UITableViewCell *cell = [[UITableViewCell alloc]
                             initWithStyle:UITableViewCellStyleSubtitle
                             reuseIdentifier:@"UITableViewCell"];
    
    Coin * tempCoin;
    
    if(indexPath.section == 0)
    {
        tempCoin = [pennies objectAtIndex:indexPath.row];
    }
    
    if (indexPath.section == 1)
    {
        tempCoin = [nickels objectAtIndex:indexPath.row];
    }
    
    if (indexPath.section == 2)
    {
        tempCoin = [dimes objectAtIndex:indexPath.row];
    }
    
    if (indexPath.section == 3)
    {
        tempCoin = [quarters objectAtIndex:indexPath.row];
    }
    
   //cell.textLabel.text = [tempCoin coinValueString];
    cell.detailTextLabel.text = [NSString stringWithFormat:@"Center:(%.2f , %.2f) - Radius:%.2f px",
                            tempCoin.center_x_touch, tempCoin.center_y_touch, tempCoin.radius];
    
   
    
    return cell;
}


-(NSString *) tableView:(UITableView *)tableView titleForHeaderInSection:(NSInteger)section
{
    NSString * result;
    
    if(section == 0)
    {
        result = @"Pennies";
    }
    else if (section == 1)
    {
        result = @"Nickels";
    }
    else if (section == 2)
    {
        result = @"Dimes";
    }
    else
    {
        result = @"Quarters";
    }
    
    return result;
}


- (void) setCoins:(NSArray *)coinArray
{
    coins = coinArray;
    
    
    pennies = [[NSMutableArray alloc]init];
    dimes = [[NSMutableArray alloc] init];
    nickels = [[NSMutableArray alloc] init];
    quarters = [[NSMutableArray alloc] init];
    
    //now split the coins into four bins so we can have three sections on the table
    for(Coin * coin in coins)
    {
        switch (coin.coinValue)
        {
                
            case Penny:
                [pennies addObject:coin];
                break;
            case Nickel:
                [nickels addObject:coin];
                break;
            case Dime:
                [dimes addObject:coin];
                break;
            case Quarter:
                [quarters addObject:coin];
                break;
        }
    }
    
}

@end
