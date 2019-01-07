#include "dialogform.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>

DialogForm::DialogForm(QWidget *parent) : QDialog(parent) {
  this->setupUI();
}

DialogForm::~DialogForm() {
  delete label1;
  delete okButton;
  delete cancelButton;
  delete languageEdit;
  delete label2;
  delete nameEdit;
}

void DialogForm::setupUI() {
  this->resize(300, 100);
  this->move(650, 250);
  this->setWindowTitle("Tambah Data");

  label1 = new QLabel("Bahasa Pemrograman");
  languageEdit = new QLineEdit();
  label2 = new QLabel("Nama Pencipta");
  nameEdit = new QLineEdit();

  QGridLayout *grid = new QGridLayout();
  grid->addWidget(label1, 0, 0);
  grid->addWidget(languageEdit, 0, 1);
  grid->addWidget(label2, 1, 0);
  grid->addWidget(nameEdit, 1, 1);

  okButton = new QPushButton("OK");
  cancelButton = new QPushButton("Cancel");

  QHBoxLayout*hbox = new QHBoxLayout();
  hbox->addStretch();
  hbox->addWidget(okButton);
  hbox->addWidget(cancelButton);

  QVBoxLayout *layout = new QVBoxLayout();
  layout->addLayout(grid);
  layout->addLayout(hbox);

  this->setLayout(layout);

  connect(okButton, SIGNAL(clicked()), this, SLOT(accept()));
  connect(cancelButton, SIGNAL(clicked()), this, SLOT(reject()));
}

QString DialogForm::getLanguage() {
  return languageEdit->text();
}

QString DialogForm::getName() {
  return nameEdit->text();
}
