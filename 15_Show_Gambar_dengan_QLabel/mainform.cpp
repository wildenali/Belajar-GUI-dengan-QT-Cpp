#include "mainform.h"
#include <QVBoxLayout>

MainForm::MainForm(QWidget *parent) : QWidget(parent) {
  this->setupUI();
}

MainForm::~MainForm() {
  delete label1;
  delete label2;
}

void MainForm::setupUI() {
  this->resize(400,200);
  this->move(500,200);
  this->setWindowTitle("Add Gambar dengan QLabel");

  label1 = new QLabel();
  label1->setText("Menampilkan GAMBAR dengan QLabel");

  label2 = new QLabel();
  label2->setText("<img src=\"monyet.jpeg\">");

  QVBoxLayout *layout = new QVBoxLayout();
  layout->addWidget(label1);
  layout->addWidget(label2);

  this->setLayout(layout);
}
