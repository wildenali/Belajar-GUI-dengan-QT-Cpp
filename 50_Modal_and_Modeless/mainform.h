#ifndef MAINFORM_H
#define MAINFORM_H

#include "dialogform.h"
#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

class MainForm: public QWidget{
  Q_OBJECT
private:
  DialogForm *form;
  QLabel *label;
  QLineEdit *lineEdit;
  QPushButton *showModalDialogButton;
  QPushButton *showModelessDialogButton;

private slots:
  void on_showModalDialogButton_clicked();
  void on_showModelessDialogButton_clicked();

public:
  explicit MainForm(QWidget *parent);
  ~MainForm();
  void setupUI();
};

#endif
