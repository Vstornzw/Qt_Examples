#include "DirectionKey.h"
#include "ui_DirectionKey.h"

DirectionKey::DirectionKey(QWidget *parent) :
  QWidget(parent),
  ui(new Ui::DirectionKey)
{
  ui->setupUi(this);
}

DirectionKey::~DirectionKey()
{
  delete ui;
}

