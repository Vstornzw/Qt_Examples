参考网址：https://blog.csdn.net/cloud_castle/article/details/21789723


第一步：服务器
tcpServer = new QTcpServer(this);
 if (!tcpServer->listen()) {// 新建 Tcp 服务并开始监听，这个监听是基于所有地址，任意端口的<span style="font-family: Arial, Helvetica, sans-serif;">                              </span>
      QMessageBox::critical(this, tr("Fortune Server"),
                            tr("Unable to start the server: %1.")
                            .arg(tcpServer->errorString()));
      close();
      return;
  }

第二步：客户端
由connect(getFortuneButton, &QAbstractButton::clicked,
            this, &Client::requestNewFortune);
到
tcpSocket->connectToHost(hostCombo->currentText(),
                             portLineEdit->text().toInt());//连接到主机，第一个参数是IP地址，第二个参数是端口号，第三个参数默认值为读写
第三步：客户端判断 
1>能连接上
服务器：connect(tcpServer, &QTcpServer::newConnection, this, &Server::sendFortune);//发送消息
客户端： connect(tcpSocket, &QIODevice::readyRead, this, &Client::readFortune);//接受消息
2>不能连接上
客户端：
 typedef void (QAbstractSocket::*QAbstractSocketErrorSignal)(QAbstractSocket::SocketError);
    connect(tcpSocket, static_cast<QAbstractSocketErrorSignal>(&QAbstractSocket::error), this, &Client::displayError);


void Client::displayError(QAbstractSocket::SocketError socketError)// 这个SocketError是抽象基类的枚举对象，因此对所有套接字都是通用的
{
    switch (socketError) {
    case QAbstractSocket::RemoteHostClosedError:
        break;
    case QAbstractSocket::HostNotFoundError:
        QMessageBox::information(this, tr("Fortune Client"),
                                 tr("The host was not found. Please check the "
                                    "host name and port settings."));
        break;
    case QAbstractSocket::ConnectionRefusedError:
        QMessageBox::information(this, tr("Fortune Client"),
                                 tr("The connection was refused by the peer. "
                                    "Make sure the fortune server is running, "
                                    "and check that the host name and port "
                                    "settings are correct."));
        break;
    default:
        QMessageBox::information(this, tr("Fortune Client"),
                                 tr("The following error occurred: %1.")
                                 .arg(tcpSocket->errorString()));
    }

    getFortuneButton->setEnabled(true);
}

ll
