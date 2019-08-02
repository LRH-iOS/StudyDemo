//
//  CXAnswerCallAction.h
//  CallKit
//
//  Copyright © 2015 Apple. All rights reserved.
//

#import <CallKit/CXCallAction.h>

NS_ASSUME_NONNULL_BEGIN

CX_CLASS_AVAILABLE(ios(10.0))

/// CXAnswerCallAction类 ：接听
@interface CXAnswerCallAction : CXCallAction

/// Normally, providers can just call -[CXAction fulfill] to indicate action fulfillment. Use this method to note a specific date that the call connected. A call is considered connected when both caller and callee can start communicating.
/// 通常，提供程序只需调用-[cxaction full]来指示操作完成。
/// 使用此方法记下调用连接的特定日期。当呼叫者和被呼叫者都可以开始通信时，认为呼叫已连接。
- (void)fulfillWithDateConnected:(NSDate *)dateConnected;

@end

NS_ASSUME_NONNULL_END
