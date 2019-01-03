#ifndef MAINFORM_H
#define MAINFORM_H

#include <QWidget>
#include <QSlider>
#include <QLCDNumber>

class MainForm: public QWidget {
  Q_OBJECT

private:
  QSlider *slider;
  QLCDNumber *lcd;

private slots:
  void on_slider_sliderMoved();

public:
  explicit MainForm(QWidget *parent);
  ~MainForm();
  void setupUI();
};

#endif
