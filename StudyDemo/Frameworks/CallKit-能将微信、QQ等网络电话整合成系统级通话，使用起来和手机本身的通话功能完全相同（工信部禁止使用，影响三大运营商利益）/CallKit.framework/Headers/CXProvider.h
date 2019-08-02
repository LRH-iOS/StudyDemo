//
//  CXProvider.h
//  CallKit
//
//  Copyright © 2015 Apple. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CallKit/CXBase.h>

NS_ASSUME_NONNULL_BEGIN

@class CXAction;
@class CXCallAction;
@class CXCallUpdate;
@class CXProvider;
@class CXProviderConfiguration;
@class CXTransaction;
@class CXStartCallAction;
@class CXAnswerCallAction;
@class CXEndCallAction;
@class CXSetHeldCallAction;
@class CXSetMutedCallAction;
@class CXSetGroupCallAction;
@class CXPlayDTMFCallAction;

@class AVAudioSession;

typedef NS_ENUM(NSInteger, CXCallEndedReason) {
    CXCallEndedReasonFailed = 1, // An error occurred while trying to service the call      尝试为调用提供服务时出错
    CXCallEndedReasonRemoteEnded = 2, // The remote party explicitly ended the call         远程方显式结束了调用
    CXCallEndedReasonUnanswered = 3, // The call never started connecting and was never explicitly ended (e.g. outgoing/incoming call timeout)  /呼叫从未开始连接，也从未显式结束（例如，传出/传入呼叫超时）
    CXCallEndedReasonAnsweredElsewhere = 4, // The call was answered on another device      //呼叫是在另一台设备上应答的
    CXCallEndedReasonDeclinedElsewhere = 5, // The call was declined on another device      //呼叫是在另一台设备上挂断了
} API_AVAILABLE(ios(10.0));

@protocol CXProviderDelegate <NSObject>

/// Called when the provider has been reset. Delegates must respond to this callback by cleaning up all internal call state (disconnecting communication channels, releasing network resources, etc.). This callback can be treated as a request to end all calls without the need to respond to any actions
/// 必须通过清除所有内部呼叫状态（断开通信信道、释放网络资源等）来响应此回调 ，此回调可以被视为结束所有调用的请求，而无需响应任何操作
- (void)providerDidReset:(CXProvider *)provider;

@optional

/// Called when the provider has been fully created and is ready to send actions and receive updates
/// provider创建好以后触发
- (void)providerDidBegin:(CXProvider *)provider;

/// Called whenever a new transaction should be executed. Return whether or not the transaction was handled:
///
/// - NO: the transaction was not handled indicating that the perform*CallAction methods should be called sequentially for each action in the transaction
/// - YES: the transaction was handled and the perform*CallAction methods should not be called sequentially
///
/// If the method is not implemented, NO is assumed.
/// 是否执行一个transaction
- (BOOL)provider:(CXProvider *)provider executeTransaction:(CXTransaction *)transaction;

// If provider:executeTransaction:error: returned NO, each perform*CallAction method is called sequentially for each action in the transaction
/// 如果 provider:executeTransaction:error: 返回 NO, 下面的方法按逻辑执行
/// 拨打方成功发起一个通话后触发
- (void)provider:(CXProvider *)provider performStartCallAction:(CXStartCallAction *)action;
/// 接听方成功接听一个电话时触发
- (void)provider:(CXProvider *)provider performAnswerCallAction:(CXAnswerCallAction *)action;
/// 接听方拒接电话或者双方结束通话时触发
- (void)provider:(CXProvider *)provider performEndCallAction:(CXEndCallAction *)action;
/// 当点击系统通话界面的 暂停 按钮时，会触发
- (void)provider:(CXProvider *)provider performSetHeldCallAction:(CXSetHeldCallAction *)action;
/// 当点击系统通话界面的 静音 按钮时，会触发
- (void)provider:(CXProvider *)provider performSetMutedCallAction:(CXSetMutedCallAction *)action;
/// 当点击系统通话界面的 添加通话 按钮时，会触发
- (void)provider:(CXProvider *)provider performSetGroupCallAction:(CXSetGroupCallAction *)action;
///  多频双音功能触发
- (void)provider:(CXProvider *)provider performPlayDTMFCallAction:(CXPlayDTMFCallAction *)action;

/// Called when an action was not performed in time and has been inherently failed. Depending on the action, this timeout may also force the call to end. An action that has already timed out should not be fulfilled or failed by the provider delegate
/// 通话响应超时，强制通话结束
- (void)provider:(CXProvider *)provider timedOutPerformingAction:(CXAction *)action;

/// Called when the provider's audio session activation state changes.
/// audio session activation state改变时发起
- (void)provider:(CXProvider *)provider didActivateAudioSession:(AVAudioSession *)audioSession;
- (void)provider:(CXProvider *)provider didDeactivateAudioSession:(AVAudioSession *)audioSession;

@end

CX_CLASS_AVAILABLE(ios(10.0))

/// 提供者：系统信息传递给用户 
@interface CXProvider : NSObject

/// Initialize a new provider instance with the supplied configuration
- (instancetype)initWithConfiguration:(CXProviderConfiguration *)configuration NS_DESIGNATED_INITIALIZER;
- (instancetype)init NS_UNAVAILABLE;

/// Set delegate and optional queue for delegate callbacks to be performed on.
/// A nil queue implies that delegate callbacks should happen on the main queue. The delegate is stored weakly
- (void)setDelegate:(nullable id<CXProviderDelegate>)delegate queue:(nullable dispatch_queue_t)queue;

/// Report a new incoming call to the system.
///
/// If completion is invoked with a non-nil `error`, the incoming call has been disallowed by the system and will not be displayed, so the provider should not proceed with the call.
///
/// Completion block will be called on delegate queue, if specified, otherwise on a private serial queue.
- (void)reportNewIncomingCallWithUUID:(NSUUID *)UUID update:(CXCallUpdate *)update completion:(void (^)(NSError *_Nullable error))completion;

/// Report an update to call information.
/// 报告系统通话更新。动态更改provider的配置信息CXCallUpdate,比如拨打方，开始没有配置通话的界面，就可以在通话开始时更新这些配置信息
- (void)reportCallWithUUID:(NSUUID *)UUID updated:(CXCallUpdate *)update;

/// Report that a call ended. A nil value for `dateEnded` results in the ended date being set to now.
/// 报告系统通话结束的时间和原因
- (void)reportCallWithUUID:(NSUUID *)UUID endedAtDate:(nullable NSDate *)dateEnded reason:(CXCallEndedReason)endedReason;

/// Report that an outgoing call started connecting. A nil value for `dateStartedConnecting` results in the started connecting date being set to now.
/// 呼出电话：通话连接时
- (void)reportOutgoingCallWithUUID:(NSUUID *)UUID startedConnectingAtDate:(nullable NSDate *)dateStartedConnecting;

/// Report that an outgoing call connected. A nil value for `dateConnected` results in the connected date being set to now.
/// 呼出电话：通话已连接
- (void)reportOutgoingCallWithUUID:(NSUUID *)UUID connectedAtDate:(nullable NSDate *)dateConnected;

/// The receiver's current configuration.
/// 接收方当前配置
@property (nonatomic, readwrite, copy) CXProviderConfiguration *configuration;

/// Invalidate the provider. All existing calls will be marked as ended in failure. The provider must be invalidated before it is deallocated.
/// 让provider停止（所有存在的通话都被标记为失败结束）
- (void)invalidate;

/// List of all transactions that are incomplete.
/// 未完成的CXTransaction列表
@property (nonatomic, readonly, copy) NSArray<CXTransaction *> *pendingTransactions;

/// Returns subset of call actions contained in any transaction in -pendingTransactions of the specified class and with the specified call UUID.
///
- (NSArray<__kindof CXCallAction *> *)pendingCallActionsOfClass:(Class)callActionClass withCallUUID:(NSUUID *)callUUID;

@end

NS_ASSUME_NONNULL_END
