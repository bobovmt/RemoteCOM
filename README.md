# RemoteCOM
RemoteCOM
Operate COM Ports on Remote Server Through Net Connection.

ComProxy
A Python program running in a server that connects to some equipment by COM ports
![ComProxy](https://github.com/bobovmt/RemoteCOM/assets/88587617/061e21f7-62fe-4d75-8993-f2f3438036cb)

RmtCom
A QT(/QML) Program running in Windows. Just like some Com Tools(such as dock light), the difference is that this program can send data to and receive data from the server's COM port while having a net connection to the Comproxy.
![RmtCom](https://github.com/bobovmt/RemoteCOM/assets/88587617/805f1ca4-a469-4a4f-bec7-79590f7fa32e)
## 项目简介
ComProxy ：串口代理，后台运行通过tcp转发串口报文。
##  编写目的
有很多自动化设备是计算机通过串口控制的，如果设备接在本机上，调试的时候可以用串口助手之类的工具去收发串口消息，或者编写程序打开读写串口。
但如果设备是连接在远程主机，一般只能用vnc，这就需要占据远程主机的屏幕（或者其他毕竟麻烦的方式），而如果需要编写控制软件操作远程串口也比较麻烦。
所以我在学习python的时候结合自身的工作需要，编写了这个串口代理（ComProxy），可以运行在远程主机上，将其串口报文通过网络通信转发到用户这边。
用户如果想调试串口，我这也写了一个QML界面的工具（RmtCom），可以像普通串口助手一样读写远程串口。
用户也可以根据tcp通信协议开发自己的应用程序去操作远程串口设备。
## 语言和包
Python， serial，pyserial，Timer， socket，json， sys， threading


