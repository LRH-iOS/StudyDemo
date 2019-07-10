//
//  ACError.h
//  Accounts
//
//  Copyright (c) 2011-2012 Apple Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <Accounts/AccountsDefines.h>

ACCOUNTS_EXTERN NSString * const ACErrorDomain API_AVAILABLE(ios(5.0), macos(10.8));

typedef enum ACErrorCode {
    ACErrorUnknown = 1,
    ACErrorAccountMissingRequiredProperty,  // Account wasn't saved because it is missing a required property.                  //保存失败：缺少必需的属性
    ACErrorAccountAuthenticationFailed,     // Account wasn't saved because authentication of the supplied credential failed.   //保存失败：提供的凭据的身份验证失败
    ACErrorAccountTypeInvalid,              // Account wasn't saved because the account type is invalid.                        //保存失败：帐户类型无效
    ACErrorAccountAlreadyExists,            // Account wasn't added because it already exists.                                  //添加失败：帐户已存在
    ACErrorAccountNotFound,                 // Account wasn't deleted because it could not be found.                            //删除失败：找不到帐户
    ACErrorPermissionDenied,                // The operation didn't complete because the user denied permission.                //操作失败：由于用户拒绝权限
    ACErrorAccessInfoInvalid,               // The client's access info dictionary has incorrect or missing values.             //客户端的访问信息字典中的值不正确或丢失
    ACErrorClientPermissionDenied,          // Your client does not have access to the requested data.                          //您的客户端无权访问请求的数据
    ACErrorAccessDeniedByProtectionPolicy,  // Due to the current protection policy in effect, we couldn't fetch a credential   //由于当前有效的保护策略，无法获取凭据
    ACErrorCredentialNotFound,              // Yo, I tried to find your credential, but it must have run off!                   //我试图找到您的凭证，但它一定跑掉了！
    ACErrorFetchCredentialFailed,           // Something bad happened on the way to the keychain                                //钥匙链的路上发生了一些错误
    ACErrorStoreCredentialFailed,           // Unable to store credential                                                       //无法存储凭据
    ACErrorRemoveCredentialFailed,          // Unable to remove credential                                                      //无法删除凭据
    ACErrorUpdatingNonexistentAccount,      // Account save failed because the account being updated has been removed.          //保存失败：由于要更新的帐户已被删除
    ACErrorInvalidClientBundleID,           // The client making the request does not have a valid bundle ID.                   //发出请求的客户端没有有效的包ID
    ACErrorDeniedByPlugin,                  // A plugin prevented the expected action to occur.                                 //插件阻止了预期的操作发生
    ACErrorCoreDataSaveFailed,              // Something broke below us when we tried to the CoreData store.                    //当试图访问coredata store时，下面发生了一些问题
    ACErrorFailedSerializingAccountInfo,                                                                                        //序列化数据失败
    ACErrorInvalidCommand,                                                                                                      //无效的命令
    ACErrorMissingTransportMessageID,                                                                                           //缺少安全信息
    ACErrorCredentialItemNotFound,          // Credential item wasn't saved because it could not be found.                      //保存失败：找不到凭据项
    ACErrorCredentialItemNotExpired,        // Credential item wasn't removed because it has not yet expired.                   //删除失败：因为它尚未过期
} ACErrorCode;
