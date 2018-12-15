#include "mainform.h"
#include <QVBoxLayout>
#include <QPixmap>

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
  this->setWindowTitle("fungsi setPixmap() dari Kelas QLabel");

  label1 = new QLabel();
  label1->setText("Menampilkan GAMBAR dengan menggunakan fungsi setPixmap dari kelas QLabel");

  QPixmap pixmap("monyet.jpeg");
  label2 = new QLabel();
  label2->setPixmap(pixmap);

  QVBoxLayout *layout = new QVBoxLayout();
  layout->addWidget(label1);
  layout->addWidget(label2);

  this->setLayout(layout);
}
