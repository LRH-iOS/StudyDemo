# CoreFoundation 

Core Foundation框架和Foundation框架紧密相关，它们为相同功能提供接口，但Foundation框架提供Objective-C接口。
如果您将Foundation对象和Core Foundation类型掺杂使用，则可利用两个框架之间的 “toll-free bridging”。
所谓的Toll-free bridging是说您可以在某个框架的方法或函数同时使用Core Foundatio和Foundation 框架中的某些类型。
很多数据类型支持这一特性，其中包括群体和字符串数据类型。每个框架的类和类型描述都会对某个对象是否为 toll-free bridged，应和什么对象桥接进行说明。


## 下面列举该框架支持进行管理的数据以及可提供的服务：

1、群体数据类型 (数组、集合等)
2、程序包
3、字符串管理
4、日期和时间管理
5、原始数据块管理
6、偏好管理
7、URL及数据流操作
8、线程和RunLoop
9、端口和soket通讯


## Objective-C指针与CoreFoundation指针之间的转换

　　ARC仅管理Objective-C指针（retain、release、autorelease），不管理CoreFoundation指针，CF指针由人工管理，手动的CFRetain和CFRelease来管理，注，CF中没有autorelease。
　　CocoaFoundation指针与CoreFoundation指针转换，需要考虑的是所指向对象所有权的归属。ARC提供了3个修饰符来管理。
　　1. __bridge，什么也不做，仅仅是转换。此种情况下：
　　　　　　i). 从Cocoa转换到Core，需要人工CFRetain，否则，Cocoa指针释放后， 传出去的指针则无效。
　　　　　　ii). 从Core转换到Cocoa，需要人工CFRelease，否则，Cocoa指针释放后，对象引用计数仍为1，不会被销毁。　　　　
　　2. __bridge_retained，转换后自动调用CFRetain，即帮助自动解决上述i的情形。　　　　　　　　　　
　　3. __bridge_transfer，转换后自动调用CFRelease，即帮助自动解决上述ii的情形。
