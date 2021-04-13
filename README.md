# cpp_threadpool_http
使用Threadpool开发http



## 概念：
    异步I/O
    异步解耦

程序在执行的过程中，比如说http程序，保存日志，直接写磁盘的话，性能压在磁盘的读写上面，引入一个线程池

异步I/O
第一种是CPU等着，也就是程序暂停执行后续代码，等100M的数据在10秒后写入磁盘，再接着往下执行，这种模式称为同步IO；

另一种方法是CPU不等待，只是告诉磁盘，“您老慢慢写，不着急，我接着干别的事去了”，于是，后续代码可以立刻接着执行，这种模式称为异步IO


同步和异步的区别就在于是否等待IO执行的结果。好比你去麦当劳点餐，你说“来个汉堡”，服务员告诉你，对不起，汉堡要现做，需要等5分钟，于是你站在收银台前面等了5分钟，拿到汉堡再去逛商场，这是同步IO。

你说“来个汉堡”，服务员告诉你，汉堡需要等5分钟，你可以先去逛商场，等做好了，我们再通知你，这样你可以立刻去干别的事情（逛商场），这是异步IO。


## 线程池
三部分
1. 执行队列，线程s
2. 任务队列，任务s
3. 管理组件