#include "mainform.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QFile>
#include <QMessageBox>

using namespace std;

MainForm::MainForm(QWidget *parent) : QWidget(parent) {
  this->setupUI();
}

MainForm::~MainForm() {
  delete label1;
  delete oldFileEdit;
  delete label2;
  delete newFileEdit;
  delete renameButton;
}

void MainForm::setupUI() {
  this->resize(400, 150);
  this->move(500, 250);
  this->setWindowTitle("QFile.rename()");

  label1 = new QLabel("Nama File LAMA");
  oldFileEdit = new QLineEdit();
  label2 = new QLabel("Nama File BARU");
  newFileEdit = new QLineEdit();

  renameButton = new QPushButton("Ganti namanya");

  QHBoxLayout *hbox = new QHBoxLayout();
  hbox->addStretch();
  hbox->addWidget(renameButton);

  QVBoxLayout *layout = new QVBoxLayout();
  layout->addWidget(label1);
  layout->addWidget(oldFileEdit);
  layout->addWidget(label2);
  layout->addWidget(newFileEdit);
  layout->addLayout(hbox);

  this->setLayout(layout);

  connect(renameButton, SIGNAL(clicked()), this, SLOT(on_renameButton_clicked()));
}

void MainForm::on_renameButton_clicked() {
  if (oldFileEdit->text().trimmed().size() == 0 || newFileEdit->text().trimmed().size() == 0) {
    QMessageBox::critical(this, "Kesalahan", "Nama file LAMA dan BARU harus di isi");
    return;
  }

  if (!QFile::exists(oldFileEdit->text())) {
    QMessageBox::critical(this, "Kesalahan", "File nya tidak ditemukan");
    return;
  }

  QString oldFile = oldFileEdit->text();
  QString newFile = newFileEdit->text();

  if (QFile::rename(oldFile, newFile)) {
    QMessageBox::information(this, "Informasi", "File \"" + oldFile + "\" telah BERUBAH menjadi \"" + newFile + "\"");
  } else {
    QMessageBox::critical(this, "Kesalahan", "File GAGAL berubah");
  }


}
