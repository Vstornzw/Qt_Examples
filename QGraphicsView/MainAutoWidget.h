#ifndef MAINAUTOWIDGET_H
#define MAINAUTOWIDGET_H

#include <QWidget>

namespace Ui {
class MainAutoWidget;
}



class MainAutoWidget : public QWidget
{
  Q_OBJECT

public:
  explicit MainAutoWidget(QWidget *parent = 0);
  ~MainAutoWidget();



private:
  Ui::MainAutoWidget *ui_;
};




#endif // MAINAUTOWIDGET_H
