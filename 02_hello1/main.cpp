#include "MinimalForm.h"
#include <QApplication>

int main(int argc, char* argv[]) {
  QApplication a(argc, argv);
  MinimalForm *form = new MinimalForm(NULL);
  form -> show();

  return a.exec();
}
