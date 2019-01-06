#ifndef MAINFORM_H
#define MAINFORM_H

#include <QWidget>
#include <QLabel>
#include <QTimer>

class MainForm: public QWidget {
  Q_OBJECT
private:
  QLabel *label1;
  QLabel *label2;
  QTimer *timer;

private slots:
  void on_timer_timeout();

public:
  explicit MainForm(QWidget *parent);
  ~MainForm();
  void setupUI();
};

#endif
