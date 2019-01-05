#include <QCoreApplication>
#include <QDebug>

int main(int argc, char *argv[]) {
  QCoreApplication apps(argc, argv);

  QString a = "Ini A";
  QString b = "Ini B";
  QString c = "Ini C";

  QString gabungkanX = a + b + c;
  QString gabungkanY = a + " " + b + " " + c;

  qDebug() << gabungkanX;
  qDebug() << gabungkanY;

  return apps.exec();
}
