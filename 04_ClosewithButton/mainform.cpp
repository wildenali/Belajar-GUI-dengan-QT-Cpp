#include "mainform.h"

MainForm::MainForm(QWidget *parent) : QWidget(parent) {
  this -> setupUI();
}

MainForm::~MainForm() {
  delete button;
}

void MainForm::setupUI() {
  this -> resize(600,300);  // ukuran
  this -> move(100,200);    // posisi form terhadap layar komputer
  this -> setWindowTitle("Klik exim");

  button = new QPushButton("TuTut");
  button -> move(50, 50);
  button -> setParent(this);

  connect(button, SIGNAL(clicked()), this, SLOT(on_button_clicked()));
}

void MainForm::on_button_clicked() {
  this -> close();  // ketika di klik maka apps nge close
}
