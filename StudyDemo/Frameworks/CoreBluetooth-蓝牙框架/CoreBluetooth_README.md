# StudyDemo
主要目的：用来学习苹果开发语言OC底层框架

## iOS中的蓝牙

BLE:(Bluetooth low energy)蓝牙4.0设备因为低耗电,也叫BLE
iOS中提供了4个框架用于实现蓝牙连接。

### 1.GameKit.framework(用法简单)
只能用于iOS设备之间的同个应用内连接,多用于游戏(eg:棋牌类),从iOS7开始过期

### 2.MultipeerConnectivity.framework(代替1)
只能用于iOS设备之间的连接,从iOS7开始引入,主要用于非联网状态下,通过wifi或者蓝牙进行文件共享(仅限于沙盒的文件),多用于附近无网聊天

### 3.ExternalAccessory.framework(MFi)
可用于第三方蓝牙设备交互,但是蓝牙设备必须经过苹果MFi认证(国内很少)

### 4.CoreBluetooth.framework（常用 Apple推行蓝牙的核心)
可用于第三方蓝牙设备交互,必须要支持蓝牙4.0
硬件至少是4s,系统至少是iOS6 (现iPhoneX 蓝牙5.0)
蓝牙4.0以低功耗著称,一般也叫BLE（Bluetooth Low Energy）
目前应用比较多的案例:运动手环,嵌入式设备,智能家居
我们公司对接的外设比较多 心率计、踏频、码表等运动蓝牙设备
