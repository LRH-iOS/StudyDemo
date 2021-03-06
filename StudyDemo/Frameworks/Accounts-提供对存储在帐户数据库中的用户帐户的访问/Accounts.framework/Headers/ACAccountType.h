//
//  ACAccountType.h
//  Accounts
//
//  Copyright (c) 2011-2012 Apple Inc. All rights reserved.
//

/**
 *  ACAccountType对象封装有关特定类型的所有帐户的信息。
 *  您不直接创建帐户类型对象。 要获取帐户类型，请使用 accountTypeWithAccountTypeIdentifier:方法或帐户对象的accountType属性。
 *  Account Type Identifiers描述当前支持的帐户类型的标识符。 您也可以使用accountsWithAccountType:方法来获取特定类型的所有帐户。
 */
#import <Foundation/Foundation.h>
#import <Accounts/AccountsDefines.h>

// The identifiers for supported system account types are listed here:
ACCOUNTS_EXTERN NSString * const ACAccountTypeIdentifierTwitter API_DEPRECATED("Use Twitter SDK instead", ios(5.0, 11.0), macos(10.8, 10.13));
ACCOUNTS_EXTERN NSString * const ACAccountTypeIdentifierFacebook API_DEPRECATED("Use Facebook SDK instead", ios(6.0, 11.0), macos(10.8, 10.13));
ACCOUNTS_EXTERN NSString * const ACAccountTypeIdentifierSinaWeibo API_DEPRECATED("Use Sina Weibo SDK instead", ios(6.0, 11.0), macos(10.8, 10.13));
ACCOUNTS_EXTERN NSString * const ACAccountTypeIdentifierTencentWeibo API_DEPRECATED("Use Tencent Weibo SDK instead", ios(7.0, 11.0), macos(10.9, 10.13));
ACCOUNTS_EXTERN NSString * const ACAccountTypeIdentifierLinkedIn API_DEPRECATED("Use LinkedIn SDK instead", macos(10.9, 10.13)) API_UNAVAILABLE(ios);

// Options dictionary keys for Facebook access, for use with [ACAccountStore requestAccessToAccountsWithType:options:completion:]
ACCOUNTS_EXTERN NSString * const ACFacebookAppIdKey API_DEPRECATED("Use Facebook SDK instead", ios(6.0, 11.0), macos(10.8, 10.13)); // Your Facebook App ID, as it appears on the Facebook website.
ACCOUNTS_EXTERN NSString * const ACFacebookPermissionsKey API_DEPRECATED("Use Facebook SDK instead", ios(6.0, 11.0), macos(10.8, 10.13)); // An array of of the permissions you're requesting.
ACCOUNTS_EXTERN NSString * const ACFacebookAudienceKey API_DEPRECATED("Use Facebook SDK instead", ios(6.0, 11.0), macos(10.8, 10.13)); // Only required when posting permissions are requested.

// Options dictionary values for Facebook access, for use with [ACAccountStore requestAccessToAccountsWithType:options:completion:]
ACCOUNTS_EXTERN NSString * const ACFacebookAudienceEveryone API_DEPRECATED("Use Facebook SDK instead", ios(6.0, 11.0), macos(10.8, 10.13)); // Posts from your app are visible to everyone.
ACCOUNTS_EXTERN NSString * const ACFacebookAudienceFriends API_DEPRECATED("Use Facebook SDK instead", ios(6.0, 11.0), macos(10.8, 10.13)); // Posts are visible only to friends.
ACCOUNTS_EXTERN NSString * const ACFacebookAudienceOnlyMe API_DEPRECATED("Use Facebook SDK instead", ios(6.0, 11.0), macos(10.8, 10.13)); // Posts are visible to the user only.

// Options dictionary keys for LinkedIn access, for use with [ACAccountStore requestAccessToAccountsWithType:options:completion:]
ACCOUNTS_EXTERN NSString * const ACLinkedInAppIdKey API_DEPRECATED("Use LinkedIn SDK instead", macos(10.9, 10.13)) API_UNAVAILABLE(ios); // Your LinkedIn App ID (or API Key), as it appears on the LinkedIn website.
ACCOUNTS_EXTERN NSString * const ACLinkedInPermissionsKey API_DEPRECATED("Use LinkedIn SDK instead", macos(10.9, 10.13)) API_UNAVAILABLE(ios); // An array of of the LinkedIn permissions you're requesting.

ACCOUNTS_EXTERN NSString * const ACTencentWeiboAppIdKey API_DEPRECATED("Use Tencent Weibo SDK instead", ios(7.0, 11.0), macos(10.9, 10.13)); // Tencent App ID

// Each account has an associated account type, containing information relevant to all the accounts of that type.
// ACAccountType objects are obtained by using the [ACAccountStore accountTypeWithIdentifier:] method
// or accessing the accountType property for a particular account object. They may also be used to find
// all the accounts of a particular type using [ACAccountStore accountsWithAccountType:]

API_AVAILABLE(ios(5.0), macos(10.8))
@interface ACAccountType : NSObject

// A human readable description of the account type.
// 账户描述
@property (readonly, nonatomic) NSString *accountTypeDescription;

// A unique identifier for the account type. Well known system account type identifiers are listed above.
@property (readonly, nonatomic) NSString *identifier;

// A boolean indicating whether the user has granted access to accounts of this type for your application.
// 指示用户是否已为您的应用程序授予此类型帐户的访问权限。
@property (readonly, nonatomic) BOOL     accessGranted;

@end
