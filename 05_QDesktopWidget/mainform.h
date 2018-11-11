#ifndef MAINFORM_H
#define MAINFORM_H

#include <QWidget>
#include <QPushButton>

class MainForm: public QWidget {
  Q_OBJECT

public:
  explicit MainForm(QWidget *parent);
  ~MainForm();
  void setupUI();
  void setCenter();
};

#endif
