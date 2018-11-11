#include "MinimalForm.h"

MinimalForm::MinimalForm(QWidget *parent) : QWidget(parent) {
  this -> setupUi();
}

MinimalForm::~MinimalForm() {
  delete label;
}

void MinimalForm::setupUi() {
  this -> resize(200, 300);
  this -> move(300,300);
  this -> setWindowTitle("Percobaan GUI");

  label = new QLabel("Hay QyuTi");
  label -> move(55,40);
  label -> setParent(this);
}
