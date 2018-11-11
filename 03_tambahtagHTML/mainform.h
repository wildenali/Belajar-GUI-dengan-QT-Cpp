#ifndef MAINFORM_H
#define MAINFORM_H

#include <QWidget>
#include <QLabel>

class MainForm: public QWidget {
  Q_OBJECT

public:
  explicit MainForm(QWidget *parent);
  ~MainForm();
  void setupUi();

private:
  QLabel *label1;
  QLabel *label2;
};

#endif
