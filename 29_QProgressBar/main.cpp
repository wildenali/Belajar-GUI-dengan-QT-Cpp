#include "mainform.h"
#include <QApplication>

int main(int argc, char* argv[]) {
  QApplication apps(argc, argv);

  MainForm *form = new MainForm(NULL);

  form->show();

  return apps.exec();
}
