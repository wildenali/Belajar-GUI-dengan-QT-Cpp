#ifndef MINIMALFORM_H
#define MINIMALFORM_H

#include <QWidget>
#include <QLabel>

class MinimalForm: public QWidget {
  Q_OBJECT

public:
  explicit MinimalForm(QWidget *parent);
  ~MinimalForm();
  void setupUi();

private:
  QLabel *label;
};

#endif      // MINIMALFORM_H
