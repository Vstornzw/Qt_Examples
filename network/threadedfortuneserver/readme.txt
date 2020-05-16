Thread Fortune Server Example 结合fortuneclient文件夹先后运行


Thread Fortune Server Example里面的类就更多啦，除了界面类和线程类，
还有一个FortuneServer类继承自QTcpServer。
为什么不像上面那个例子一样直接在线程创建一个QTcpServer对象呢？
因为服务器与客户机不同，它面对往往都是多个客户机并发的请求。
如果像上一个例子那样先锁住资源响应第一个，再解锁，再锁住响应第二个，再响应第三个。。。。好吧这个服务器这是太棒了。。。
那么此时我们需要对每一个客户机的请求创建一个单独的线程来进行响应。此时我们不再需要互斥锁来保护资源。

Dialog类负责界面绘制，
并通过server.listen()开启FortuneServer的监听事件，一旦有客户机连接上来，server通过IncomingConnection()开启一个新的线程FortuneThread，
该线程则负责将财富(Fortune)发送给客户端，之后将自身销毁。
