#include <QCoreApplication>
#include <QDebug>
#include <QtCore/QStack>

/*
    QStack adalah kelas kontainer di dalam Qt yang merepresentasikan struktur data
tumpukan(stack).
    Data stack yang dimasukan pertama kali akan di ambil terakhir kali (last-in first-out) LIFO
*/

int main(int argc, char *argv[]) {
  QCoreApplication apps(argc, argv);

  QStack<int> s;

  // meMASUKan data
  s.push(10);
  s.push(20);
  s.push(30);
  s.push(40);
  s.push(50);

  qDebug() << "Ukuran stack: " <<s.size();

  int n = s.size();
  for (int i = 0; i < n; i++) {
    qDebug() << s.pop();    // diKELUARin
  }
  qDebug() << "Ukuran stack: " << s.size();

  return apps.exec();
}
