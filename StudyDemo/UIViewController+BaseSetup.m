//
//  UIViewController+BaseSetup.m
//  StudyDemo
//
//  Created by LRH on 2019/7/10.
//  Copyright © 2019 LRH. All rights reserved.
//

#import "UIViewController+BaseSetup.h"

@implementation UIViewController (BaseSetup)

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wobjc-protocol-method-implementation"

- (void)viewDidLoad {

    // Do any additional setup after loading the view.
    
    self.title = NSStringFromClass(self.class);
    
    // 过滤操作
    Class class = NSClassFromString(@"UIInputWindowController");
    if (self.class != class) {
        self.view.backgroundColor = [UIColor groupTableViewBackgroundColor];
    }
}

#pragma clang diagnostic pop

@end
