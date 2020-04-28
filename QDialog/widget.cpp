#include "widget.h"
#include "ui_widget.h"


Widget::Widget(QWidget *parent) :
  QWidget(parent),
  ui(new Ui::Widget),
  status(false)
{
  ui->setupUi(this);
  dialog = new Dialog(this);
  dialog->setModal(true);

  connect(ui->push_button_,SIGNAL(clicked(bool)),this,SLOT(onShowDialog()));
}

Widget::~Widget()
{
  delete ui;
}

void Widget::onShowDialog() {
  if(!status){
    dialog->show();
    status = true;
  } else {
    dialog->hide();
    status = false;
  }
}
