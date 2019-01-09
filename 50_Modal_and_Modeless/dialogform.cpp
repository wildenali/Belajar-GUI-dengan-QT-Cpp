#include "dialogform.h"
#include <QHBoxLayout>
#include <QVBoxLayout>

DialogForm::DialogForm(QWidget *parent) : QDialog(parent) {
  this->setupUI();
}

DialogForm::~DialogForm() {
  delete label;
  delete closeButton;
}

void DialogForm::setupUI() {
  this->resize(300, 100);
  this->move(400, 250);
  this->setWindowTitle("Dialog");

  label = new QLabel();

  closeButton = new QPushButton("Tutup");

  QHBoxLayout *hbox = new QHBoxLayout();
  hbox->addStretch();
  hbox->addWidget(closeButton);

  QVBoxLayout *layout = new QVBoxLayout();
  layout->addWidget(label);
  layout->addLayout(hbox);

  this->setLayout(layout);

  connect(closeButton, SIGNAL(clicked()), this, SLOT(close()));
}

void DialogForm::setLabelText(QString text) {
  label->setText(text);
}
