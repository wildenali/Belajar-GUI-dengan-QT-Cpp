#include "entryform.h"

EntryForm::EntryForm() {
  this->setupUI();
}

EntryForm::~EntryForm() {
  delete label1;
  delete nameLineEdit;
  delete label2;
  delete phoneLineEdit;
  delete okButton;
  delete cancelButton;
}

void EntryForm::setupUI() {
  this->resize(300, 100);
  this->move(320, 280);
  this->setWindowTitle("Tambah/Ubah Kontak");

  okButton = new QPushButton("OK");
  cancelButton = new QPushButton("Batal");

  QHBoxLayout *hbox = new QHBoxLayout();
  hbox->addWidget(okButton);
  hbox->addWidget(cancelButton);

  label1 = new QLabel("Nama Lengkap:");
  nameLineEdit = new QLineEdit();
  label2 = new QLabel("Nomor HP:");
  phoneLineEdit = new QLineEdit();

  QGridLayout *layout = new QGridLayout();
  layout->addWidget(label1, 0, 0);
  layout->addWidget(nameLineEdit, 0, 1);
  layout->addWidget(label2, 1, 0);
  layout->addWidget(phoneLineEdit, 1, 1);
  layout->addLayout(hbox, 2, 1);

  this->setLayout(layout);

  connect(okButton, SIGNAL(clicked()), this, SLOT(accept()));
  connect(cancelButton, SIGNAL(clicked()), this, SLOT(reject()));
}

void EntryForm::setName(QString name) {
  nameLineEdit->setText(name);
}

QString EntryForm::getName() {
  return nameLineEdit->text();
}

void EntryForm::setPhoneNumber(QString phoneNumber) {
  phoneLineEdit->setText(phoneNumber);
}

QString EntryForm::getPhoneNumber() {
  return phoneLineEdit->text();
}
