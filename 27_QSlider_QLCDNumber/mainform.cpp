#include "mainform.h"
#include <QVBoxLayout>

MainForm::MainForm(QWidget *parent) : QWidget(parent) {
  this->setupUI();
}

MainForm::~MainForm() {
  delete slider;
  delete lcd;
}

void MainForm::setupUI() {
  this->resize(400, 100);
  this->move(400, 250);
  this->setWindowTitle("Demo QSlider dan QLCDNumber");

  slider = new QSlider(Qt::Horizontal);
  slider->setMinimum(-1);
  slider->setMaximum(100);
  slider->setValue(54);

  lcd = new QLCDNumber();
  lcd->setDigitCount(3);
  lcd->display(54);

  QVBoxLayout *layout = new QVBoxLayout();
  layout->addWidget(slider);
  layout->addWidget(lcd);

  this->setLayout(layout);

  connect(slider, SIGNAL(sliderMoved(int)), this, SLOT(on_slider_sliderMoved()));
}

void MainForm::on_slider_sliderMoved() {
  lcd->display(slider->value());
}
