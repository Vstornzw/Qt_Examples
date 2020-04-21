#include "MainAutoPage.h"
#include <QApplication>

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  MainAutoPage w;
  w.show();

  return a.exec();
}
