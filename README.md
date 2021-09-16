# 逆向OsrLoader记录

> reverse OSR Loader and achieve my driver loader by vs2019.

* OSR Loader version: osrloaderv30\Projects\OsrLoader\kit\WNET\AMD64\FRE

## Motivation

想知道Stop Service按钮背后发生了什么。
![f99663ff9fa5c715e46add402cc63fbf.png](en-resource://database/2335:1)

## 逆向过程

1. 定位stop service字符串（不太直接）

![ff2e9ee9be531d3c29ff5199dc6a7e35.png](en-resource://database/2337:1)

2. ida

sub_100005F58

HKEY_LOCAL_MACHINE\SYSTEM\CurrentControlSet\Control\ServiceGroupOrder

3. 定位关键函数ControlService

![b3b1101613a4f23d115afff29e604318.png](en-resource://database/2339:0)

根据调用service相关的api，可以找到四个按钮所调用的函数。
![2666df94fb5931cab98f1bc31eaa15ac.png](en-resource://database/2343:0)

![52f39cbc208c2501bbbae9a10457d99d.png](en-resource://database/2341:0)

## 如何实现加载（卸载、开启和停止）驱动的功能

没有实现对load group的指定，默认为none。

问题：使用DeleteService删除服务后再次加载驱动，显示该服务已标记为删除。
解决办法（可能的）：不关闭SCManager handle。

效果图
![image-20210916114359280](https://i.loli.net/2021/09/16/opUg1CLkATPZdFG.png)

## 参考资料

https://www.cnblogs.com/cxys/p/4961229.html（有点问题）
https://blog.csdn.net/Simon798/article/details/106158122
