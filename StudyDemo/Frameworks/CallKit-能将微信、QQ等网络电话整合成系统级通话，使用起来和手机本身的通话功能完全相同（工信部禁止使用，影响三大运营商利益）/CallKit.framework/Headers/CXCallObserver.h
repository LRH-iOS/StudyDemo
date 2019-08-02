//
//  CXCallObserver.h
//  CallKit
//
//  Copyright © 2016 Apple. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CallKit/CXBase.h>

NS_ASSUME_NONNULL_BEGIN

@class CXCall;
@class CXCallObserver;

@protocol CXCallObserverDelegate <NSObject>

- (void)callObserver:(CXCallObserver *)callObserver callChanged:(CXCall *)call;

@end

CX_CLASS_AVAILABLE(ios(10.0))

/// CXCallObserver: 随时捕获电话信息的更新
@interface CXCallObserver : NSObject

/// Retrieve the current call list, blocking on initial state retrieval if necessary
/// 返回当前呼叫列表
@property (nonatomic, readonly, copy) NSArray<CXCall *> *calls;

/// Set delegate and optional queue for delegate callbacks to be performed on.
/// A nil queue implies that delegate callbacks should happen on the main queue. The delegate is stored weakly
- (void)setDelegate:(nullable id<CXCallObserverDelegate>)delegate queue:(nullable dispatch_queue_t)queue;

@end

NS_ASSUME_NONNULL_END
