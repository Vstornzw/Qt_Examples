#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QObject>

class MyThread : public QObject
{
  Q_OBJECT
public:
  explicit MyThread(QObject *parent = 0);

  void CloseThread();

signals:

public slots:
  void onStartThread();
private:
  volatile bool isStop;
};

#endif // MYTHREAD_H
