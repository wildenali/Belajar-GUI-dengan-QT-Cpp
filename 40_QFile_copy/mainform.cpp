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
  delete sourceFileEdit;
  delete label2;
  delete destFileEdit;
  delete copyButton;
}

void MainForm::setupUI() {
  this->resize(400, 150);
  this->move(500, 250);
  this->setWindowTitle("QFile.copy()");

  label1 = new QLabel("Nama File Sumber");
  sourceFileEdit = new QLineEdit();
  label2 = new QLabel("Nama File Tujuan");
  destFileEdit = new QLineEdit();

  copyButton = new QPushButton("Kopi aja");

  QHBoxLayout *hbox = new QHBoxLayout();
  hbox->addStretch();
  hbox->addWidget(copyButton);

  QVBoxLayout *layout = new QVBoxLayout();
  layout->addWidget(label1);
  layout->addWidget(sourceFileEdit);
  layout->addWidget(label2);
  layout->addWidget(destFileEdit);
  layout->addLayout(hbox);

  this->setLayout(layout);

  connect(copyButton, SIGNAL(clicked()), this, SLOT(on_copyButton_clicked()));
}

void MainForm::on_copyButton_clicked() {
  if (sourceFileEdit->text().trimmed().size() == 0 || destFileEdit->text().trimmed().size() == 0) {
    QMessageBox::critical(this, "Kesalahan", "Nama file sumber dan tujuan harus di isi");
    return;
  }

  if (!QFile::exists(sourceFileEdit->text())) {
    QMessageBox::critical(this, "Kesalahan", "File sumber tidak ditemukan");
    return;
  }

  QString sourceFile = sourceFileEdit->text();
  QString destFile = destFileEdit->text();

  if (QFile::copy(sourceFile, destFile)) {
    QMessageBox::information(this, "Informasi", "File BERHASIL disalin");
  } else {
    QMessageBox::critical(this, "Kesalahan", "File GAGAL disalin");
  }


}
