//
//  CXCallDirectory.h
//  CallKit
//
//  Copyright © 2016 Apple. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef int64_t CXCallDirectoryPhoneNumber;

/// 可以标识一个电话号码数组
static const CXCallDirectoryPhoneNumber CXCallDirectoryPhoneNumberMax = (INT64_MAX - 1);

NS_ASSUME_NONNULL_END
