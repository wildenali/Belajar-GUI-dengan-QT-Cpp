#ifndef MAINFORM_H
#define MAINFORM_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>

class MainForm: public QWidget{
  Q_OBJECT
private:
  QLabel *label;
  QPushButton *showDialogButton;

private slots:
  void on_showDialogButton_clicked();

public:
  explicit MainForm(QWidget *parent);
  ~MainForm();
  void setupUI();
};

#endif
