#include "mythread.h"
#include<QDebug>
#include<QMutex>

MyThread::MyThread() {
  isStop = false;
}

void MyThread::CloseThread() {
  isStop = true;
}

void MyThread::run() {
  while(1) {
    if(isStop) {
      return ;
    }
    qDebug()<<tr("mythread QThreadId() ==")<<QThread::currentThreadId();
    sleep(1);
  }
}
