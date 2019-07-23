//
//  NSArrayViewController.m
//  StudyDemo
//
//  Created by LRH on 2019/7/11.
//  Copyright © 2019 LRH. All rights reserved.
//

#import "NSArrayViewController.h"
#import "NSArrayModel.h"

@interface NSArrayViewController ()

@end

@implementation NSArrayViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    
    [self testNSArray];
    
    [self textNSMutableArray];
}

- (void)testNSArray
{
    NSArrayModel *model = [[NSArrayModel alloc]init];
    NSArrayModel *model1 = [[NSArrayModel alloc]init];
    NSArrayModel *model2 = [[NSArrayModel alloc]init];
    
    id objects[] = { model, @"hello world", @998 };
    NSUInteger count = sizeof(objects) / sizeof(id);
    
    NSArray *array1 = [[NSArray alloc] initWithObjects:@"1", model, @12, nil, nil];
    NSArray *array2 = [[NSArray alloc] initWithObjects:objects count:count];
    
    NSArray *array3 = [array2 arrayByAddingObject:@"123"];
    NSArray *array4 = [array3 arrayByAddingObjectsFromArray:array2];
    
    NSString *str1 = [array4 componentsJoinedByString:@","];
    
    BOOL bool1 = [array4 containsObject:model];
    
    NSLog(@"description=%@", array4.description);
    
    NSLog(@"description=%@", str1.debugDescription);
    
    NSString *str2 = [NSString stringWithFormat:@"123"];
    
    NSUInteger index = [array4 indexOfObject:str2];
    
    NSUInteger index4 = [array4 indexOfObjectIdenticalTo:str2];
    if (index4 == NSNotFound) {
        NSLog(@"找不到");
    }
    
    NSUInteger index3 = [array4 indexOfObjectIdenticalTo:@"12"];
    
    NSRange range = {1, 2};
    NSUInteger index2 = [array4 indexOfObject:@"123" inRange:range];
    
    //比较数组第一个元素是否相等
    NSArray *array5 = @[@"ass", @"123", @"app"];
    NSArray *array6 = @[@"ass1", @"oooo"];
    id object = [array5 firstObjectCommonWithArray:array6];
    
    //遍历数组指针
    NSArray *array7 = @[@"ass", @"123", @"app", @"12312312", @"543543"];
    NSEnumerator *enu = [array7 objectEnumerator];
    id obj;
    while ((obj = enu.nextObject)) {
        NSLog(@"从前往后遍历===%@==",obj);
    }
    NSEnumerator *enu2 = [array7 reverseObjectEnumerator];
    id obj2;
    while ((obj2 = enu2.nextObject)) {
        NSLog(@"从后往前遍历===%@==",obj2);
    }
    
    // 排序
    NSArray *array8 = [array7 sortedArrayUsingFunction:intSort context:nil];
    NSArray *array9 = [array7 sortedArrayUsingFunction:intSort context:nil hint:array7.sortedArrayHint];
    
    NSArray *array10 = [array7 sortedArrayUsingSelector:@selector(compare:)];
    
    NSLog(@"array8 = %@ \n array9 = %@ \n array10 = %@", array8, array9,array10);
    
    // 执行数组内对象的方法
    NSArray *array11 = @[model, model1, model2];
    [array11 enumerateObjectsUsingBlock:^(id  _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
        [obj jjjjjjjjj];
    }];
    
}

- (void)textNSMutableArray
{
    NSMutableArray *arr1 = [[NSMutableArray alloc] initWithObjects:@"123", @"sadsa", nil];
    NSMutableArray *arr2 = [[NSMutableArray alloc] initWithObjects:@"808", nil];
    
    [arr1 addObjectsFromArray:arr2];
    
    NSLog(@"arr1 = %@", arr1);
    
    [arr1 exchangeObjectAtIndex:1 withObjectAtIndex:2];
    
    NSLog(@"arr1 exchangeObjectAtIndex = %@", arr1);
}

NSInteger intSort(id num1, id num2, void *context)
{
    int v1 = [num1 intValue];
    int v2 = [num2 intValue];
    if (v1 < v2)
        return NSOrderedAscending;
    else if (v1 > v2)
        return NSOrderedDescending;
    else
        return NSOrderedSame;
}

@end
