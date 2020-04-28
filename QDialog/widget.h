#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "dialog.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
  Q_OBJECT

public slots:
  void onShowDialog();
public:
  explicit Widget(QWidget *parent = 0);
  ~Widget();

private:
  Ui::Widget *ui;
  Dialog *dialog;
  bool status;
};

#endif // WIDGET_H
