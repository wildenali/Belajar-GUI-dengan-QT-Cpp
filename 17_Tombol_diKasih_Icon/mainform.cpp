#include "mainform.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QIcon>

MainForm::MainForm(QWidget *parent) : QWidget(parent) {
  this->setupUI();
}

MainForm::~MainForm() {
  delete label;
  delete button1;
  delete button2;
  delete button3;
}

void MainForm::setupUI() {
  this->resize(400,100);
  this->move(500,200);
  this->setWindowTitle("QPushButton pake Icon");

  label = new QLabel();
  label->setText("QPushButton pakai gambar ICON");

  QIcon icon1("monyet.jpeg");
  button1 = new QPushButton("\tTambah");
  button1->setIcon(icon1);

  QIcon icon2("monyet.jpeg");
  button2 = new QPushButton("\tHapus");
  button2->setIcon(icon2);

  QIcon icon3("monyet.jpeg");
  button3 = new QPushButton("\tRefresh");
  button3->setIcon(icon3);

  QHBoxLayout *hbox = new QHBoxLayout();
  hbox->addWidget(button1);
  hbox->addWidget(button2);
  hbox->addWidget(button3);

  QVBoxLayout *layout = new QVBoxLayout();
  layout->addWidget(label);
  layout->addLayout(hbox);

  this->setLayout(layout);

}
