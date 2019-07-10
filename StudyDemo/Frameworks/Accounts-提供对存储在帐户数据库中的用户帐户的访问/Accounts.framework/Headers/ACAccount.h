//
//  ACAccount.h
//  Accounts
//
//  Copyright (c) 2011-2012 Apple Inc. All rights reserved.
//

/**
 * ACAccount对象封装有关存储在“帐户”数据库中的用户帐户的信息
 */
#import <Foundation/Foundation.h>
#import <Accounts/AccountsDefines.h>

@class ACAccountType, ACAccountCredential;

// The ACAccount class represents an account stored on the system.
// Accounts are created not bound to any store. Once an account is saved it belongs
// to the store it was saved into.

API_AVAILABLE(ios(5.0), macos(10.8))
@interface ACAccount : NSObject

// Creates a new account object with a specified account type.
- (instancetype)initWithAccountType:(ACAccountType *)type NS_DESIGNATED_INITIALIZER;

// This identifier can be used to look up the account using [ACAccountStore accountWithIdentifier:].
@property (readonly, weak, NS_NONATOMIC_IOSONLY) NSString      *identifier;

// Accounts are stored with a particular account type. All available accounts of a particular type
// can be looked up using [ACAccountStore accountsWithAccountType:]. When creating new accounts
// this property is required.
@property (strong, NS_NONATOMIC_IOSONLY)   ACAccountType       *accountType;

// A human readable description of the account.
// This property is only available to applications that have been granted access to the account by the user.
@property (copy, NS_NONATOMIC_IOSONLY)     NSString            *accountDescription;

// The username for the account. This property can be set and saved during account creation. The username is
// only available to applications that have been granted access to the account by the user.
// 帐户的用户名。此属性可以在创建帐户时设置和保存。用户名仅适用于已被用户授予访问帐户权限的应用程序。
@property (copy, NS_NONATOMIC_IOSONLY)     NSString            *username;

// For accounts that support it (currently only Facebook accounts), you can get the user's full name for display
// purposes without having to talk to the network.
// 对于支持它的帐户（当前仅限于Facebook帐户），您可以获取用户的全名进行显示无需与网络通信的目的。
@property (readonly, NS_NONATOMIC_IOSONLY)  NSString           *userFullName API_AVAILABLE(ios(7.0)) API_UNAVAILABLE(macos);

// The credential for the account. This property can be set and saved during account creation. It is
// inaccessible once the account has been saved.
// 帐户的凭据。此属性可以在创建帐户时设置和保存。保存帐户后无法访问。
@property (strong, NS_NONATOMIC_IOSONLY)   ACAccountCredential *credential;

@end
