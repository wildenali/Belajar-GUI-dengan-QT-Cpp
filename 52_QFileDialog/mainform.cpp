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
  delete openButton;
  delete fileLabel;
}

void MainForm::setupUI() {
  this->resize(500, 450);
  this->move(450, 150);
  this->setWindowTitle("File Dialog");

  textEdit = new QTextEdit();
  openButton = new QPushButton("Buka");

  QHBoxLayout *hbox = new QHBoxLayout();
  hbox->addWidget(openButton);
  hbox->addStretch();

  fileLabel = new QLabel("Nama File");

  QVBoxLayout *layout = new QVBoxLayout();
  layout->addWidget(textEdit);
  layout->addLayout(hbox);
  layout->addWidget(fileLabel);

  this->setLayout(layout);

  connect(openButton, SIGNAL(clicked()), this, SLOT(on_openButton_clicked()));
}

void MainForm::on_openButton_clicked() {
  QString fileName;
  fileName = QFileDialog::getOpenFileName(this, tr("Pilih File"), tr("/home/password-sari/Documents/"), tr("C++ Code (*.cpp);; C++ Header (*.h)"));
  if (fileName.trimmed().size() == 0) return;
  fileLabel->setText(fileName);
  QFile fileHandle(fileName);
  if (!fileHandle.open(QIODevice::ReadOnly)) return;
  QTextStream stream(&fileHandle);
  textEdit->setPlainText(stream.readAll());
  fileHandle.close();
}
