#include "mainform.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QFile>
#include <QTextStream>
#include <QIODevice>
#include <QMessageBox>

using namespace std;

MainForm::MainForm(QWidget *parent) : QWidget(parent) {
  this->setupUI();
}

MainForm::~MainForm() {
  delete label1;
  delete label2;
  delete label3;
  delete fileEdit;
  delete inputTextEdit;
  delete outputTextEdit;
  delete writeButton;
  delete readButton;
}

void MainForm::setupUI() {
  this->resize(500, 300);
  this->move(450, 200);
  this->setWindowTitle("Demo Akses File dengan QFile");

  label1 = new QLabel("Nama File");
  fileEdit = new QLineEdit();
  label2 = new QLabel("Data yang akan ditulis");
  inputTextEdit = new QTextEdit();
  label3 = new QLabel("Data yang akan dibaca");
  outputTextEdit = new QTextEdit();
  outputTextEdit->setReadOnly(true);

  writeButton = new QPushButton("Tulis Data");
  readButton = new QPushButton("Baca Data");
  readButton->setDisabled(true);

  QHBoxLayout *hbox = new QHBoxLayout();
  hbox->addStretch();
  hbox->addWidget(writeButton);
  hbox->addWidget(readButton);

  QVBoxLayout *layout = new QVBoxLayout();
  layout->addWidget(label1);
  layout->addWidget(fileEdit);
  layout->addWidget(label2);
  layout->addWidget(inputTextEdit);
  layout->addWidget(label3);
  layout->addWidget(outputTextEdit);
  layout->addLayout(hbox);

  this->setLayout(layout);

  connect(writeButton, SIGNAL(clicked()), this, SLOT(on_writeButton_clicked()));
  connect(readButton, SIGNAL(clicked()), this, SLOT(on_readButton_clicked()));
}

void MainForm::on_writeButton_clicked() {
  if (fileEdit->text().trimmed().size() == 0) {
    QMessageBox::critical(this, "Kesalahan", "Nama File harus diisi.");
    return;
  }
  if (inputTextEdit->document()->isEmpty()) {
    QMessageBox::critical(this, "Kesalahan", "Data yang akan ditulis harus diisi.");
    return;
  }

  QFile f(fileEdit->text());
  if (!f.open(QIODevice::WriteOnly | QIODevice::Text)) return;
  QTextStream outputStream(&f);
  outputStream << inputTextEdit->document()->toPlainText();
  f.close();

  fileEdit->setDisabled(true);
  inputTextEdit->setDisabled(true);
  writeButton->setDisabled(true);
  readButton->setDisabled(false);
}

void MainForm::on_readButton_clicked() {
  QFile f(fileEdit->text());
  if (!f.open(QIODevice::ReadOnly | QIODevice::Text)) return;
  QString s(f.readAll());
  outputTextEdit->document()->setPlainText(s);  // Menempelkan data ke kontrol outputTextEdit
  f.close();    // Menutup file
}
