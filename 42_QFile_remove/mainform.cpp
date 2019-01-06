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
  delete fileEdit;
  delete removeButton;
}

void MainForm::setupUI() {
  this->resize(400, 150);
  this->move(500, 250);
  this->setWindowTitle("QFile.remove()");

  label1 = new QLabel("Nama File yang akan dihapus");
  fileEdit = new QLineEdit();

  removeButton = new QPushButton("Hapus filenya");

  QHBoxLayout *hbox = new QHBoxLayout();
  hbox->addStretch();
  hbox->addWidget(removeButton);

  QVBoxLayout *layout = new QVBoxLayout();
  layout->addWidget(label1);
  layout->addWidget(fileEdit);
  layout->addLayout(hbox);

  this->setLayout(layout);

  connect(removeButton, SIGNAL(clicked()), this, SLOT(on_removeButton_clicked()));
}

void MainForm::on_removeButton_clicked() {
  if (fileEdit->text().trimmed().size() == 0) {
    QMessageBox::critical(this, "Kesalahan", "Nama file harus di isi");
    return;
  }

  if (!QFile::exists(fileEdit->text())) {
    QMessageBox::critical(this, "Kesalahan", "File nya tidak ditemukan");
    return;
  }

  QString fileName = fileEdit->text();

  if (QFile::remove(fileName)) {
    QMessageBox::information(this, "Informasi", "File \"" + fileName + "\" telah HILANG");
  } else {
    QMessageBox::critical(this, "Kesalahan", "File GAGAL menghilang");
  }


}
