#include "widget.h"
#include <QDebug>
#include <windows.h>
Widget::Widget(QWidget *parent)
  : QWidget(parent) {
  createView();
}

Widget::~Widget() {

}
void Widget::createView() {
  //添加界面
  QPushButton *openThread = new QPushButton(tr("打开线程"));
  QPushButton *closeThread = new QPushButton(tr("关闭线程"));
  mainLayout = new QVBoxLayout(this);
  mainLayout->addWidget(openThread);//-----------注意
  mainLayout->addWidget(closeThread);//----------注意
  mainLayout->addStretch();
  connect(openThread,SIGNAL(clicked(bool)),this,SLOT(onOpenThreadBtn()));
  connect(closeThread,SIGNAL(clicked(bool)),this,SLOT(onCloseThreadBtn()));

  //线程初始化
  thread1 = new MyThread();//-------------注意
  connect(thread1,SIGNAL(finished()),this,SLOT(onFinishedThreadBtn()));
}
void Widget::onOpenThreadBtn() {
  //开启一个线程
  thread1->start();
  qDebug()<<"Parent id:"<<QThread::currentThreadId();
}

void Widget::onCloseThreadBtn() {
  thread1->CloseThread();
  thread1->wait();
}

void Widget::onFinishedThreadBtn() {
  qDebug()<<tr("finished and tarch");
}
