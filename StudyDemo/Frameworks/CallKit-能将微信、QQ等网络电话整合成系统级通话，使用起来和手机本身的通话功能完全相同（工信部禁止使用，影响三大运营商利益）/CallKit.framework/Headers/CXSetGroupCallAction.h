//
//  CXSetGroupCallAction.h
//  CallKit
//
//  Copyright © 2015 Apple. All rights reserved.
//

#import <CallKit/CXCallAction.h>

NS_ASSUME_NONNULL_BEGIN

CX_CLASS_AVAILABLE(ios(10.0))

/// CXSetGroupCallAction类 ：群组电话
@interface CXSetGroupCallAction : CXCallAction

- (instancetype)initWithCallUUID:(NSUUID *)callUUID callUUIDToGroupWith:(nullable NSUUID *)callUUIDToGroupWith NS_DESIGNATED_INITIALIZER;
- (nullable instancetype)initWithCoder:(NSCoder *)aDecoder NS_DESIGNATED_INITIALIZER;
- (instancetype)initWithCallUUID:(NSUUID *)callUUID NS_UNAVAILABLE;

/// The UUID of another call to group with.
///
/// - If the call for this action's UUID is already in a group, it should leave that group if necessary.
/// - If nil, leave any group the call is currently in.
/// - 如果对该操作的UUID的调用已经在一个组中，则应在必要时离开该组。
/// - 如果为零，则保留呼叫当前所在的任何组。
@property (nonatomic, copy, nullable) NSUUID *callUUIDToGroupWith;

@end

NS_ASSUME_NONNULL_END
