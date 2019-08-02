//
//  CallKitViewController.m
//  StudyDemo
//
//  Created by LRH on 2019/7/24.
//  Copyright © 2019 LRH. All rights reserved.
//

#import "CallKitViewController.h"
#import <CallKit/CallKit.h>

@interface CallKitViewController () <CXProviderDelegate>

@end

@implementation CallKitViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    
    CXCallController *callViewCtrl = [[CXCallController alloc] init];
    
//    CXProviderConfiguration *configuration = [[CXProviderConfiguration alloc] initWithLocalizedName:@"123123ppppp"];
//    configuration.supportsVideo = YES;
//
//    CXCallUpdate *update = [[CXCallUpdate alloc] init];
//
    NSUUID *uuid = [[NSUUID alloc] init];//[[NSUUID alloc] initWithUUIDString:@"8bc0332b916c55bd3c38b16f5f28f0f09cb68e89"];
//
//    CXProvider *provider = [[CXProvider alloc] initWithConfiguration:configuration];
//    [provider setDelegate:self queue:nil];
//
//    [provider reportNewIncomingCallWithUUID:uuid update:update completion:^(NSError * _Nullable error) {
//
//    }];
//
//    /// Report an update to call information.
//    /// 报告系统通话更新。动态更改provider的配置信息CXCallUpdate,比如拨打方，开始没有配置通话的界面，就可以在通话开始时更新这些配置信息
//    [provider reportCallWithUUID:uuid updated:update];
//
//    /// Report that a call ended. A nil value for `dateEnded` results in the ended date being set to now.
//    /// 报告系统通话结束的时间和原因
////    CXCallEndedReasonFailed = 1, // An error occurred while trying to service the call
////    CXCallEndedReasonRemoteEnded = 2, // The remote party explicitly ended the call
////    CXCallEndedReasonUnanswered = 3, // The call never started connecting and was never explicitly ended (e.g. outgoing/incoming call timeout)
////    CXCallEndedReasonAnsweredElsewhere = 4, // The call was answered on another device
////    CXCallEndedReasonDeclinedElsewhere = 5, /
//    [provider reportCallWithUUID:uuid endedAtDate:[NSDate date] reason:CXCallEndedReasonFailed];
//
//    /// Report that an outgoing call started connecting. A nil value for `dateStartedConnecting` results in the started connecting date being set to now.
//    /// 呼出电话：通话连接时
//    [provider reportOutgoingCallWithUUID:uuid startedConnectingAtDate:[NSDate date]];
//    /// Report that an outgoing call connected. A nil value for `dateConnected` results in the connected date being set to now.
//    /// 呼出电话：通话已连接
//    [provider reportOutgoingCallWithUUID:uuid connectedAtDate:[NSDate date]];
    
    
    CXHandle *handle = [[CXHandle alloc] initWithType:CXHandleTypePhoneNumber value:@"18038008370"];
    CXStartCallAction *startAction = [[CXStartCallAction alloc] initWithCallUUID:uuid handle:handle];
    
    CXTransaction *transaction = [[CXTransaction alloc] initWithAction:startAction];
    [callViewCtrl requestTransaction:transaction completion:^(NSError * _Nullable error) {
        
    }];
    
}

#pragma mark - CXProviderDelegate

- (void)providerDidReset:(CXProvider *)provider
{
    
}

/// Called when the provider has been fully created and is ready to send actions and receive updates
/// provider创建好以后触发
- (void)providerDidBegin:(CXProvider *)provider
{
    
}

/// Called whenever a new transaction should be executed. Return whether or not the transaction was handled:
///
/// - NO: the transaction was not handled indicating that the perform*CallAction methods should be called sequentially for each action in the transaction
/// - YES: the transaction was handled and the perform*CallAction methods should not be called sequentially
///
/// If the method is not implemented, NO is assumed.
/// 是否执行一个transaction
- (BOOL)provider:(CXProvider *)provider executeTransaction:(CXTransaction *)transaction
{
    
    return NO;
}

// If provider:executeTransaction:error: returned NO, each perform*CallAction method is called sequentially for each action in the transaction
/// 如果 provider:executeTransaction:error: 返回 NO, 下面的方法按逻辑执行
/// 拨打方成功发起一个通话后触发
- (void)provider:(CXProvider *)provider performStartCallAction:(CXStartCallAction *)action
{
    
}

/// 接听方成功接听一个电话时触发
- (void)provider:(CXProvider *)provider performAnswerCallAction:(CXAnswerCallAction *)action
{
    
}

/// 接听方拒接电话或者双方结束通话时触发
- (void)provider:(CXProvider *)provider performEndCallAction:(CXEndCallAction *)action
{
    
}

/// 当点击系统通话界面的 暂停 按钮时，会触发
- (void)provider:(CXProvider *)provider performSetHeldCallAction:(CXSetHeldCallAction *)action
{
    
}

/// 当点击系统通话界面的 静音 按钮时，会触发
- (void)provider:(CXProvider *)provider performSetMutedCallAction:(CXSetMutedCallAction *)action
{
    
}

/// 当点击系统通话界面的 添加通话 按钮时，会触发
- (void)provider:(CXProvider *)provider performSetGroupCallAction:(CXSetGroupCallAction *)action
{
    
}

///  多频双音功能触发
- (void)provider:(CXProvider *)provider performPlayDTMFCallAction:(CXPlayDTMFCallAction *)action
{
    
}

/// Called when an action was not performed in time and has been inherently failed. Depending on the action, this timeout may also force the call to end. An action that has already timed out should not be fulfilled or failed by the provider delegate
/// 通话响应超时，强制通话结束
- (void)provider:(CXProvider *)provider timedOutPerformingAction:(CXAction *)action
{
    
}

/// Called when the provider's audio session activation state changes.
/// audio session activation state改变时发起
- (void)provider:(CXProvider *)provider didActivateAudioSession:(AVAudioSession *)audioSession
{
    
}

- (void)provider:(CXProvider *)provider didDeactivateAudioSession:(AVAudioSession *)audioSession
{
    
}



@end
