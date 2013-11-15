//
//  ViewController.m
//  Button
//
//  Created by BloomingKids Software on 11/15/13.
//  Copyright (c) 2013 BloomingKids Software. All rights reserved.
//

#import "ViewController.h"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
	    
    UIButton *button = [UIButton buttonWithType:UIButtonTypeRoundedRect];
    button.frame = CGRectMake(400, 300, 259, 93);
    [button setTitle:@"" forState:UIControlStateNormal];
    [button setImage:[UIImage imageNamed:@"Start.jpg"] forState:UIControlStateNormal];

    [button setImage:[UIImage imageNamed:@"Start+2.jpg"] forState:UIControlStateHighlighted];

    [self.view addSubview:button];
}


@end
