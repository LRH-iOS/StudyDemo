//
//  CXCall.h
//  CallKit
//
//  Copyright © 2016 Apple. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CallKit/CXBase.h>

NS_ASSUME_NONNULL_BEGIN

CX_CLASS_AVAILABLE(ios(10.0))

/// CXCall类：电话信息类
@interface CXCall : NSObject

/// 唯一通过这个ID可以定位到特定时刻的特定号码的来电信息
@property (nonatomic, readonly, copy) NSUUID *UUID;

/// 是否是自己拨打的
@property (nonatomic, readonly, assign, getter=isOutgoing) BOOL outgoing;

/// 电话是否挂起
@property (nonatomic, readonly, assign, getter=isOnHold) BOOL onHold;

/// 电话是否接通
@property (nonatomic, readonly, assign) BOOL hasConnected;

/// 电话是否结束
@property (nonatomic, readonly, assign) BOOL hasEnded;

- (instancetype)init NS_UNAVAILABLE;

- (BOOL)isEqualToCall:(CXCall *)call NS_SWIFT_UNAVAILABLE("Use == operator instead");

@end

NS_ASSUME_NONNULL_END
