#ifndef MAINFORM_H
#define MAINFORM_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>

class MainForm: public QWidget {
  Q_OBJECT

private:
  QLineEdit *lineEdit;
  QPushButton *button1;
  QPushButton *button2;

public:
  explicit MainForm(QWidget *parent);
  ~MainForm();
  void setupUI();
};

#endif      // MAINFORM_H
