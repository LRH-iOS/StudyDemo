/*	NSAutoreleasePool.h
	Copyright (c) 1994-2018, Apple Inc. All rights reserved.
*/

/*
 *  NSAutoreleasePool是什么？
 *  实际上是个对象引用计数自动处理器，在官方文档中被称为是一个类。它的组织是个栈，总是存在一个栈顶 pool，每创建一个 pool，就往栈里压，并替换栈顶；drain 消息，则就弹出栈顶的 pool。
 *  Autorelease 实际上只是把对 release 的调用延迟了，对于每一个 Autorelease，系统只是把该 Object 放入了当 前的 Autorelease pool 中，当该 pool(池)被释放时，该 pool 中的所有 Object 会被调用 Release。
 */
/*
 *  autorelease 释放的具体原理是什么？
 *  1.系统在 main()调用的时候会自动调用一个 autorelease，在每一个Runloop，  系统也会隐式创建一个Autorelease pool；
 *  2.所有的 release pool 会构成一个像 CallStack(调用栈) 一样的一个栈式结构。一个 Runloop 结束，当前栈顶的 Autorelease pool 会被销毁，这样这个 pool 里的每个 Object 会收到 release。(autorelease 的释放时间)
 *  main()的 autorelease 与 autorelease pool：
 
 *  3、Runloop 与 autorelease pool？
 *  main()创建了父类，每个Runloop自动生成的或自定义的 autorelease pool 都会成为该父类的子类，父类被释放的时候，没有被释放的子类也会被释放；
 *  这样所有子类中的对象也会收到release消息。
 */
#import <Foundation/NSObject.h>

NS_ASSUME_NONNULL_BEGIN

NS_AUTOMATED_REFCOUNT_UNAVAILABLE
@interface NSAutoreleasePool : NSObject {
@private
    void	*_token;
    void	*_reserved3;
    void	*_reserved2;
    void	*_reserved;
}

+ (void)addObject:(id)anObject;

- (void)addObject:(id)anObject;

// 销毁自动释放池
- (void)drain;

@end

NS_ASSUME_NONNULL_END
