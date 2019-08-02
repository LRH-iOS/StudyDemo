//
//  CXCallDirectoryManager.h
//  CallKit
//
//  Copyright © 2016 Apple. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CallKit/CXBase.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, CXCallDirectoryEnabledStatus) {
    CXCallDirectoryEnabledStatusUnknown = 0,            //未知
    CXCallDirectoryEnabledStatusDisabled = 1,           //未授权
    CXCallDirectoryEnabledStatusEnabled = 2,            //授权
} API_AVAILABLE(ios(10.0));

CX_CLASS_AVAILABLE(ios(10.0))

/// 电话目录管理
@interface CXCallDirectoryManager : NSObject

@property (readonly, class) CXCallDirectoryManager *sharedInstance;

/// 需要实时更新
- (void)reloadExtensionWithIdentifier:(NSString *)identifier completionHandler:(nullable void (^)(NSError *_Nullable error))completion;

/// 获取app extension的授权
//  identifier：app extension的bundleID
//  enabledStatus：授权状态：未授权-授权-不知道
- (void)getEnabledStatusForExtensionWithIdentifier:(NSString *)identifier completionHandler:(void (^)(CXCallDirectoryEnabledStatus enabledStatus, NSError *_Nullable error))completion;

@end

NS_ASSUME_NONNULL_END
