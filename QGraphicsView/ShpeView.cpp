#include "ShpeView.h"
#include <QToolTip>
ShpeView::ShpeView(QWidget *parent) : QGraphicsView(parent) {

}

//当按下鼠标时候，显示鼠标的坐标
void ShpeView::mouseMoveEvent(QMouseEvent *event) {
  m_pos_ = mapToScene(event->pos());
  QString pos = QString("X%1, Y%2").arg(m_pos_.x(), 0, 'f', 2).arg(m_pos_.y(), 0, 'f', 2);
  QToolTip::showText(event->globalPos(),pos,this);
}
