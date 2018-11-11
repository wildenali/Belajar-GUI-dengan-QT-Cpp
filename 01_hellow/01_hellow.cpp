#include <QApplication>
#include <QWidget>
#include <QLabel>

int main(int argc, char* argv[]) {
  QApplication a(argc, argv);   // kode untuk membuat objek(instance)
  QWidget *form = new QWidget();  // pointer si QWidget

  form -> resize(500,200);    // panjang kali lebar
  form -> move(0,500);        // posisi form di layar
  form -> setWindowTitle("GUI hellow");

  QLabel *label = new QLabel("Hellow ini GUI");   // pointer si QLabel
  label -> move(55,40);       // Posisi tulisan
  label -> setParent(form);

  form -> show();

  return a.exec();            // kode ini berfungsi untuk pengulangan (event loop) dari aplikasi
                              // kode ini ini akan di eksekusi terus menerus, sampai kalau mau udahan pencet tanda silang(close di pencet)
}
