#include "mainform.h"
#include <QHBoxLayout>
#include <QVBoxLayout>

MainForm::MainForm(QWidget *parent) : QWidget(parent) {
  this->setupUI();
}

MainForm::~MainForm() {
  delete lineEdit;
  delete button1;
  delete button2;
}

void MainForm::setupUI() {
  this->resize(300,100);
  this->move(500, 200);
  this->setWindowTitle("Test SIGNAL dan SLOT");

  lineEdit = new QLineEdit("Cobain SIGNAL dan SLOT");

  button1 = new QPushButton("Bersihkan");
  button2 = new QPushButton("Keluar");

  QHBoxLayout *hbox = new QHBoxLayout();
  hbox->addWidget(button1);
  hbox->addWidget(button2);

  QVBoxLayout *layout = new QVBoxLayout();
  layout->addWidget(lineEdit);
  layout->addLayout(hbox);

  this->setLayout(layout);

  // Cara Menghubungkan SIGNAL dan SLOT
  connect(button1, SIGNAL(clicked()), lineEdit, SLOT(clear()));
  connect(button2, SIGNAL(clicked()), this, SLOT(close()));
}
