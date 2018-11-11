#include "otherform.h"

OtherForm::OtherForm() {
  this->setupUI();
}

OtherForm::~OtherForm() {
  delete closeButton;
}

void OtherForm::setupUI() {
  this->resize(300, 200);
  this->move(320, 250);
  this->setWindowTitle("ini Form Lainnya");

  closeButton = new QPushButton("Tutut");
  closeButton->move(50,50);
  closeButton->setParent(this);

  connect(closeButton, SIGNAL(clicked()), this, SLOT(on_closeButton_clicked()));
}

void OtherForm::on_closeButton_clicked() {
  this->close();
}
