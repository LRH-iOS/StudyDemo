//
//  CXStartCallAction.h
//  CallKit
//
//  Copyright © 2015 Apple. All rights reserved.
//

#import <CallKit/CXCallAction.h>

NS_ASSUME_NONNULL_BEGIN

@class CXHandle;

CX_CLASS_AVAILABLE(ios(10.0))

/// CXStartCallAction类 ：电话开始
@interface CXStartCallAction : CXCallAction

- (instancetype)initWithCallUUID:(NSUUID *)callUUID handle:(CXHandle *)handle NS_DESIGNATED_INITIALIZER;
- (nullable instancetype)initWithCoder:(NSCoder *)aDecoder NS_DESIGNATED_INITIALIZER;
- (instancetype)initWithCallUUID:(NSUUID *)callUUID NS_UNAVAILABLE;  // NS_UNAVAILABLE: 不可用

/// Handle for the party to call
@property (nonatomic, copy) CXHandle *handle;

/// 呼叫接收方的标识符
@property (nonatomic, copy, nullable) NSString *contactIdentifier;

/// 是否是视频电话
@property (nonatomic, getter=isVideo) BOOL video;

/// Normally, providers can just call -[CXAction fulfill] to indicate action fulfillment. Use this method to note a specific date that the call started if it is different from [NSDate date]. A call is considered started when its invitation has been sent to the remote callee.
/// 通常，提供程序只需调用-[cxaction full]来指示操作完成。
/// 使用此方法记下调用开始的特定日期（如果它与[nsdate date]不同）。当其邀请已发送到远程被呼叫方时，将认为呼叫已启动。
- (void)fulfillWithDateStarted:(NSDate *)dateStarted;

@end

NS_ASSUME_NONNULL_END
