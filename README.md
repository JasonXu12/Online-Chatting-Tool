# Online-Chatting-Tool
In this project, I design a real-time online chatting tool, which is based on C++. The user interface is based on MFC frame. 
1、登陆：直接输入学号与net2014即可
2、查询：直接输入学号，点击查询按钮
3、一对一通信：
   a、点击Access Server，与之前查询的对象建立连接（在点击之前，务必查询你想要连接的对象学号，并且确保对方在线，系统自动连接对象的IP地址）
   b、在“主动聊天区”输入内容
   c、点击Send to
   d、若要继续发送，则修改“主动聊天区内容”，点击Send to
   【若为被发消息方，则消息会显示在被动聊天区，修改其中内容，点击send则可以回复】
4、发送文件：
   a、在查询在线情况下，点击File Route
   b、点击Send Files选择并发送文件（由于未解决问题，文件大小不要超过31K）
5、群聊：在主动聊天区输入内容，点击群聊
6、下线：点击下线按钮
