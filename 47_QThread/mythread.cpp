#include "mythread.h"

MyThread::MyThread() {
  // Kosong
}

MyThread::~MyThread() {
  // Kosong
}

void MyThread::setName(QString name) {
  this->name = name;
}

void MyThread::run() {
  for (int i = 1; i < 100000; i++) {
    listWidget->addItem(name + " : " + QString::number(i));
  }
}
