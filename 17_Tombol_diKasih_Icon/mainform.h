#ifndef MAINFORM_H
#define MAINFORM_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>

class MainForm: public QWidget {
  Q_OBJECT
private:
  QLabel *label;
  QPushButton *button1;
  QPushButton *button2;
  QPushButton *button3;

public:
  explicit MainForm(QWidget *parent);
  ~MainForm();
  void setupUI();
};

#endif
