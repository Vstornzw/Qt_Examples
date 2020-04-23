//#include <QtWidgets/QApplication>
//#include <QWaitCondition>
//#include <QMutex>
//#include <QThread>

//QMutex mutex;              //各线程的全局量
//QWaitCondition incNumber;  //各线程的全局量
//int numUsed;               //producer 和 consumer 的共享变量

//class Producer : public QThread
//{
//public:
//    Producer() {}
//protected:
//    void run()
//    {
//        for(int i = 0 ; i < 10 ; i++){
//            //sleep(1);
//            mutex.lock();  //注意此互斥量生产者与消费者共享
//            ++numUsed;
//            incNumber.wakeAll();
//        qDebug("Producer-numUsed : %d", numUsed);
//            mutex.unlock();
//        }
//    }
//};

//class Consumer : public QThread
//{
//public:
//    Consumer(){}
//protected:
//    void run()
//    {
//        for(int i = 0 ; i < 10 ; i++)
//        {
//            mutex.lock();
//            //incNumber.wait(&mutex);  //此处mutex与生产者是同一个，所以会等待生产者线程
//       qDebug("Consumer-numUsed : %d", numUsed);
//            mutex.unlock();        }
//    }
//};

//int main(int argc, char *argv[])
//{
//  //QApplication a(argc, argv);
//  //Widget w;
//  //w.show();

//  QCoreApplication a(argc, argv);

//  Producer producer;
//  Consumer consumer;
//  producer.start();
//  consumer.start();

//  return a.exec();
//}

#include <QApplication>
#include <QMutex>
#include <QThread>
#include <QSemaphore>
#include <QWaitCondition>
#include <iostream>
using namespace std;

// 需要生产的数据量
const int DATA_SIZE = 100;

//指定缓冲区的大小
const int BUF_SIZE = 10;

// 存/取数据的缓冲区
int buf[BUF_SIZE] = {0};

//实现线程之间的互斥
QMutex mutex;

//当缓冲区不充满时，该条件被触发(反之，当缓冲区被填充满了，该条件会阻塞线程)
QWaitCondition bufIsNotFull;

//当缓冲区不为空时，该条件被触发(反之，当缓冲区为空时，该条件会阻塞线程)
QWaitCondition bufIsNotEmpty;

//统计生产的且还没有被消费的数据量
int nUsedSapce = 0;





class CProducer : public QThread
{
protected:
    virtual void run()
    {
        for (int i = 0 ; i < DATA_SIZE ; ++i)
        {
            mutex.lock();
            if (nUsedSapce == BUF_SIZE)// 如果缓冲区已填满，则等待缓冲区中的数据被取走
                bufIsNotFull.wait(&mutex);// 在阻塞线程前，bufIsNotFull会解锁互斥量，然后阻塞线程，等待bufIsNotFull条件对象被触发，在返回前，会重新锁定互斥量，然后返回

            buf[i%BUF_SIZE] = qrand() % 50 + 1;// 保存生产的数据
            cout << "produce data is :" <<i%BUF_SIZE<<"  "<< buf[i%BUF_SIZE] << endl;

            ++nUsedSapce;// 生产了一个数据

            bufIsNotEmpty.wakeAll();// 唤醒所有等待bufIsNotEmpty条件的线程

            mutex.unlock();
        }
    }
};

class CConsumer : public QThread
{
protected:
    virtual void run()
    {
        for (int i = 0 ; i < DATA_SIZE ; ++i)
        {
            mutex.lock();
            if (nUsedSapce == 0)// 如果缓冲区为空，那么等待缓冲区被填充数据
                bufIsNotEmpty.wait(&mutex);// 在阻塞线程前，bufIsNotEmpty会解锁互斥量，然后阻塞线程，等待bufIsNotEmpty条件对象被触发，在返回前，bufIsNotEmpty会重新锁定互斥量，然后返回

            int nData = buf[i%BUF_SIZE];// 取出要消费的数据
            cout << "consume data is :" <<i%BUF_SIZE<<"  "<< nData << endl;

            --nUsedSapce;// 消费了一个数据

            bufIsNotFull.wakeAll();// 唤醒所有等待bufIsNotFull条件的线程

            mutex.unlock();
        }

    }
};


int main(int argc, char *agcv[]) {

  QApplication app(argc,agcv);

  CProducer producer;
  CConsumer consumer;

  producer.start();
  consumer.start();

  producer.wait();
  consumer.wait();

  return app.exec();
}



/*produce data is :42
produce data is :18
consume data is: 42
produce data is :35
consume data is: 18
produce data is :1
consume data is: 35
produce data is :20
consume data is: 1
produce data is :25
consume data is: 20
produce data is :29
consume data is: 25
produce data is :9
consume data is: 29
produce data is :13
consume data is: 9
produce data is :15
consume data is: 13
produce data is :6
consume data is: 15
produce data is :46
consume data is: 6
produce data is :32
consume data is: 46
produce data is :28
consume data is: 32
produce data is :12
consume data is: 28
produce data is :42
consume data is: 12
produce data is :46
consume data is: 42
produce data is :43
consume data is: 46
produce data is :28
consume data is: 43
produce data is :37
consume data is: 28
produce data is :42
consume data is: 37
produce data is :5
consume data is: 42
produce data is :3
consume data is: 5
produce data is :4
consume data is: 3
produce data is :43
consume data is: 4
produce data is :33
consume data is: 43
produce data is :22
consume data is: 33
produce data is :17
consume data is: 22
produce data is :19
consume data is: 17
produce data is :46
consume data is: 19
produce data is :48
consume data is: 46
produce data is :27
consume data is: 48
produce data is :22
consume data is: 27
produce data is :39
consume data is: 22
produce data is :20
consume data is: 39
produce data is :13
consume data is: 20
produce data is :18
consume data is: 13
produce data is :50
consume data is: 18
produce data is :36
consume data is: 50
produce data is :45
consume data is: 36
produce data is :4
consume data is: 45
produce data is :12
consume data is: 4
produce data is :23
consume data is: 12
produce data is :34
consume data is: 23
produce data is :24
consume data is: 34
produce data is :15
consume data is: 24
produce data is :42
consume data is: 15
produce data is :12
consume data is: 42
produce data is :4
consume data is: 12
produce data is :19
consume data is: 4
produce data is :48
consume data is: 19
produce data is :45
consume data is: 48
produce data is :13
consume data is: 45
produce data is :8
consume data is: 13
produce data is :38
consume data is: 8
produce data is :10
consume data is: 38
produce data is :24
consume data is: 10
produce data is :42
consume data is: 24
produce data is :30
consume data is: 42
produce data is :29
consume data is: 30
produce data is :17
consume data is: 29
produce data is :36
consume data is: 17
produce data is :41
consume data is: 36
produce data is :43
consume data is: 41
produce data is :39
consume data is: 43
produce data is :7
consume data is: 39
produce data is :41
consume data is: 7
produce data is :43
consume data is: 41
produce data is :15
consume data is: 43
produce data is :49
consume data is: 15
produce data is :47
consume data is: 49
produce data is :6
consume data is: 47
produce data is :41
consume data is: 6
produce data is :30
consume data is: 41
produce data is :21
consume data is: 30
produce data is :1
consume data is: 21
produce data is :7
consume data is: 1
produce data is :2
consume data is: 7
produce data is :44
consume data is: 2
produce data is :49
consume data is: 44
produce data is :30
consume data is: 49
produce data is :24
consume data is: 30
produce data is :35
consume data is: 24
produce data is :5
consume data is: 35
produce data is :7
consume data is: 5
produce data is :41
consume data is: 7
produce data is :17
consume data is: 41
produce data is :27
consume data is: 17
produce data is :32
consume data is: 27
produce data is :9
consume data is: 32
produce data is :45
consume data is: 9
produce data is :40
consume data is: 45
produce data is :27
consume data is: 40
produce data is :24
consume data is: 27
produce data is :38
consume data is: 24
produce data is :39
consume data is: 38
produce data is :19
consume data is: 39
produce data is :33
consume data is: 19
produce data is :30
consume data is: 33
produce data is :42
consume data is: 30
consume data is: 42
*/
