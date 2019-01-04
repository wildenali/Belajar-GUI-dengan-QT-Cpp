#include "mainform.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QApplication>

MainForm::MainForm(QWidget *parent) : QWidget(parent) {
  this->setupUI();
}

MainForm::~MainForm() {
  delete label1;
  delete list1;
  delete label2;
  delete list2;
  delete progress;
  delete startButton;
}

void MainForm::setupUI() {
  this->resize(400, 400);
  this->move(500, 150);
  this->setWindowTitle("QProgressBar");

  label1 = new QLabel("Bilangan Ganjil");
  list1 = new QListWidget();
  QVBoxLayout *vbox1 = new QVBoxLayout();
  vbox1->addWidget(label1);
  vbox1->addWidget(list1);

  label2 = new QLabel("Bilangan Genap");
  list2 = new QListWidget();
  QVBoxLayout *vbox2 = new QVBoxLayout();
  vbox2->addWidget(label2);
  vbox2->addWidget(list2);

  QHBoxLayout *hbox = new QHBoxLayout();
  hbox->addLayout(vbox1);
  hbox->addLayout(vbox2);

  progress = new QProgressBar();
  progress->setMinimum(0);
  progress->setMaximum(10000);
  progress->setValue(0);

  startButton = new QPushButton("Mulai.....");

  QVBoxLayout *layout = new QVBoxLayout();
  layout->addLayout(hbox);
  layout->addWidget(progress);
  layout->addWidget(startButton);

  this->setLayout(layout);

  connect(startButton, SIGNAL(clicked()), this, SLOT(on_startButton_clicked()));
}

void MainForm::on_startButton_clicked() {
  progress->setValue(0);
  for (int i = 0; i < 10000; i++) {
    QApplication::processEvents();
    QString s;
    s.setNum(i);
    if (i % 2 == 1) {
      list1->addItem(s);
    } else {
      list2->addItem(s);
    }
    progress->setValue(progress->value()+1);
  }
}
