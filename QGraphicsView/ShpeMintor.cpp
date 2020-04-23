#include "ShpeMintor.h"
#include "ui_ShpeMintor.h"



ShpeMintor::ShpeMintor(QWidget *parent) :
  QWidget(parent),
  ui_(new Ui::ShpeMintor)
{
  ui_->setupUi(this);
  graphicssrence = new QGraphicsScene();
  QPen pen;
  pen.setColor(QColor(255,0,0));
  pen.setWidth(2);
  graphicssrence->addRect(0.0,0.0,100.0,100.0,pen);
  ui_->shpeView->setScene(graphicssrence);

}

ShpeMintor::~ShpeMintor()
{
  delete ui_;
}


