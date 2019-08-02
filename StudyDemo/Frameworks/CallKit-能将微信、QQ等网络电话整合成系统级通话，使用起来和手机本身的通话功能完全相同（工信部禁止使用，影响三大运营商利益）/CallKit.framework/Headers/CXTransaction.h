//
//  CXTransaction.h
//  CallKit
//
//  Copyright © 2015 Apple. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CallKit/CXBase.h>

NS_ASSUME_NONNULL_BEGIN

@class CXAction;

CX_CLASS_AVAILABLE(ios(10.0))

/// CXTransaction类 ：用户的任何操作（CXAction）被包装成CXTransaction，然后丢给CXCallController通知系统
@interface CXTransaction : NSObject <NSCopying, NSSecureCoding>

/// Unique ID
@property (nonatomic, readonly, copy) NSUUID *UUID;

/// Whether all actions have been completed
/// 所有的CXAction是否已经完成
@property (nonatomic, readonly, assign, getter=isComplete) BOOL complete;

/// The list of actions contained by the receiver
/// 获取CXAction列表
@property (nonatomic, readonly, copy) NSArray<__kindof CXAction *> *actions;

- (instancetype)initWithActions:(NSArray<CXAction *> *)actions NS_DESIGNATED_INITIALIZER;
- (instancetype)initWithAction:(CXAction *)action;

/// Add the provided action to the receiver's list of actions
- (void)addAction:(CXAction *)action;

@end

NS_ASSUME_NONNULL_END
