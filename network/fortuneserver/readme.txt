��һ����������
tcpServer = new QTcpServer(this);
 if (!tcpServer->listen()) {// �½� Tcp ���񲢿�ʼ��������������ǻ������е�ַ������˿ڵ�<span style="font-family: Arial, Helvetica, sans-serif;">                              </span>
      QMessageBox::critical(this, tr("Fortune Server"),
                            tr("Unable to start the server: %1.")
                            .arg(tcpServer->errorString()));
      close();
      return;
  }

�ڶ������ͻ���
��connect(getFortuneButton, &QAbstractButton::clicked,
            this, &Client::requestNewFortune);
��
tcpSocket->connectToHost(hostCombo->currentText(),
                             portLineEdit->text().toInt());//���ӵ���������һ��������IP��ַ���ڶ��������Ƕ˿ںţ�����������Ĭ��ֵΪ��д
���������ͻ����ж� 
1>��������
��������connect(tcpServer, &QTcpServer::newConnection, this, &Server::sendFortune);//������Ϣ
�ͻ��ˣ� connect(tcpSocket, &QIODevice::readyRead, this, &Client::readFortune);//������Ϣ
2>����������
�ͻ��ˣ�
 typedef void (QAbstractSocket::*QAbstractSocketErrorSignal)(QAbstractSocket::SocketError);
    connect(tcpSocket, static_cast<QAbstractSocketErrorSignal>(&QAbstractSocket::error), this, &Client::displayError);


void Client::displayError(QAbstractSocket::SocketError socketError)// ���SocketError�ǳ�������ö�ٶ�����˶������׽��ֶ���ͨ�õ�
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

lll