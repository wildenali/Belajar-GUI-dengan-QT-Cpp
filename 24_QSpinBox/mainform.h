#ifndef MAINFORM_H
#define MAINFORM_H

#include <QWidget>
#include <QSpinBox>
#include <QFontComboBox>
#include <QLabel>

class MainForm: public QWidget {
  Q_OBJECT
private:
  QLabel *fontLabel;
  QFontComboBox *fontCombo;
  QLabel *sizeLabel;
  QSpinBox *sizeSpinBox;
  QLabel *sampleLabel;

private slots:
  void changeFont();

public:
  explicit MainForm(QWidget *parent);
  ~MainForm();
  void setupUI();
};

#endif
