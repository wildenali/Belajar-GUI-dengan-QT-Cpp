#include "mainform.h"
#include <QVBoxLayout>
#include <QHBoxLayout>

MainForm::MainForm(QWidget *parent) : QWidget(parent) {
  // membuat object dari kelas DialogForm
  form = new DialogForm(this);

  this->setupUI();
}


MainForm::~MainForm() {
  delete form;
  delete label;
  delete lineEdit;
  delete showModalDialogButton;
  delete showModelessDialogButton;
}

void MainForm::setupUI() {
  this->resize(350, 100);
  this->move(500, 300);
  this->setWindowTitle("Model dan Modeless");

  label = new QLabel();
  label->setText(tr("Tuliskan teks pada kotak ") + tr("di bawah ketika dialog di tampilkan"));

  lineEdit = new QLineEdit();
  showModalDialogButton = new QPushButton("Modal");
  showModelessDialogButton = new QPushButton("Modeless");

  QHBoxLayout *hbox = new QHBoxLayout();
  hbox->addWidget(showModalDialogButton);
  hbox->addWidget(showModelessDialogButton);

  QVBoxLayout *layout = new QVBoxLayout();
  layout->addWidget(label);
  layout->addWidget(lineEdit);
  layout->addLayout(hbox);

  this->setLayout(layout);

  connect(showModalDialogButton, SIGNAL(clicked()), this, SLOT(on_showModalDialogButton_clicked()));
  connect(showModelessDialogButton, SIGNAL(clicked()), this, SLOT(on_showModelessDialogButton_clicked()));
}

void MainForm::on_showModalDialogButton_clicked() {
  form->setLabelText("Dialog ini bersifat MODAL");
  form->setModal(true);
  form->show();
}

void MainForm::on_showModelessDialogButton_clicked() {
  form->setLabelText("Dialog ini bersifat MODELESS");
  form->setModal(false);
  form->show();
}
