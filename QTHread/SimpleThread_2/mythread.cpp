#include "mythread.h"
#include <QDebug>
#include <QThread>
MyThread::MyThread(QObject *parent) : QObject(parent)
{
  isStop = false;
}

void MyThread::CloseThread() {
  isStop = true;
}

void MyThread::StartThread() {
  while(1) {
    if(isStop) {
      return;
    }
    qDebug()<<"MyThread::startThreadSlot QThread::currentThreadId()=="<<QThread::currentThreadId();
    QThread::sleep(1);
  }
}
