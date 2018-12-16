#ifndef MAINFORM_H
#define MAINFORM_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QTextEdit>
#include <QFrame>
#include <QPushButton>

class MainForm: public QWidget {
  Q_OBJECT
private:
  QLabel *label1;
  QLineEdit *nameLineEdit;
  QLabel *label2;
  QTextEdit *commentTextEdit;
  QFrame *horizontalLine;
  QPushButton *getTextButton;
  QPushButton *exitButton;

private slots:
  void on_getTextButton_clicked();

public:
  explicit MainForm(QWidget *parent);
  ~MainForm();
  void setupUI();
};

#endif
