#ifndef MAINFORM_H
#define MAINFORM_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QTextEdit>
#include <QPushButton>

class MainForm: public QWidget {
  Q_OBJECT
private:
  QLabel *label1;
  QLineEdit *fileEdit;
  QLabel *label2;
  QTextEdit *inputTextEdit;
  QLabel *label3;
  QTextEdit *outputTextEdit;
  QPushButton *writeButton;
  QPushButton *readButton;

private slots:
  void on_writeButton_clicked();
  void on_readButton_clicked();

public:
  explicit MainForm(QWidget *parent);
  ~MainForm();
  void setupUI();
};

#endif
