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
	    
    button = [UIButton buttonWithType:UIButtonTypeRoundedRect];
    button.frame = CGRectMake(400, 300, 259, 93);
    [button setTitle:@"" forState:UIControlStateNormal];
    
    [button addTarget:self action:@selector(buttonFunction) forControlEvents:UIControlEventTouchUpInside];
    
    [button setImage:[UIImage imageNamed:@"Start.jpg"] forState:UIControlStateNormal];

    [button setImage:[UIImage imageNamed:@"Start+2.jpg"] forState:UIControlStateHighlighted];

    [self.view addSubview:button];
}

-(void)buttonFunction {
    
    [button removeFromSuperview];
    
    textView = [[UITextView alloc] initWithFrame:CGRectMake(400, 300, 259, 93)];
    
    textView.textAlignment =  NSTextAlignmentCenter;
    textView.textColor = [UIColor blackColor];
    textView.backgroundColor = [UIColor whiteColor];
    [textView setFont:[UIFont fontWithName:@"ArialMT" size:22]];
    textView.clipsToBounds = YES;
    textView.userInteractionEnabled = NO;
    
    textView.text = @"My Text View";
    [self.view  addSubview:textView];
}


@end
