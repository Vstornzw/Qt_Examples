#include "widget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  Widget w;
  w.resize(500,500);
  w.show();

  return a.exec();
}
/*创建多线程步骤如下：

a1新建一个类MyThread，基类为QThread。

a2重写类MyThread的虚函数void run();，即新建一个函数protected void run()，然后对其进行定义。

a3在需要用到多线程的地方，实例MyThread，然后调用函数MyThread::start()后，则开启一条线程，自动运行函数run()。

a4当停止线程时，调用MyThread::wait()函数，等待线程结束，并且回收线程资源。
*/
