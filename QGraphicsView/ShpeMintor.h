#ifndef SHPEMINTOR_H
#define SHPEMINTOR_H

#include <QWidget>
#include <QGraphicsScene>
#include <QPen>

namespace Ui {
class ShpeMintor;
}

class ShpeMintor : public QWidget
{
  Q_OBJECT

public:
  explicit ShpeMintor(QWidget *parent = 0);
  ~ShpeMintor();

private:
  QGraphicsScene *graphicssrence;
  Ui::ShpeMintor *ui_;
};

#endif // SHPEMINTOR_H
