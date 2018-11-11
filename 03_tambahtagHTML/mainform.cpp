#include "mainform.h"

MainForm::MainForm(QWidget *parent) : QWidget(parent) {
  this -> setupUi();
}

MainForm::~MainForm() {
  delete label1;
  delete label2;
}

void MainForm::setupUi() {
  this -> resize(500,300);
  this -> move(300,300);
  this -> setWindowTitle("Cobain tag HTML");

  label1 = new QLabel();
  label1 -> setText("<h1>Hay Tayo.. <font color=red> Bis Kecil </font></h1>");
  label1 -> move(10, 10);
  label1 -> setParent(this);

  QString str = tr("Cobain teks pakai <u>HTML</u> bisa apa kaga<br>") +
                tr("Tebel in teks <b>tebel nih</b><br>") +
                tr("Miring in teks <i>MIRING nih</i><br>") +
                tr("Garis Bawah in teks <u>parragraph</u><br>");

  label2 = new QLabel();
  label2 -> setText(str);
  // label2 -> setWordWrap(true);
  label2 -> move(100, 100);
  label2 -> setParent(this);
}
