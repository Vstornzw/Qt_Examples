#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QThread>
class MyThread : public QThread
{
public:
  MyThread();
  void CloseThread();

protected:
  virtual void run();
private:
  volatile bool isStop;//isStop是易失性变量，需要用volatile 进行声明
};

#endif // MYTHREAD_H
