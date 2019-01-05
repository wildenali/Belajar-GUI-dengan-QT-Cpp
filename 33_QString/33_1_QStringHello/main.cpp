#include <QCoreApplication>
#include <QDebug>

int main(int argc, char *argv[]) {
  QCoreApplication a(argc, argv);

  // Deklarasi pointer ke tipe QString
  QString *s;

  // Membuat objek yang ditunjuk oleh pointer s
  s = new QString("C++ dan Qt");

  qDebug() << *s;

  // Menghapus objek QString setelah digunakan
  delete s;

  return a.exec();
}
