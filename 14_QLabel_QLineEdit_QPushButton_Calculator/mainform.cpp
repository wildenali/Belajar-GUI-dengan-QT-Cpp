#include "mainform.h"
#include <QVBoxLayout>
#include <QHBoxLayout>

MainForm::MainForm(QWidget *parent) : QWidget(parent) {
  this->setupUI();
}

MainForm::~MainForm() {
  delete label1;
  delete numberEdit1;
  delete label2;
  delete numberEdit2;
  delete label3;
  delete resultEdit;
  delete addButton;
  delete substactButton;
  delete mulButton;
  delete divButton;
  delete verticalLine;
}

void MainForm::setupUI() {
  this->resize(400,200);
  this->move(500,200);
  this->setWindowTitle("QLabel, QLineEdit, QPushButton di Kalkulator");

  label1 = new QLabel();
  label1->setText("Bilangan Pertama");
  numberEdit1 = new QLineEdit();

  label2 = new QLabel();
  label2->setText("Bilangan Kedua");
  numberEdit2 = new QLineEdit();

  label3 = new QLabel();
  label3->setText("Hasil Perhitungan");
  resultEdit = new QLineEdit();
  resultEdit->setReadOnly(true);    // si resultEdit di seting HANYA BACA aja

  QVBoxLayout *vbox1 = new QVBoxLayout();
  vbox1->addWidget(label1);
  vbox1->addWidget(numberEdit1);
  vbox1->addWidget(label2);
  vbox1->addWidget(numberEdit2);
  vbox1->addWidget(label3);
  vbox1->addWidget(resultEdit);
  vbox1->addStretch();

  addButton = new QPushButton("&Tambah");       // kenapa ada tanda '&' disitu, karena itu buat shortcut
  substactButton = new QPushButton("&Kurang");  // jadi kalau mau cepet tinggal pencet ALT+T untuk tambah
  mulButton = new QPushButton("K&ali");         // ALT+K untuk Kurang, ALT+a untuk kAli
  divButton = new QPushButton("&Bagi");         // ALT+B untuk Bagi

  QVBoxLayout * vbox2 = new QVBoxLayout();
  vbox2->addWidget(addButton);
  vbox2->addWidget(substactButton);
  vbox2->addWidget(mulButton);
  vbox2->addWidget(divButton);
  vbox2->addStretch();

  verticalLine = new QFrame();
  verticalLine->setFrameShape(QFrame::VLine);
  verticalLine->setFrameShadow(QFrame::Sunken);

  QHBoxLayout *layout = new QHBoxLayout();
  layout->addLayout(vbox1);
  layout->addWidget(verticalLine);
  layout->addLayout(vbox2);

  this->setLayout(layout);

  connect(addButton, SIGNAL(clicked()), this, SLOT(on_addButton_clicked()));
  connect(substactButton, SIGNAL(clicked()), this, SLOT(on_substractButton_clicked()));
  connect(mulButton, SIGNAL(clicked()), this, SLOT(on_mulButton_clicked()));
  connect(divButton, SIGNAL(clicked()), this, SLOT(on_divButton_clicked()));
}

void MainForm::calculate(char op) {
  double a = numberEdit1->text().toDouble();
  double b = numberEdit2->text().toDouble();
  double c = 0.0;
  switch (op) {
    case '+': c = a + b; break;
    case '-': c = a - b; break;
    case '*': c = a * b; break;
    case '/': c = a / b; break;
  }
  QString s;
  resultEdit->setText(s.setNum(c));
}

void MainForm::on_addButton_clicked() {
  this->calculate('+');
}

void MainForm::on_substractButton_clicked() {
  this->calculate('-');
}

void MainForm::on_mulButton_clicked() {
  this->calculate('*');
}

void MainForm::on_divButton_clicked() {
  this->calculate('/');
}
