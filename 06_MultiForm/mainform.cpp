#include "mainform.h"
MainForm::MainForm(QWidget *parent) : QWidget(parent) {
  this->setupUI();
  otherForm = new OtherForm();
}

MainForm::~MainForm() {
  delete showButton;
  delete otherForm;
}

void MainForm::setupUI() {
  this->resize(300, 200);
  this->move(200, 200);
  this->setWindowTitle("Testing MultiForm");

  showButton = new QPushButton("Tampilkan Form Lainnya");
  showButton->move(50 ,50);
  showButton->setParent(this);

  connect(showButton, SIGNAL(clicked()), this, SLOT(on_showButton_clicked()));
}

void MainForm::on_showButton_clicked() {
  otherForm->show();  // untuk menampilkan form yg lainnya
}
