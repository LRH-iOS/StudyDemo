//
//  CXCallController.h
//  CallKit
//
//  Copyright © 2015 Apple. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CallKit/CXBase.h>

NS_ASSUME_NONNULL_BEGIN

@class CXAction;
@class CXCallObserver;
@class CXTransaction;

CX_CLASS_AVAILABLE(ios(10.0))
@interface CXCallController : NSObject

/// Initialize call controller with a private, serial queue.
/// 在私有串行队列创建
- (instancetype)init;

/// Initialize call controller with specified queue, which is used for calling completion blocks.
/// 指定队列里创建.默认主线程 //指定使用
- (instancetype)initWithQueue:(dispatch_queue_t)queue NS_DESIGNATED_INITIALIZER;

/// 电话信息观察者
@property (nonatomic, readonly, strong) CXCallObserver *callObserver;


//以下三个方法：将CXTransaction传递给系统，如果error为空，将调起CXProvider类的-provider:executeTransaction: 代理方法

/// Request a transaction to be performed by the in-app provider.
///
/// If the completion block is called with a nil error, then the transaction will be passed to the CXProvider's -provider:executeTransaction: delegate callback.
/// A non-nil error indicates that the requested transaction could not be executed.
///
/// Completion block is performed on the queue supplied to designated initializer.
- (void)requestTransaction:(CXTransaction *)transaction completion:(void (^)(NSError *_Nullable error))completion;

/// Request a transaction containing the specified actions to be performed by the in-app provider.
///
/// If the completion block is called with a nil error, then the transaction will be passed to the CXProvider's -provider:executeTransaction: delegate callback.
/// A non-nil error indicates that the requested transaction could not be executed.
///
/// Completion block is performed on the queue supplied to designated initializer.
- (void)requestTransactionWithActions:(NSArray<CXAction *> *)actions completion:(void (^)(NSError *_Nullable error))completion API_AVAILABLE(ios(11.0));

/// Request a transaction containing the specified action to be performed by the in-app provider.
///
/// If the completion block is called with a nil error, then the transaction will be passed to the CXProvider's -provider:executeTransaction: delegate callback.
/// A non-nil error indicates that the requested transaction could not be executed.
///
/// Completion block is performed on the queue supplied to designated initializer.
- (void)requestTransactionWithAction:(CXAction *)action completion:(void (^)(NSError *_Nullable error))completion API_AVAILABLE(ios(11.0));

@end

NS_ASSUME_NONNULL_END
