#ifndef MAINFORM_H
#define MAINFORM_H

#include <QWidget>
#include <QPushButton>

class MainForm: public QWidget {
  Q_OBJECT

private:
  QPushButton *button1;
  QPushButton *button2;
  QPushButton *button3;
  QPushButton *button4;

public:
  explicit MainForm(QWidget *parent);
  ~MainForm();
  void setupUI();
};

#endif    // MAINFORM_H
