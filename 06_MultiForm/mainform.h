#ifndef MAINFORM_H
#define MAINFORM_H

#include <QWidget>
#include <QPushButton>
#include "otherform.h"

class MainForm: public QWidget {
  Q_OBJECT

public:
  explicit MainForm(QWidget *parent);
  ~MainForm();
  void setupUI();

private slots:
  void on_showButton_clicked();

private:
  QPushButton *showButton;
  OtherForm *otherForm;
};

#endif
