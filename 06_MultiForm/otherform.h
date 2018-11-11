#ifndef OTHERFORM_H
#define OTHERFORM_H

#include <QWidget>
#include <QPushButton>

class OtherForm: public QWidget {
  Q_OBJECT

public:
  OtherForm();
  ~OtherForm();
  void setupUI();

private slots:
  void on_closeButton_clicked();

private:
  QPushButton *closeButton;
};

#endif
