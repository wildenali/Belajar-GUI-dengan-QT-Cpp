#include "mainform.h"
#include <QVBoxLayout>

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
  this->resize(300,200);
  this->move(300,300);
  this->setWindowTitle("Coba QVBoxLayout");

  button1 = new QPushButton("Button 1");
  button2 = new QPushButton("Button 2");
  button3 = new QPushButton("Button 3");
  button4 = new QPushButton("Button 4");

  QVBoxLayout *layout = new QVBoxLayout();
  layout->addWidget(button1);
  layout->addWidget(button2);
  layout->addWidget(button3);
  layout->addWidget(button4);

  this->setLayout(layout);
}
