#include "mainform.h"
#include <QGridLayout>

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
  this->resize(300,400);
  this->move(300,300);
  this->setWindowTitle("Grid Layout dengan QGridLayout");

  button1 = new QPushButton("Tombol 1");
  button2 = new QPushButton("Tombol 2");
  button3 = new QPushButton("Tombol 3");
  button4 = new QPushButton("Tombol 4");

  QGridLayout *layout = new QGridLayout();
  layout->addWidget(button1, 0, 0);
  layout->addWidget(button2, 0, 1);
  layout->addWidget(button3, 1, 0);
  layout->addWidget(button4, 1, 1);

  this->setLayout(layout);
}
