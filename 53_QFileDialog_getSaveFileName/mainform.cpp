#include "mainform.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QIODevice>

MainForm::MainForm(QWidget *parent) : QWidget(parent) {
  this->setupUI();
}

MainForm::~MainForm() {
  delete textEdit;
  delete saveButton;
  delete fileLabel;
}

void MainForm::setupUI() {
  this->resize(500, 450);
  this->move(450, 150);
  this->setWindowTitle("Cara Save File");

  textEdit = new QTextEdit();
  saveButton = new QPushButton("Simpan");

  QHBoxLayout *hbox = new QHBoxLayout();
  hbox->addWidget(saveButton);
  hbox->addStretch();

  fileLabel = new QLabel("Nama File");

  QVBoxLayout *layout = new QVBoxLayout();
  layout->addWidget(textEdit);
  layout->addLayout(hbox);
  layout->addWidget(fileLabel);

  this->setLayout(layout);

  connect(saveButton, SIGNAL(clicked()), this, SLOT(on_saveButton_clicked()));
}

void MainForm::on_saveButton_clicked() {
  QString fileName;
  fileName = QFileDialog::getSaveFileName(this, tr("Pilih File"), tr("/home/password-sari/Documents/"), tr("C++ Code (*.cpp);; C++ Header (*.h)"));
  if (fileName.trimmed().size() == 0) return;
  fileLabel->setText(fileName);
  QFile fileHandle(fileName);
  if (!fileHandle.open(QIODevice::WriteOnly)) return;
  QTextStream stream(&fileHandle);
  stream << textEdit->document()->toPlainText();
  stream.flush();
  fileHandle.close();
}
