#ifndef DIRECTIONKEY_H
#define DIRECTIONKEY_H

#include <QWidget>

namespace Ui {
class DirectionKey;
}

class DirectionKey : public QWidget
{
  Q_OBJECT

public:
  explicit DirectionKey(QWidget *parent = 0);
  ~DirectionKey();

private:
  Ui::DirectionKey *ui;
};

#endif // DIRECTIONKEY_H
