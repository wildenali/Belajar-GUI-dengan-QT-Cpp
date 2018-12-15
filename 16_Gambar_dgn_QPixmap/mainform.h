#ifndef MAINFORM_H
#define MAINFORM_H

#include <QWidget>
#include <QLabel>

class MainForm: public QWidget {
  Q_OBJECT
private:
  QLabel *label1;
  QLabel *label2;

public:
  explicit MainForm(QWidget *parent);
  ~MainForm();
  void setupUI();
};

#endif
