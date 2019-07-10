//
//  AccountsViewController.m
//  StudyDemo
//
//  Created by LRH on 2019/7/10.
//  Copyright © 2019 LRH. All rights reserved.
//

#import "AccountsViewController.h"
#import <Accounts/Accounts.h>

@interface AccountsViewController ()

@end

@implementation AccountsViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    
    [self setupAccounts];
}

- (void)setupAccounts
{
    //创建操作对象
    ACAccountStore *store = [[ACAccountStore alloc] init];
    //通过操作对象 构建社交平台类型示例  这里采用的新浪微博
    ACAccountType *type = [store accountsWithAccountType:ACAccountTypeIdentifierSinaWeibo];
    //进行用户授权请求
    [store requestAccessToAccountsWithType:type options:nil completion:^(BOOL granted, NSError *error) {
        if (error) {
            NSLog(@"error = %@",error.localizedDescription);
        } else {
            dispatch_async(dispatch_get_main_queue(), ^{
                NSLog(@"授权通过");
                //一旦用户授权通过，可以使用如下方法获取到用户的社交平台账户信息：
                [self getAccountsDataStore:store type:type];
            });
        }
    }];
}

- (void)getAccountsDataStore:(ACAccountStore *)store type:(ACAccountType *)type
{
    NSArray *accounts = [store accountsWithAccountType:type];
    
    
}

@end
