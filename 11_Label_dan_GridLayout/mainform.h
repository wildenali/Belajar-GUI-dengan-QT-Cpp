#ifndef MAINFORM_H
#define MAINFORM_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

class MainForm: public QWidget {
  Q_OBJECT

private:
  QPushButton *button1;
  QLabel *label1;
  QLineEdit *lineEdit1;
  QLabel *label2;
  QLineEdit *lineEdit2;

public:
  explicit MainForm(QWidget *parent);
  ~MainForm();
  void setupUI();
};

#endif      // MAINFORM_H
