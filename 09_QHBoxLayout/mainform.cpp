#include "mainform.h"
#include <QHBoxLayout>

MainForm::MainForm(QWidget *parent) : QWidget(parent) {
  this->setupUI();
}

MainForm::~MainForm() {
  delete button1;
  delete button2;
  delete button3;
  delete button4;
}

void MainForm::setupUI() {
  this->resize(300,100);
  this->move(300,300);
  this->setWindowTitle("Coba Horizontal Layout dengan QHBoxLayout");

  button1 = new QPushButton("Tombol 1");
  button2 = new QPushButton("Tombol 2");
  button3 = new QPushButton("Tombol 3");
  button4 = new QPushButton("Tombol 4");

  QHBoxLayout *layout = new QHBoxLayout();

  layout->addWidget(button1);
  layout->addWidget(button2);
  layout->addWidget(button3);
  layout->addWidget(button4);

  this->setLayout(layout);
}
