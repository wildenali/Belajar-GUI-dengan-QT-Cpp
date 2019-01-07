#include "dialogform.h"
#include <QHBoxLayout>
#include <QVBoxLayout>

DialogForm::DialogForm(QWidget *parent) : QDialog(parent) {
  this->setupUI();
}

DialogForm::~DialogForm() {
  delete label;
  delete okButton;
  delete cancelButton;
}

void DialogForm::setupUI() {
  this->resize(300, 100);
  this->move(600, 450);
  this->setWindowTitle("QDialog");

  label = new QLabel("Form Kedua (Dialog)");

  okButton = new QPushButton("OK");
  cancelButton = new QPushButton("Cancel");

  QHBoxLayout*hbox = new QHBoxLayout();
  hbox->addStretch();
  hbox->addWidget(okButton);
  hbox->addWidget(cancelButton);

  QVBoxLayout *layout = new QVBoxLayout();
  layout->addWidget(label);
  layout->addLayout(hbox);

  this->setLayout(layout);

  connect(okButton, SIGNAL(clicked()), this, SLOT(accept()));
  connect(cancelButton, SIGNAL(clicked()), this, SLOT(reject()));
}
