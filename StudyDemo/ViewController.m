//
//  ViewController.m
//  StudyDemo
//
//  Created by LRH on 2019/5/14.
//  Copyright © 2019 LRH. All rights reserved.
//

#import "ViewController.h"
#import "AccountsViewController.h"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    
    
    [self.navigationController pushViewController:[[AccountsViewController alloc] init] animated:YES];
    
}


@end
