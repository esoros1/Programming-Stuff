//
//  CoinTableViewController.h
//  Pkt Change
//
//  Created by Eric Soros on 4/15/13.
//  Copyright (c) 2013 Jake Tobin. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface CoinTableViewController : UIViewController <UITableViewDataSource, UITableViewDelegate>
{
    NSArray * coins;
    
    NSMutableArray * pennies;
    NSMutableArray * dimes;
    NSMutableArray * nickels;
    NSMutableArray * quarters;
}
@property IBOutlet UITableView * tableView;

- (IBAction)onDismissPress:(id)sender;

- (void) setCoins:(NSArray *) coinArray;



@end
