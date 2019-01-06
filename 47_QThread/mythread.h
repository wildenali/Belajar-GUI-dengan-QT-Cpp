#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QThread>
#include <QListWidget>

class MyThread: public QThread {
private:
  QString name;

protected:
  void run();

public:
  QListWidget *listWidget;
  MyThread();
  ~MyThread();
  void setName(QString name);
};

#endif
