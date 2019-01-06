#ifndef MAINFORM_H
#define MAINFORM_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

class MainForm: public QWidget {
  Q_OBJECT
private:
  QLabel *label1;
  QLineEdit *oldFileEdit;
  QLabel *label2;
  QLineEdit *newFileEdit;
  QPushButton *renameButton;

private slots:
  void on_renameButton_clicked();

public:
  explicit MainForm(QWidget *parent);
  ~MainForm();
  void setupUI();
};

#endif
