#include "MainAutoWidget.h"
#include "ui_MainAutoWidget.h"
#include <QAction>



MainAutoWidget::MainAutoWidget(QWidget *parent) :
  QWidget(parent),
  ui_(new Ui::MainAutoWidget) {

  ui_->setupUi(this);
}

MainAutoWidget::~MainAutoWidget() {
  delete ui_;
}


