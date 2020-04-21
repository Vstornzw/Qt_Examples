#ifndef SHPEVIEW_H
#define SHPEVIEW_H

#include <QGraphicsView>
#include <QMouseEvent>
#include <QPointF>
class ShpeView : public QGraphicsView
{
public:
  ShpeView(QWidget *parent = NULL);
protected:
  void mouseMoveEvent(QMouseEvent *event);
  QPointF m_pos_;
};



#endif // SHPEVIEW_H
