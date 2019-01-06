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
  QLineEdit *fileEdit;
  QPushButton *removeButton;

private slots:
  void on_removeButton_clicked();

public:
  explicit MainForm(QWidget *parent);
  ~MainForm();
  void setupUI();
};

#endif
