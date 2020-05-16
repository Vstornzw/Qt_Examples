#ifndef MAINAUTOPAGE_H
#define MAINAUTOPAGE_H

#include <QWidget>
#include "DirectionKey.h"

namespace Ui {
class MainAutoPage;
}


class MainAutoPage : public QWidget
{
  Q_OBJECT

public:
  explicit MainAutoPage(QWidget *parent = 0);
  ~MainAutoPage();

  /* 可以在子类中重新实现此事件处理程序，以接收在事件参数中传递的窗口小部件调整大小事件。*/
  virtual void resizeEvent(QResizeEvent *event);

private:

  DirectionKey *direction_key_;
  Ui::MainAutoPage *ui_;
};



#endif // MAINAUTOPAGE_H
