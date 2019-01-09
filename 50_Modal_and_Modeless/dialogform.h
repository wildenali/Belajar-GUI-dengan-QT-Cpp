#ifndef DIALOGFORM_H
#define DIALOGFORM_H

#include <QWidget>
#include <QDialog>
#include <QLabel>
#include <QPushButton>

class DialogForm: public QDialog{
  Q_OBJECT
private:
  QLabel *label;
  QPushButton *closeButton;

public:
  explicit DialogForm(QWidget  *parent);
  ~DialogForm();
  void setupUI();
  void setLabelText(QString text);
};

#endif
