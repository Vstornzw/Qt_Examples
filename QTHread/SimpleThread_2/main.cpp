#include "widget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  Widget w;
  w.resize(960,640);
  w.show();

  return a.exec();
}
/*
a1：首先创建一个类MyThread，基类为QObject。

a2：在类MyThread中创建一个槽函数，用于运行多线程里面的代码。所有耗时代码，全部在这个槽函数里面运行。

a3：实例一个QThread线程对象（容器），将类MyThread的实例对象转到该容器中，用函数void QObject::moveToThread(QThread *thread);

myObjectThread->moveToThread(firstThread);

a4：用一个信号触发该多线程槽函数，比如用QThread::started()信号。
connect(firstThread,SIGNAL(started()),myObjectThread,SLOT(startThreadSlot()));

a5：用信号QThread::finished绑定槽函数QThread::deleteLatater()，在线程退出时，销毁该线程和相关资源。
connect(firstThread,SIGNAL(finished()),firstThread,SLOT(deleteLater()));

a6：所有线程初始化完成后，启动函数QThread::start()开启多线程，然后自动触发多线程启动信号QThread::started()。
*/
