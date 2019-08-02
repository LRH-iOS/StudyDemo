//
//  CXProviderConfiguration.h
//  CallKit
//
//  Copyright © 2016 Apple. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CallKit/CXBase.h>

NS_ASSUME_NONNULL_BEGIN

CX_CLASS_AVAILABLE(ios(10.0))

/// 配置类
@interface CXProviderConfiguration : NSObject <NSCopying>

/// Localized name of the provider
/// 获取系统来电页面显示的app名称和系统通讯记录的信息
@property (nonatomic, readonly, copy) NSString *localizedName;

/// Name of resource in app's bundle to play as ringtone for incoming call
/// 来电铃声（在app的bundel中的）
@property (nonatomic, strong, nullable) NSString *ringtoneSound;

/// 锁屏接听时系统界面右下角app图标，要40x40大小
@property (nonatomic, copy, nullable) NSData *iconTemplateImageData; // Image should be a square with side length of 40 points

/// 最大通话组
@property (nonatomic) NSUInteger maximumCallGroups; // Default 2

/// 每个通话组的最大呼叫次数，默认 5
@property (nonatomic) NSUInteger maximumCallsPerCallGroup; // Default 5

/// Whether this provider's calls should be included in the system's Recents list at the end of each call.
/// Default: YES
/// 每个通话结束是否显示在系统最近通话列表，默认YES
@property (nonatomic) BOOL includesCallsInRecents API_AVAILABLE(ios(11.0));

/// 是否支持视频，默认NO
@property (nonatomic) BOOL supportsVideo; // Default NO

// Numbers are of type CXHandleType
@property (nonatomic, copy) NSSet<NSNumber *> *supportedHandleTypes;

- (instancetype)initWithLocalizedName:(NSString *)localizedName NS_DESIGNATED_INITIALIZER;
- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
