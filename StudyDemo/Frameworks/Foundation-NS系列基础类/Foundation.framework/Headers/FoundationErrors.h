/*	FoundationErrors.h
	Copyright (c) 2004-2018, Apple Inc. All rights reserved.
*/

#import <Foundation/NSObject.h>
#import <Foundation/NSError.h>

/* NSError codes in NSCocoaErrorDomain. Note that other frameworks (such as AppKit and CoreData) also provide additional NSCocoaErrorDomain error codes.
*/
NS_ERROR_ENUM(NSCocoaErrorDomain) {
    // File system and file I/O related errors, with NSFilePathErrorKey or NSURLErrorKey containing path or URL
    // 与文件系统和文件I/O相关的错误，其中NSFilePathErrorKey或NSURLErrorKey包含路径或url
#parm mark - 读取文件错误
    NSFileNoSuchFileError = 4,                                              // Attempt to do a file system operation on a non-existent file     尝试对不存在的文件执行文件系统操作
    NSFileLockingError = 255,                                               // Couldn't get a lock on file                                      无法锁定文件
    NSFileReadUnknownError = 256,                                           // Read error (reason unknown)                                      读取错误（原因未知）
    NSFileReadNoPermissionError = 257,                                      // Read error (permission problem)                                  读取错误（权限问题)
    NSFileReadInvalidFileNameError = 258,                                   // Read error (invalid file name)                                   读取错误（无效文件名
    NSFileReadCorruptFileError = 259,                                       // Read error (file corrupt, bad format, etc)                       读取错误（文件损坏、格式错误等
    NSFileReadNoSuchFileError = 260,                                        // Read error (no such file)                                        读取错误（无此文件）
    NSFileReadInapplicableStringEncodingError = 261,                        // Read error (string encoding not applicable) also NSStringEncodingErrorKey    读取错误（字符串编码不适用）
    NSFileReadUnsupportedSchemeError = 262,                                 // Read error (unsupported URL scheme)                              读取错误（不支持的URL方案）
    NSFileReadTooLargeError API_AVAILABLE(macos(10.5), ios(2.0), watchos(2.0), tvos(9.0)) = 263,             // Read error (file too large)     读取错误（文件太大）
    NSFileReadUnknownStringEncodingError API_AVAILABLE(macos(10.5), ios(2.0), watchos(2.0), tvos(9.0)) = 264, // Read error (string encoding of file contents could not be determined)  读取错误（无法确定文件内容的字符串编码）
    
#parm mark - 写入文件错误
    NSFileWriteUnknownError = 512,                                          // Write error (reason unknown)                                     写入错误（原因未知)
    NSFileWriteNoPermissionError = 513,                                     // Write error (permission problem)
    NSFileWriteInvalidFileNameError = 514,                                  // Write error (invalid file name)
    NSFileWriteFileExistsError API_AVAILABLE(macos(10.7), ios(5.0), watchos(2.0), tvos(9.0)) = 516,          // Write error (file exists)       写入错误（文件存在）
    NSFileWriteInapplicableStringEncodingError = 517,                       // Write error (string encoding not applicable) also NSStringEncodingErrorKey
    NSFileWriteUnsupportedSchemeError = 518,                                // Write error (unsupported URL scheme)
    NSFileWriteOutOfSpaceError = 640,                                       // Write error (out of disk space)                                  写入错误（磁盘空间不足）
    NSFileWriteVolumeReadOnlyError API_AVAILABLE(macos(10.6), ios(4.0), watchos(2.0), tvos(9.0)) = 642,      // Write error (readonly volume)   写入错误（只读卷）

#parm mark - 文件管理错误
    // NSFileManager unmount errors NSfileManager卸载错误
    NSFileManagerUnmountUnknownError NS_ENUM_AVAILABLE(10_11, NA) = 768,    // The volume could not be unmounted (reason unknown)               无法卸载卷（原因未知）
    NSFileManagerUnmountBusyError NS_ENUM_AVAILABLE(10_11, NA) = 769,       // The volume could not be unmounted because it is in use           无法卸载卷，因为它正在使用中

#parm mark - 其他错误
    // Other errors
    NSKeyValueValidationError = 1024,                                       // KVC validation error                                             kvc验证错误
    NSFormattingError = 2048,                                               // Formatting error                                                 格式错误
    NSUserCancelledError = 3072,                                            // User cancelled operation (this one often doesn't deserve a panel and might be a good one to special case)    用户取消了操作（此操作通常不需要面板，在特殊情况下可能是一个很好的面板）

    NSFeatureUnsupportedError API_AVAILABLE(macos(10.8), ios(6.0), watchos(2.0), tvos(9.0)) = 3328,          // Feature unsupported error       功能不支持错误
    
#parm mark - 可执行文件加载错误
    // Executable loading errors    可执行文件加载错误
    NSExecutableNotLoadableError API_AVAILABLE(macos(10.5), ios(2.0), watchos(2.0), tvos(9.0)) = 3584,           // Executable is of a type that is not loadable in the current process 可执行文件的类型在当前进程中不可加载
    NSExecutableArchitectureMismatchError API_AVAILABLE(macos(10.5), ios(2.0), watchos(2.0), tvos(9.0)) = 3585,  // Executable does not provide an architecture compatible with the current process 可执行文件不提供与当前进程兼容的体系结构
    NSExecutableRuntimeMismatchError API_AVAILABLE(macos(10.5), ios(2.0), watchos(2.0), tvos(9.0)) = 3586,       // Executable has Objective C runtime information incompatible with the current process    可执行文件具有与当前进程不兼容的目标C运行时信息
    NSExecutableLoadError API_AVAILABLE(macos(10.5), ios(2.0), watchos(2.0), tvos(9.0)) = 3587,                  // Executable cannot be loaded for some other reason, such as a problem with a library it depends on   由于其他原因无法加载可执行文件，例如它所依赖的库有问题
    NSExecutableLinkError API_AVAILABLE(macos(10.5), ios(2.0), watchos(2.0), tvos(9.0)) = 3588,                  // Executable fails due to linking issues  由于链接问题，可执行文件失败
    
#parm mark - 包含错误范围定义
    // Inclusive error range definitions, for checking future error codes   包含错误范围定义，用于检查将来的错误代码
    NSFileErrorMinimum = 0,
    NSFileErrorMaximum = 1023,
    
    NSValidationErrorMinimum = 1024,
    NSValidationErrorMaximum = 2047,

    NSExecutableErrorMinimum API_AVAILABLE(macos(10.5), ios(2.0), watchos(2.0), tvos(9.0)) = 3584,
    NSExecutableErrorMaximum API_AVAILABLE(macos(10.5), ios(2.0), watchos(2.0), tvos(9.0)) = 3839,

    NSFormattingErrorMinimum = 2048,
    NSFormattingErrorMaximum = 2559,
    
#parm mark - property错误（属性列表错误）
    NSPropertyListReadCorruptError API_AVAILABLE(macos(10.6), ios(4.0), watchos(2.0), tvos(9.0)) = 3840,         // Error parsing a property list   分析属性列表时出错
    NSPropertyListReadUnknownVersionError API_AVAILABLE(macos(10.6), ios(4.0), watchos(2.0), tvos(9.0)) = 3841,  // The version number in the property list is unknown  属性列表中的版本号未知
    NSPropertyListReadStreamError API_AVAILABLE(macos(10.6), ios(4.0), watchos(2.0), tvos(9.0)) = 3842,          // Stream error reading a property list    读取属性列表时出现流错误
    NSPropertyListWriteStreamError API_AVAILABLE(macos(10.6), ios(4.0), watchos(2.0), tvos(9.0)) = 3851,         // Stream error writing a property list    写入属性列表时出现流错误
    NSPropertyListWriteInvalidError API_AVAILABLE(macos(10.10), ios(8.0), watchos(2.0), tvos(9.0)) = 3852,       // Invalid property list object or invalid property list type specified when writing   写入时指定的属性列表对象无效或属性列表类型无效

    NSPropertyListErrorMinimum API_AVAILABLE(macos(10.6), ios(4.0), watchos(2.0), tvos(9.0)) = 3840,
    NSPropertyListErrorMaximum API_AVAILABLE(macos(10.6), ios(4.0), watchos(2.0), tvos(9.0)) = 4095,

    NSXPCConnectionInterrupted API_AVAILABLE(macos(10.8), ios(6.0), watchos(2.0), tvos(9.0)) = 4097,
    NSXPCConnectionInvalid API_AVAILABLE(macos(10.8), ios(6.0), watchos(2.0), tvos(9.0)) = 4099,
    NSXPCConnectionReplyInvalid API_AVAILABLE(macos(10.8), ios(6.0), watchos(2.0), tvos(9.0)) = 4101,
    
    NSXPCConnectionErrorMinimum API_AVAILABLE(macos(10.8), ios(6.0), watchos(2.0), tvos(9.0)) = 4096,
    NSXPCConnectionErrorMaximum API_AVAILABLE(macos(10.8), ios(6.0), watchos(2.0), tvos(9.0)) = 4224,

#parm mark - NSURLUbiquitousItemDownloadingErrorKey、NSURLUbiquitousItemUploadingErrorKey错误属性
    NSUbiquitousFileUnavailableError API_AVAILABLE(macos(10.9), ios(7.0), watchos(2.0), tvos(9.0)) = 4353, // NSURLUbiquitousItemDownloadingErrorKey contains an error with this code when the item has not been uploaded to iCloud by the other devices yet    NSURLUbiquitousItemDownloadingErrorKey：当其他设备尚未将项目上传到iCloud时，包含此代码的错误
    NSUbiquitousFileNotUploadedDueToQuotaError API_AVAILABLE(macos(10.9), ios(7.0), watchos(2.0), tvos(9.0)) = 4354, // NSURLUbiquitousItemUploadingErrorKey contains an error with this code when the item has not been uploaded to iCloud because it would make the account go over-quota     NSURLUbiquitousItemUploadingErrorKey：在项目未上传到iCloud时包含此代码的错误，因为它会使帐户超过配额
    NSUbiquitousFileUbiquityServerNotAvailable API_AVAILABLE(macos(10.9), ios(7.0), watchos(2.0), tvos(9.0)) = 4355, // NSURLUbiquitousItemDownloadingErrorKey and NSURLUbiquitousItemUploadingErrorKey contain an error with this code when connecting to the iCloud servers failed    NSURLUbiquitousItemDownloadingErrorKey、NSURLUbiquitousItemUploadingErrorKey：连接到iCloud服务器失败时包含此代码的错误

    NSUbiquitousFileErrorMinimum API_AVAILABLE(macos(10.9), ios(7.0), watchos(2.0), tvos(9.0)) = 4352,
    NSUbiquitousFileErrorMaximum API_AVAILABLE(macos(10.9), ios(7.0), watchos(2.0), tvos(9.0)) = 4607,

    NSUserActivityHandoffFailedError API_AVAILABLE(macos(10.10), ios(8.0), watchos(2.0), tvos(9.0)) = 4608,	// The data for the user activity was not available (e.g. if the remote device became unavailable.)     //用户活动的数据不可用（例如，如果远程设备不可用）。
    NSUserActivityConnectionUnavailableError API_AVAILABLE(macos(10.10), ios(8.0), watchos(2.0), tvos(9.0)) = 4609,  // The user activity could not be continued because a required connection was not available     //由于所需连接不可用，用户活动无法继续
    NSUserActivityRemoteApplicationTimedOutError API_AVAILABLE(macos(10.10), ios(8.0), watchos(2.0), tvos(9.0)) = 4610, // The remote application failed to send data in time   远程应用程序未能及时发送数据
    NSUserActivityHandoffUserInfoTooLargeError API_AVAILABLE(macos(10.10), ios(8.0), watchos(2.0), tvos(9.0)) = 4611, // The NSUserActivity userInfo dictionary was too large to receive    NSUserActivity userInfo字典太大，无法接收

    NSUserActivityErrorMinimum API_AVAILABLE(macos(10.10), ios(8.0), watchos(2.0), tvos(9.0)) = 4608,
    NSUserActivityErrorMaximum API_AVAILABLE(macos(10.10), ios(8.0), watchos(2.0), tvos(9.0)) = 4863,
    
    NSCoderReadCorruptError API_AVAILABLE(macos(10.11), ios(9.0), watchos(2.0), tvos(9.0)) = 4864, // Error parsing data during decode      //解码时分析数据出错
    NSCoderValueNotFoundError API_AVAILABLE(macos(10.11), ios(9.0), watchos(2.0), tvos(9.0)) = 4865, // Data requested was not found        //找不到请求的数据
    NSCoderInvalidValueError API_AVAILABLE(macos(10.13), ios(11.0), watchos(4.0), tvos(11.0)) = 4866, // Data was not valid to encode       //数据无效，无法编码
    NSCoderErrorMinimum API_AVAILABLE(macos(10.11), ios(9.0), watchos(2.0), tvos(9.0)) = 4864,
    NSCoderErrorMaximum API_AVAILABLE(macos(10.11), ios(9.0), watchos(2.0), tvos(9.0)) = 4991,
    
    NSBundleErrorMinimum API_AVAILABLE(macos(10.11), ios(9.0), watchos(2.0), tvos(9.0)) = 4992,
    NSBundleErrorMaximum API_AVAILABLE(macos(10.11), ios(9.0), watchos(2.0), tvos(9.0)) = 5119,
    
    NSBundleOnDemandResourceOutOfSpaceError NS_ENUM_AVAILABLE(NA, 9_0) = 4992, // There was not enough space available to download the requested On Demand Resources.   没有足够的空间下载请求的按需资源
    NSBundleOnDemandResourceExceededMaximumSizeError NS_ENUM_AVAILABLE(NA, 9_0) = 4993, // The application exceeded the amount of On Demand Resources content in use at one time    应用程序超过了单次使用的按需资源内容量
    NSBundleOnDemandResourceInvalidTagError NS_ENUM_AVAILABLE(NA, 9_0) = 4994, // The application specified a tag which the system could not find in the application tag manifest   应用程序指定了系统在应用程序标记清单中找不到的标记
    
#parm mark - NSCloud 云服务错误
    NSCloudSharingNetworkFailureError API_AVAILABLE(macosx(10.12), ios(10.0)) API_UNAVAILABLE(watchos, tvos) = 5120,        // Sharing failed due to a network failure.  由于网络故障，共享失败。
    NSCloudSharingQuotaExceededError API_AVAILABLE(macosx(10.12), ios(10.0)) API_UNAVAILABLE(watchos, tvos) = 5121,         // The user doesn't have enough storage space available to share the requested items.       //用户没有足够的存储空间来共享请求的项目
    NSCloudSharingTooManyParticipantsError API_AVAILABLE(macosx(10.12), ios(10.0)) API_UNAVAILABLE(watchos, tvos) = 5122,   // Additional participants could not be added to the share, because the limit was reached.     //由于达到了限制，无法将其他参与者添加到共享中
    NSCloudSharingConflictError API_AVAILABLE(macosx(10.12), ios(10.0)) API_UNAVAILABLE(watchos, tvos) = 5123,              // A conflict occurred while trying to save changes to the CKShare and/or root CKRecord. Respond to this error by first fetching the server's changes to the records, then either handle the conflict manually or present it, which will instruct the user to try the operation again.  //试图保存对ckshare和/或根ckrecord的更改时发生冲突。通过首先获取服务器对记录所做的更改，然后手动处理冲突或显示冲突来响应此错误，这将指示用户重试该操作
    NSCloudSharingNoPermissionError API_AVAILABLE(macosx(10.12), ios(10.0)) API_UNAVAILABLE(watchos, tvos) = 5124,         // The current user doesn't have permission to perform the requested actions.              //当前用户没有执行请求操作的权限。
    NSCloudSharingOtherError API_AVAILABLE(macosx(10.12), ios(10.0)) API_UNAVAILABLE(watchos, tvos) = 5375,                 // These errors may require application-specific responses. For CloudKit sharing, use the NSUnderlyingErrorKey, which is a CKErrorDomain error, to discover the specific error and refer to the CloudKit documentation for the proper response to these errors.
    // 这些错误可能需要应用程序特定的响应。对于Cloudkit共享，请使用NSUnderlyingErrorKey（一个ckerrordomain错误）来发现特定的错误，并参考Cloudkit文档以获得对这些错误的正确响应
    NSCloudSharingErrorMinimum API_AVAILABLE(macosx(10.12), ios(10.0)) API_UNAVAILABLE(watchos, tvos) = 5120,
    NSCloudSharingErrorMaximum API_AVAILABLE(macosx(10.12), ios(10.0)) API_UNAVAILABLE(watchos, tvos) = 5375,

};

