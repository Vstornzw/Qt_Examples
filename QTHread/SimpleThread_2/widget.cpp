#include "widget.h"
#include <QDebug>


Widget::Widget(QWidget *parent)
  : QWidget(parent) {

  CreateView();
}

Widget::~Widget()
{

}

void Widget::CreateView()
{
    /*UI界面*/
    mainLayout = new QVBoxLayout(this);
    QPushButton *openThreadBtn = new QPushButton(tr("打开线程"));
    QPushButton *closeThreadBtn = new QPushButton(tr("关闭线程"));
    mainLayout->addWidget(openThreadBtn);
    mainLayout->addWidget(closeThreadBtn);
    mainLayout->addStretch();
    connect(openThreadBtn,SIGNAL(clicked(bool)),this,SLOT(onOpenThrea()));
    connect(closeThreadBtn,SIGNAL(clicked(bool)),this,SLOT(CloseThread()));
}

void Widget::onOpenThrea() {
  //开启一条多线程
  qDebug()<<tr("start thread");
  firstThread = new QThread;        //线程容器
  myObjectThread = new MyThread;
  myObjectThread->moveToThread(firstThread); //将创建的对象移到线程容器中

  connect(firstThread,SIGNAL(started()),myObjectThread,SLOT(onStartThread()));//开启线程槽函数

  connect(firstThread,SIGNAL(finished()),myObjectThread,SLOT(deleteLater()));//终止线程时要调用deleteLater槽函数
  connect(firstThread,SIGNAL(finished()),this,SLOT(FinishedThread()));
  firstThread->start();
  qDebug()<<"mainWidget QThread::curreantThreadId=="<<QThread::currentThreadId();
}

void Widget::CloseThread() {
  qDebug()<<tr("filish thread");
  if(firstThread->isRunning()) {
    myObjectThread->CloseThread(); //关闭线程槽函数
    firstThread->quit();           //退出事件循环
    firstThread->wait();           //释放线程槽函数
  }
}
void Widget::FinishedThread() {
  qDebug()<<tr("thread torch 123 information");
}
