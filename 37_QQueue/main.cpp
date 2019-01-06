#include <QCoreApplication>
#include <QDebug>
#include <QtCore/QQueue>

/*
    kelas QStack adalah kontainer yang merepresentasikan struktur data antrian (queue)
    Data stack yang dimasukan pertama kali akan di ambil pertama kali (first-in first-out) FIFO
*/

int main(int argc, char *argv[]) {
  QCoreApplication apps(argc, argv);

  QQueue<int> q;

  // meMASUKan data
  q.enqueue(10);
  q.enqueue(20);
  q.enqueue(30);
  q.enqueue(40);
  q.enqueue(50);

  qDebug() << "Ukuran queue: " << q.size();

  int n = q.size();
  for (int i = 0; i < n; i++) {
    qDebug() << q.dequeue();    // diKELUARin
  }
  qDebug() << "Ukuran dequeue: " << q.size();

  return apps.exec();
}
