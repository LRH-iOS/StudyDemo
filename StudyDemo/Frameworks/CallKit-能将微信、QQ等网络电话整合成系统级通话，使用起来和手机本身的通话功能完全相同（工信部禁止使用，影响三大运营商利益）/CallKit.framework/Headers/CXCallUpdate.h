//
//  CXCallUpdate.h
//  CallKit
//
//  Copyright © 2015 Apple. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CallKit/CXBase.h>

NS_ASSUME_NONNULL_BEGIN

@class CXHandle;

// Any property that is not set will be ignored

CX_CLASS_AVAILABLE(ios(10.0))

/// 通话更新
@interface CXCallUpdate : NSObject <NSCopying>

/// Handle for the remote party (for an incoming call, the caller; for an outgoing call, the callee)
/// 通话对方的Handel信息
@property (nonatomic, copy, nullable) CXHandle *remoteHandle;

/// Override the computed caller name to a provider-defined value.
/// Normally the system will determine the appropriate caller name to display (e.g. using the user's contacts) based on the supplied caller identifier. Set this property to customize.
/// 对方的名字，可以设置为app注册的昵称
@property (nonatomic, copy, nullable) NSString *localizedCallerName;

/// Whether the call can be held on its own or swapped with another call
/// 通话过程中再来电，是否支持保留并接听
@property (nonatomic) BOOL supportsHolding;

/// Whether the call can be grouped (merged) with other calls when it is ungrouped
/// 通话是否可以加入一个群组
@property (nonatomic) BOOL supportsGrouping;

/// The call can be ungrouped (taken private) when it is grouped
/// 通话中当被加入群组时，是否可退出
@property (nonatomic) BOOL supportsUngrouping;

/// The call can send DTMF tones via hard pause digits or in-call keypad entries
/// 是否支持键盘拨号
@property (nonatomic) BOOL supportsDTMF;

/// The call includes video in addition to audio.
/// 本次通话是否有视频
@property (nonatomic) BOOL hasVideo;

@end

NS_ASSUME_NONNULL_END
