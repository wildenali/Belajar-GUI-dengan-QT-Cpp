#ifndef MAINFORM_H
#define MAINFORM_H

#include <QWidget>
#include <QComboBox>
#include <QPushButton>

class MainForm: public QWidget {
  Q_OBJECT
private:
  QComboBox *combo;
  QPushButton *getTextButton;

private slots:
  void on_getTextButton_clicked();

public:
  explicit MainForm(QWidget *parent);
  ~MainForm();
  void setupUI();
};

#endif
