#include "mainform.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QApplication>

using namespace std;

MainForm::MainForm(QWidget *parent) : QWidget(parent) {
  this->setupUI();

  thread1 = new MyThread();
  thread1->setName(tr("Thread 1"));
  thread1->listWidget = listWidget1;

  thread2 = new MyThread();
  thread2->setName(tr("Thread 2"));
  thread2->listWidget = listWidget2;
}

MainForm::~MainForm() {
  delete label1;
  delete listWidget1;
  delete label2;
  delete listWidget2;
  delete startButton;
  delete thread1;
  delete thread2;
}

void MainForm::setupUI() {
  this->resize(300, 300);
  this->move(500, 200);
  this->setWindowTitle("QThread");

  label1 = new QLabel("Thread 1");
  listWidget1 = new QListWidget();
  label2 = new QLabel("Thread 2");
  listWidget2 = new QListWidget();
  startButton = new QPushButton("Mulai");

  QHBoxLayout *hbox = new QHBoxLayout();
  hbox->addStretch();
  hbox->addWidget(startButton);

  QVBoxLayout *layout = new QVBoxLayout();
  layout->addWidget(label1);
  layout->addWidget(listWidget1);
  layout->addWidget(label2);
  layout->addWidget(listWidget2);
  layout->addLayout(hbox);

  this->setLayout(layout);

  connect(startButton, SIGNAL(clicked()), this, SLOT(on_startButton_clicked()));
}

void MainForm::on_startButton_clicked() {
  thread1->start();
  thread2->start();
  QApplication::processEvents();
}
