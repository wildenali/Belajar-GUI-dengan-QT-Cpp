#ifndef MAINFORM_H
#define MAINFORM_H

#include <QWidget>
#include <QTextEdit>
#include <QPushButton>

class MainForm: public QWidget{
  Q_OBJECT
private:
  QTextEdit *textEdit;
  QPushButton *fontButton;

private slots:
  void on_fontButton_clicked();

public:
  explicit MainForm(QWidget *parent);
  ~MainForm();
  void setupUI();
};

#endif
