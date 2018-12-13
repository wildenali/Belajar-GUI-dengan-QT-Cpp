#include "mainform.h"
#include <QGridLayout>

MainForm::MainForm(QWidget *parent) : QWidget(parent) {
  this->setupUI();
}

MainForm::~MainForm() {
  delete label1;
  delete lineEdit1;
  delete label2;
  delete lineEdit2;
  delete button1;
}

void MainForm::setupUI() {
  this->resize(300,400);
  this->move(300,300);
  this->setWindowTitle("Phonebook dengan posisi menggunakan Grid Layout");

  label1 = new QLabel("Nama");
  lineEdit1 = new QLineEdit();

  label2= new QLabel("No Hp");
  lineEdit2 = new QLineEdit();

  button1 = new QPushButton("Okey");

  QGridLayout *layout = new QGridLayout();
  layout->addWidget(label1, 0, 0);
  layout->addWidget(lineEdit1, 0, 1);
  layout->addWidget(label2, 1, 0);
  layout->addWidget(lineEdit2, 1, 1);
  layout->addWidget(button1, 2, 0, 1, 2);

  this->setLayout(layout);
}
