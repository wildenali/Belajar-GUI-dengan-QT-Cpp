#ifndef MAINFORM_H
#define MAINFORM_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QFrame>

class MainForm: public QWidget {
  Q_OBJECT
private:
  QLabel *label1;
  QLineEdit *numberEdit1;
  QLabel *label2;
  QLineEdit *numberEdit2;
  QLabel *label3;
  QLineEdit *resultEdit;
  QPushButton *addButton;
  QPushButton *substactButton;
  QPushButton *mulButton;
  QPushButton *divButton;
  QFrame *verticalLine;

private slots:
  void on_addButton_clicked();
  void on_substractButton_clicked();
  void on_mulButton_clicked();
  void on_divButton_clicked();


public:
  explicit MainForm(QWidget *parent);
  ~MainForm();
  void setupUI();
  void calculate(char op);
};

#endif
