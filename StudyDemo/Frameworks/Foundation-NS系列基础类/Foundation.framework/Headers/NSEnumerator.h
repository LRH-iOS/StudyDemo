/*	NSEnumerator.h
 Copyright (c) 1995-2018, Apple Inc. All rights reserved.
 */

#import <Foundation/NSObject.h>

@class NSArray<ObjectType>;

NS_ASSUME_NONNULL_BEGIN

/*
 * The fast enumeration protocol NSFastEnumeration is adopted and
 * implemented by objects wishing to make use of a fast and safe
 * enumeration style.  The language "foreach" construct then can
 * be used with such objects.
 *
 * The abstract class NSEnumerator itself is taught how to do this
 * for convenience by using -nextObject to return items one at a time.
 */

typedef struct {
    unsigned long state;
    id __unsafe_unretained _Nullable * _Nullable itemsPtr;
    unsigned long * _Nullable mutationsPtr;
    unsigned long extra[5];
} NSFastEnumerationState;

/**
 * 快速遍历
 * forin是通过外部传入一个缓冲数组，在countByEnumeratingWithState方法体内通过外部的不断循环调用根据state状态重复填充缓冲区数组并返回结果。
 * 背后遍历使用的是原始的循环结构do-while 2.数组的下标索引+原始的do-while/while循环结构如何实现数组的遍历
 * 具体可见：https://www.jianshu.com/p/2ec49d525871
 */
@protocol NSFastEnumeration

- (NSUInteger)countByEnumeratingWithState:(NSFastEnumerationState *)state objects:(id __unsafe_unretained _Nullable [_Nonnull])buffer count:(NSUInteger)len;

/**
 * 分析一下实现代码发现
 1.countByEnumeratingWithState方法的实现有两种方式，例子代码中使用宏USE_STACKBUF进行了区分，两种方式的主要区别是：第一种方式是利用了参数中的缓冲数组，第二种方式没有使用缓冲数组而是直接持有了原数组的一个弱引用。第二种是不安全的，因此大多情况的实现应该是使用第一中方式。
 2.仔细阅读第一种方式的实现代码，可以看出：
    a.countByEnumeratingWithState肯定是被外部循环调用的，使用结构体指针NSFastEnumerationState记录当前最新的遍历状态，循环的次数取决于参数stackbufLength缓冲区的大小。
    b.NSFastEnumerationState中state用来记录最后遍历的位置，itemsPtr指向缓冲区数组,mutationsPtr和extra是用来检测和控制原始数组改变的。
    c.当最终返回'count = 0'是表示遍历结束。
 */

/**
 内部实现方法
 #define USE_STACKBUF 1
 
 - (NSUInteger)countByEnumeratingWithState:(NSFastEnumerationState *)state
 objects:(id __unsafe_unretained [])stackbuf
 count:(NSUInteger)stackbufLength
 {
 NSUInteger count = 0;
 unsigned long countOfItemsAlreadyEnumerated = state->state;
 
 if(countOfItemsAlreadyEnumerated == 0)
 {
 state->mutationsPtr = &state->extra[0];
 }
 
 #if USE_STACKBUF // Method One.
 
 if(countOfItemsAlreadyEnumerated < _list.size())
 {
 state->itemsPtr = stackbuf;
 while((countOfItemsAlreadyEnumerated < _list.size()) && (count < stackbufLength))
 {
 stackbuf[count] = _list[countOfItemsAlreadyEnumerated];
 countOfItemsAlreadyEnumerated++;
 
 count++;
 }
 }
 else
 {
 count = 0;
 }
 
 #else // Method Two.
 if (countOfItemsAlreadyEnumerated < _list.size())
 {
 __unsafe_unretained const id * const_array = _list.data();
 state->itemsPtr = (__typeof__(state->itemsPtr))const_array;
 
 count = _list.size();
 
 countOfItemsAlreadyEnumerated = _list.size();
 }
 else
 {
 count = 0;
 }
 #endif
 state->state = countOfItemsAlreadyEnumerated;
 return count;
 }
 */

@end

@interface NSEnumerator<ObjectType> : NSObject <NSFastEnumeration>

- (nullable ObjectType)nextObject;

@end

@interface NSEnumerator<ObjectType> (NSExtendedEnumerator)

@property (readonly, copy) NSArray<ObjectType> *allObjects;

@end

NS_ASSUME_NONNULL_END
