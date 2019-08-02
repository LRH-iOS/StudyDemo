//
//  CXSetHeldCallAction.h
//  CallKit
//
//  Copyright © 2015 Apple. All rights reserved.
//

#import <CallKit/CXCallAction.h>

NS_ASSUME_NONNULL_BEGIN

CX_CLASS_AVAILABLE(ios(10.0))

///CXSetHeldCallAction类 ：暂停
@interface CXSetHeldCallAction : CXCallAction

- (instancetype)initWithCallUUID:(NSUUID *)callUUID onHold:(BOOL)onHold NS_DESIGNATED_INITIALIZER;
- (nullable instancetype)initWithCoder:(NSCoder *)aDecoder NS_DESIGNATED_INITIALIZER;
- (instancetype)initWithCallUUID:(NSUUID *)callUUID NS_UNAVAILABLE;

/// 是否被挂起
@property (nonatomic, getter=isOnHold) BOOL onHold;

@end

NS_ASSUME_NONNULL_END
