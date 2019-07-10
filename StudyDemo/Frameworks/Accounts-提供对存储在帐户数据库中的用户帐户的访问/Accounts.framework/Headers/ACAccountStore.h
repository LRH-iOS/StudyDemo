//
//  ACAccountStore.h
//  Accounts
//
//  Copyright (c) 2011-2012 Apple Inc. All rights reserved.
//

/**
 *  ACAccountStore类提供了一个用于访问，操作和存储帐户的接口。
 *  要从“帐户”数据库创建和检索帐户，您必须创建一个ACAccountStore对象。 每个ACAccount对象都属于一个ACAccountStore对象。
 */
#import <Foundation/Foundation.h>
#import <Accounts/AccountsDefines.h>

typedef NS_ENUM(NSInteger, ACAccountCredentialRenewResult) {
    ACAccountCredentialRenewResultRenewed,  // A new credential was obtained and is now associated with the account. //获得了一个新凭据，现在与该帐户关联
    ACAccountCredentialRenewResultRejected, // Renewal failed because of a user-initiated action. //由于用户启动的操作，续订失败。
    ACAccountCredentialRenewResultFailed,   // A non-user-initiated cancel of the prompt.  //非用户启动的取消提示
};

typedef void(^ACAccountStoreSaveCompletionHandler)(BOOL success, NSError *error);
typedef void(^ACAccountStoreRemoveCompletionHandler)(BOOL success, NSError *error);
typedef void(^ACAccountStoreRequestAccessCompletionHandler)(BOOL granted, NSError *error);
typedef void(^ACAccountStoreCredentialRenewalHandler)(ACAccountCredentialRenewResult renewResult, NSError *error);

@class ACAccount, ACAccountType;

// The ACAccountStore class provides an interface for accessing and manipulating
// accounts. You must create an ACAccountStore object to retrieve, add and delete
// accounts from the Accounts database.
//
// IMPORTANT NOTE: You MUST keep the account store around for as long as you have
// any objects fetched from that store if you expect other 'sub-fetches' to work,
// most notably being fetching credentials. If you really just want to open the
// store to grab credentials, just be sure to grab the credential object and then
// you can release the owning account and store, e.g.

API_AVAILABLE(ios(5.0), macos(10.8))
@interface ACAccountStore : NSObject

// An array of all the accounts in an account database
@property (readonly, weak, NS_NONATOMIC_IOSONLY) NSArray *accounts;

// Returns the account matching the given account identifier
- (ACAccount *)accountWithIdentifier:(NSString *)identifier;

// Returns the account type object matching the account type identifier. See
// ACAccountType.h for well known account type identifiers
- (ACAccountType *)accountTypeWithAccountTypeIdentifier:(NSString *)typeIdentifier;

// Returns the accounts matching a given account type.
- (NSArray *)accountsWithAccountType:(ACAccountType *)accountType;

// Saves the account to the account database. If the account is unauthenticated and the associated account
// type supports authentication, the system will attempt to authenticate with the credentials provided.
// Assuming a successful authentication, the account will be saved to the account store. The completion handler
// for this method is called on an arbitrary queue.
- (void)saveAccount:(ACAccount *)account withCompletionHandler:(ACAccountStoreSaveCompletionHandler)completionHandler;

// DEPRECATED: Please use requestAccessToAccountsWithType:options:completion: instead.
- (void)requestAccessToAccountsWithType:(ACAccountType *)accountType withCompletionHandler:(ACAccountStoreRequestAccessCompletionHandler)handler API_DEPRECATED_WITH_REPLACEMENT("-requestAccessToAccountsWithType:options:completion:", ios(5.0, 6.0)) API_UNAVAILABLE(macos);

// Obtains permission, if necessary, from the user to access protected properties, and utilize accounts
// of a particular type in protected operations, for example OAuth signing. The completion handler for 
// this method is called on an arbitrary queue.
// Certain account types (such as Facebook) require an options dictionary. A list of the required keys
// appears in ACAccountType.h. This method will throw an NSInvalidArgumentException if the options
// dictionary is not provided for such account types. Conversely, if the account type does not require
// an options dictionary, the options parameter must be nil.
// 在调用requestAccessToAccountsWithType方法时，options 可以传入一个字典参数，某些社交平台的授权需要配置一些额外参数
- (void)requestAccessToAccountsWithType:(ACAccountType *)accountType options:(NSDictionary *)options completion:(ACAccountStoreRequestAccessCompletionHandler)completion;

// Call this if you discover that an ACAccount's credential is no longer valid.
// For Twitter and Sina Weibo accounts, this method will prompt the user to go to Settings to re-enter their password.
// For Facebook accounts, if your access token became invalid due to regular expiration, this method will obtain a new one.
// However, if the user has deauthorized your app, this renewal request will return ACAccountCredentialRenewResultRejected.
// 如果发现acaccount的凭据不再有效，则调用此函数。
// 对于Twitter和新浪微博账号，该方法会提示用户进入设置，重新输入密码。
// 对于facebook账户，如果您的访问令牌因定期到期而失效，该方法将获得一个新的访问令牌。
// 但是，如果用户已重新授权您的应用程序，则此续订请求将返回AcaccountCredentialRenewResultRejected。
- (void)renewCredentialsForAccount:(ACAccount *)account completion:(ACAccountStoreCredentialRenewalHandler)completionHandler;

// Removes an account from the account store. The completion handler for this method is called on an arbitrary queue.
// This call will fail if you don't have sufficient rights to remove the account in question.
// 从帐户存储中删除帐户。在任意队列上调用此方法的完成处理程序。
// 如果您没有足够的权限删除相关帐户，则此调用将失败。
- (void)removeAccount:(ACAccount *)account withCompletionHandler:(ACAccountStoreRemoveCompletionHandler)completionHandler;

@end

// Notification name sent out when the database is changed by an external process, another account store
// in the same process or by calling saveAccount: or removeAccount: on a store you are managing. When this
// notification is received, you should consider all ACAccount instances you have to be invalid. Purge current
// instances of ACAccount and obtain new instances using the account store. You may need to deal with accounts
// being removed by an external process while you are using them.
ACCOUNTS_EXTERN NSString * const ACAccountStoreDidChangeNotification API_AVAILABLE(ios(5.0), macos(10.8));
