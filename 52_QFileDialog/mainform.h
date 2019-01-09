#ifndef MAINFORM_H
#define MAINFORM_H

#include <QWidget>
#include <QTextEdit>
#include <QPushButton>
#include <QLabel>

class MainForm: public QWidget{
  Q_OBJECT
private:
  QTextEdit *textEdit;
  QPushButton *openButton;
  QLabel *fileLabel;

private slots:
  void on_openButton_clicked();

public:
  explicit MainForm(QWidget *parent);
  ~MainForm();
  void setupUI();
};

#endif
