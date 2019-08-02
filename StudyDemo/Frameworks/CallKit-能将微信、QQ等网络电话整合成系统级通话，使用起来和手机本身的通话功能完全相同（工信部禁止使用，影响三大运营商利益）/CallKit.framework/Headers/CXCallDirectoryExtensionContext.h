//
//  CXCallDirectoryExtensionContext.h
//  CallKit
//
//  Copyright © 2016 Apple. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CallKit/CXBase.h>
#import <CallKit/CXCallDirectory.h>

NS_ASSUME_NONNULL_BEGIN

@class CXCallDirectoryExtensionContext;

@protocol CXCallDirectoryExtensionContextDelegate <NSObject>

- (void)requestFailedForExtensionContext:(CXCallDirectoryExtensionContext *)extensionContext withError:(NSError *)error;

@end

CX_CLASS_AVAILABLE(ios(10.0))
/// 扩展extension
@interface CXCallDirectoryExtensionContext : NSExtensionContext

@property (nonatomic, weak, nullable) id<CXCallDirectoryExtensionContextDelegate> delegate;

/**
 Whether the request should provide incremental data.

 If this is called at the beginning of the request (before any entries have been added or removed) and the result is YES,
 then the request must only provide an "incremental" set of entries, i.e. only add or remove entries relative to the last time data
 was loaded for the extension. Otherwise, if this method is not called OR is called and returns NO, then the request must provide
 a "complete" set of entries, adding the full list of entries from scratch (and removing none), regardless of whether data has ever been
 successfully loaded in the past.
 */
@property (nonatomic, readonly, getter=isIncremental) BOOL incremental API_AVAILABLE(ios(11.0));

/// 给系统数据库增加骚扰电话号码
- (void)addBlockingEntryWithNextSequentialPhoneNumber:(CXCallDirectoryPhoneNumber)phoneNumber;

/**
 Remove blocking entry with the specified phone number.

 May only be used when `-isIncremental` returns YES, indicating that the request should provide incremental entries and thus may use this
 API to remove a previously-added blocking entry.

 @param phoneNumber The blocking entry phone number to remove.
 */
/// 移除系统数据库某个骚扰电话号码
- (void)removeBlockingEntryWithPhoneNumber:(CXCallDirectoryPhoneNumber)phoneNumber API_AVAILABLE(ios(11.0));

/**
 Remove all currently-stored blocking entries.

 May only be used when `-isIncremental` returns YES, indicating that the request should provide incremental entries and thus may use this
 API to remove all previously-added blocking entries.
 */
/// 删除所有骚扰电话
- (void)removeAllBlockingEntries API_AVAILABLE(ios(11.0));

/// 给系统数据库增加骚扰电话号码以及提示的文本
- (void)addIdentificationEntryWithNextSequentialPhoneNumber:(CXCallDirectoryPhoneNumber)phoneNumber label:(NSString *)label;

/**
 Remove identification entry with the specified phone number.

 May only be used when `-isIncremental` returns YES, indicating that the request should provide incremental entries and thus may use this
 API to remove a previously-added identification entry. Removes all identification entries with the specified phone number, even if
 multiple identification entries with different labels are present for a single phone number.

 @param phoneNumber The identification entry phone number to remove.
 */
/// 删除指定电话的标记
- (void)removeIdentificationEntryWithPhoneNumber:(CXCallDirectoryPhoneNumber)phoneNumber API_AVAILABLE(ios(11.0));

/**
 Remove all currently-stored identification entries.

 May only be used when `-isIncremental` returns YES, indicating that the request should provide incremental entries and thus may use this
 API to remove all previously-added identification entries.
 */
/// 删除所有电话标记
- (void)removeAllIdentificationEntries API_AVAILABLE(ios(11.0));

/// 提交
- (void)completeRequestWithCompletionHandler:(nullable void (^)(BOOL expired))completion;

// Use -completeRequestWithCompletionHandler: instead
- (void)completeRequestReturningItems:(nullable NSArray *)items completionHandler:(void (^__nullable)(BOOL expired))completionHandler NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
