//
//  CXPlayDTMFCallAction.h
//  CallKit
//
//  Copyright © 2015 Apple. All rights reserved.
//

#import <CallKit/CXCallAction.h>

typedef NS_ENUM(NSInteger, CXPlayDTMFCallActionType) {
    CXPlayDTMFCallActionTypeSingleTone = 1, // The user tapped a digit on the in-call keypad  用户在通话键盘上点击了一个数字。
    CXPlayDTMFCallActionTypeSoftPause = 2, // The user included digits after a soft pause in their dial string 用户在拨号字符串中软暂停后包含数字。
    CXPlayDTMFCallActionTypeHardPause = 3, // The user included digits after a hard pause in their dial string 用户在拨号字符串中硬暂停后包含数字。
} API_AVAILABLE(ios(10.0));

NS_ASSUME_NONNULL_BEGIN

CX_CLASS_AVAILABLE(ios(10.0))

/// CXPlayDTMFCallAction类 ：双频多音功能
@interface CXPlayDTMFCallAction : CXCallAction

- (instancetype)initWithCallUUID:(NSUUID *)callUUID digits:(NSString *)digits type:(CXPlayDTMFCallActionType)type NS_DESIGNATED_INITIALIZER;
- (nullable instancetype)initWithCoder:(NSCoder *)aDecoder NS_DESIGNATED_INITIALIZER;
- (instancetype)initWithCallUUID:(NSUUID *)callUUID NS_UNAVAILABLE;

// The string representation of the digits that should be played as DTMF tones
// 应作为DTMF音调播放的数字的字符串表示形式
@property (nonatomic, copy) NSString *digits;

// Whether or not the string of digits represents tones following a hard or soft pause
// 是否表示硬暂停或软暂停后的音调
@property (nonatomic) CXPlayDTMFCallActionType type;

@end

NS_ASSUME_NONNULL_END
