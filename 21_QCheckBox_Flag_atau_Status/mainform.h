#ifndef MAINFORM_H
#define MAINFORM_H

#include <QWidget>
#include <QLineEdit>
#include <QLabel>
#include <QCheckBox>


class MainForm: public QWidget {
  Q_OBJECT
private:
  QLabel *label;
  QLineEdit *lineEdit;
  QCheckBox *fullPathCheck;
  QString fileName;

private slots:
  void on_fullPathCheck_clicked();

public:
  explicit MainForm(QWidget *parent);
  ~MainForm();
  void setupUI();
};

#endif
