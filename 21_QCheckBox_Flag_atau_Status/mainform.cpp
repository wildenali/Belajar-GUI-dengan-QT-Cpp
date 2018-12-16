#include "mainform.h"
#include <QVBoxLayout>
#include <QFileInfo>

MainForm::MainForm(QWidget *parent) : QWidget(parent) {
  this->setupUI();
}

MainForm::~MainForm() {
  delete label;
  delete lineEdit;
  delete fullPathCheck;
}

void MainForm::setupUI() {
  this->resize(1200,100);
  this->move(100,200);
  this->setWindowTitle("QCheckBox path");

  label = new QLabel();
  label->setText("Nama File: ");

  fileName = "/home/password-sari/Documents/wildenali github/Belajar-GUI-dengan-QT-Cpp/21_QCheckBox_Flag_atau_Status/mainform.cpp";

  lineEdit = new QLineEdit(fileName);
  fullPathCheck = new QCheckBox();
  fullPathCheck->setText("Nama dile disertai dengan path lengkap");
  fullPathCheck->setChecked(true);

  QVBoxLayout *layout = new QVBoxLayout();
  layout->addWidget(label);
  layout->addWidget(lineEdit);
  layout->addWidget(fullPathCheck);
  layout->addStretch();

  this->setLayout(layout);

  connect(fullPathCheck, SIGNAL(clicked()), this, SLOT(on_fullPathCheck_clicked()));
}

void MainForm::on_fullPathCheck_clicked() {
  QFileInfo fi;
  fi.setFile(fileName);
  if (fullPathCheck->isChecked()) {
    lineEdit->setText(fi.filePath());
  } else {
    lineEdit->setText(fi.fileName());
  }
}
