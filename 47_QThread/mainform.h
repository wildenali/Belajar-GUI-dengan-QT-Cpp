#ifndef MAINFORM_H
#define MAINFORM_H

#include "mythread.h"
#include <QWidget>
#include <QLabel>
#include <QListWidget>
#include <QPushButton>

class MainForm: public QWidget {
  Q_OBJECT
private:
  MyThread *thread1;
  MyThread *thread2;
  QLabel *label1;
  QListWidget *listWidget1;
  QLabel *label2;
  QListWidget *listWidget2;
  QPushButton *startButton;

private slots:
  void on_startButton_clicked();

public:
  explicit MainForm(QWidget *parent);
  ~MainForm();
  void setupUI();
};

#endif
