# StudyDemo
主要目的：用来学习苹果开发语言OC底层框架

## 作用
1、发起音、视频通话
2、来电识别、拦截


## CallKit被禁用的原因、影响
而CallKit被禁用的影响就是，当你收到微信语音时，不会在锁屏界面显示“来电提醒”，也不能直接“接听”或“拒绝”，而是显示一条微信通知，需要解锁并进入微信App内才能通话。对于微信电话很多的用户来说，确实没有以前方便。
CallKit动了哪家的蛋糕也是非常明显了，凭借微信的巨大用户量，微信语音通话通过CallKit整合进系统内，网络通话和传统通话使用体验完全一致。这无疑会对传统三大运营商造成巨大的打击，所以工信部明令禁止中国大陆App内支持CallKit功能也是情有可原了。


## 原理
在使用 CallKit 时，有两个主要的类：CXProvider和 CXCallController。分别介绍如下。

### CXProvider
你的 App 使用 CXProvider 来将外部通知报告给系统。通常是外部事件，比如来电。
当有事件发生，CXProvider 会创建一个 call update 来通知系统。什么是 call update？call update 用于封装新的或者改变了的和通话有关的信息。它用 CXCallUpdate 类来描述，这个类暴露了这些属性：呼入者姓名、是否是音频通话还是视频通话。
当系统想通知 App 有收到一个事件时，它会以 CXAction 的形式通知。CXAction 是一个抽象类，表示电话的动作。针对不同 action，CallKit 会提供不同的 CXAction 实现。例如，呼出用 CXStartCallAction 来表示，CXAnswerCallAction 则用于接听呼入。Action 通过唯一的 UUID 来识别，它要么是 fail 要么是 fulfill。
App 通过 CXProviderDelegate 和 CXProvider 打交道，这个协议定义了 CXProvider 的生命周期事件方法，以及来电 Action。

### CXCallController
App 使用 CXCallController 来让系统知道用户发起的请求，比如“呼叫”动作。CXProvider 和 CXCallController 的最大不同在于：CXProvider 的工作是通知系统，而 CXCallController 则代表用户向用户发起请求。
CXCallController 在发起请求时使用了事务。事务用 CXTransaction 来表示，它会包含一个或多个 CXAction 实例。CXCallCotroller 将事务发送给系统，如果一切正常，系统会响应对应的 action 给 CXProvider。


## 官方文档
https://developer.apple.com/documentation/callkit

## 参考文章
https://blog.csdn.net/kmyhy/article/details/74388913
