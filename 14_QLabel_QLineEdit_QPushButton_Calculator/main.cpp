#include "mainform.h"
#include <QApplication>

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);

  MainForm *form = new MainForm(NULL);

  form->show();

  return a.exec();
}
