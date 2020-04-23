#include "MainAutoPage.h"
#include "ui_MainAutoPage.h"



MainAutoPage::MainAutoPage(QWidget *parent) :
  QWidget(parent),
  ui_(new Ui::MainAutoPage) {
  ui_->setupUi(this);

  ui_->widget_left->setVisible(false);

  direction_key_ = new DirectionKey(this);
}

MainAutoPage::~MainAutoPage() {
  delete ui_;
}

void MainAutoPage::resizeEvent(QResizeEvent *event) {
  direction_key_->setGeometry(ui_->widget_->width() - direction_key_->width(),
                               ui_->widget_->height() - direction_key_->height(),
                               direction_key_->width(), direction_key_->height());
  QWidget::resizeEvent(event);
}

