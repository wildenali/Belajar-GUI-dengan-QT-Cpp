#include "mainform.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QFile>
#include <QMessageBox>

using namespace std;

MainForm::MainForm(QWidget *parent) : QWidget(parent) {
  // membuat objek dari kelas QDir
  directory = new QDir();

  this->setupUI();
}

MainForm::~MainForm() {
  delete directory;

  delete groupBox1;
  delete label1;
  delete newDirEdit;
  delete createButton;

  delete groupBox2;
  delete label2;
  delete oldDirNameEdit;
  delete label3;
  delete newDirNameEdit;
  delete renameButton;

  delete groupBox3;
  delete label4;
  delete dirNameEdit;
  delete removeButton;
}

void MainForm::setupUI() {
  this->resize(400, 250);
  this->move(500, 150);
  this->setWindowTitle("QDir");

  groupBox1 = new QGroupBox("Membuat Direktori");
  label1 = new QLabel("Nama direktori yang akan dibuat");
  newDirEdit = new QLineEdit();
  createButton = new QPushButton("Buat Direktori");

  QVBoxLayout *vbox1 = new QVBoxLayout();
  vbox1->addWidget(label1);
  vbox1->addWidget(newDirEdit);
  QHBoxLayout *hbox1 = new QHBoxLayout();
  hbox1->addStretch();
  hbox1->addWidget(createButton);
  vbox1->addLayout(hbox1);
  groupBox1->setLayout(vbox1);


  groupBox2 = new QGroupBox("Mengubah Nama Direktori");
  label2 = new QLabel("Nama direktori lama");
  oldDirNameEdit = new QLineEdit();
  label3 = new QLabel("Nama direktori Baru");
  newDirNameEdit = new QLineEdit();
  renameButton = new QPushButton("Ubah Nama Direktori");

  QVBoxLayout *vbox2 = new QVBoxLayout();
  vbox2->addWidget(label2);
  vbox2->addWidget(oldDirNameEdit);
  vbox2->addWidget(label3);
  vbox2->addWidget(newDirNameEdit);
  QHBoxLayout *hbox2 = new QHBoxLayout();
  hbox2->addStretch();
  hbox2->addWidget(renameButton);
  vbox2->addLayout(hbox2);
  groupBox2->setLayout(vbox2);


  groupBox3 = new QGroupBox("Menghapus Nama Direktori");
  label4 = new QLabel("Nama direktori yang akan dihapus");
  dirNameEdit = new QLineEdit();
  removeButton = new QPushButton("Hapus Direktori");

  QVBoxLayout *vbox3 = new QVBoxLayout();
  vbox3->addWidget(label4);
  vbox3->addWidget(dirNameEdit);
  QHBoxLayout *hbox3 = new QHBoxLayout();
  hbox3->addStretch();
  hbox3->addWidget(removeButton);
  vbox3->addLayout(hbox3);
  groupBox3->setLayout(vbox3);


  QVBoxLayout *layout = new QVBoxLayout();
  layout->addWidget(groupBox1);
  layout->addWidget(groupBox2);
  layout->addWidget(groupBox3);
  layout->addStretch();

  this->setLayout(layout);

  connect(createButton, SIGNAL(clicked()), this, SLOT(on_createButton_clicked()));
  connect(renameButton, SIGNAL(clicked()), this, SLOT(on_renameButton_clicked()));
  connect(removeButton, SIGNAL(clicked()), this, SLOT(on_removeButton_clicked()));
}

void MainForm::on_createButton_clicked() {
  if (newDirEdit->text().trimmed().size() == 0) {
    QMessageBox::critical(this, "Kesalahan", "Nama Direktori harus di isi");
    newDirEdit->setFocus();
    return;
  }

  if (directory->exists(newDirEdit->text())) {
    QMessageBox::critical(this, "Kesalahan", "Nama Direktori sudah ada");
    newDirEdit->setFocus();
    return;
  }

  QString dirName = newDirEdit->text();

  if (directory->mkdir(dirName)) {
    QMessageBox::information(this, "Informasi", "Direktori \"" + dirName + "\" BERHASIL dibuat");
  } else {
    QMessageBox::critical(this, "Kesalahan", "File GAGAL dibuat");
  }
}

void MainForm::on_renameButton_clicked() {
  if (oldDirNameEdit->text().trimmed().size() == 0) {
    QMessageBox::critical(this, "Kesalahan", "Nama Direktori lama harus di isi");
    oldDirNameEdit->setFocus();
    return;
  }
  if (newDirNameEdit->text().trimmed().size() == 0) {
    QMessageBox::critical(this, "Kesalahan", "Nama Direktori baru harus di isi");
    newDirNameEdit->setFocus();
    return;
  }

  if (!directory->exists(oldDirNameEdit->text())) {
    QMessageBox::critical(this, "Kesalahan", "Nama Direktori tidak ditemukan");
    newDirEdit->setFocus();
    return;
  }

  QString oldDirName = oldDirNameEdit->text();
  QString newDirName = newDirNameEdit->text();

  if (directory->rename(oldDirName, newDirName)) {
    QMessageBox::information(this, "Informasi", "Direktori \"" + oldDirName + "\" telah BERUBAH menjadi" + newDirName);
  } else {
    QMessageBox::critical(this, "Kesalahan", "File GAGAL BERUBAH");
  }
}

void MainForm::on_removeButton_clicked() {
  if (dirNameEdit->text().trimmed().size() == 0) {
    QMessageBox::critical(this, "Kesalahan", "Nama Direktori harus di isi");
    dirNameEdit->setFocus();
    return;
  }

  if (!directory->exists(dirNameEdit->text())) {
    QMessageBox::critical(this, "Kesalahan", "Nama Direktori tidak ditemukan");
    dirNameEdit->setFocus();
    return;
  }

  QString dirName = dirNameEdit->text();

  if (directory->rmdir(dirName)) {
    QMessageBox::information(this, "Informasi", "Direktori \"" + dirName + "\" BERHASIL hilang");
  } else {
    QMessageBox::critical(this, "Kesalahan", "File GAGAL hilang");
  }
}
