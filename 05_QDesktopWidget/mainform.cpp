#include "mainform.h"
#include <QDesktopWidget>

MainForm::MainForm(QWidget *parent): QWidget(parent) {
  this -> setupUI();
}

MainForm::~MainForm() {

}

void MainForm::setupUI() {
  this -> resize(700, 200);
  this -> setCenter();
  this -> setWindowTitle("Form di TENGAH layar");
}

void MainForm::setCenter() {
  QDesktopWidget *desktop= new QDesktopWidget();

  int screenwidth = desktop -> screen() -> width();
  int screenheight = desktop -> screen() -> height();

  this -> setGeometry(
                    (screenwidth - this -> width()) / 2,
                    (screenheight - this -> height()) / 2,
                    this -> width(),
                    this -> height());
  delete desktop;
}
