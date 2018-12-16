#ifndef MAINFORM_H
#define MAINFORM_H

#include <QWidget>
#include <QFontComboBox>
#include <QLabel>

class MainForm: public QWidget {
  Q_OBJECT
private:
  QFontComboBox *fontCombo;
  QLabel *label;

private slots:
  void on_fontCombo_activated();

public:
  explicit MainForm(QWidget *parent);
  ~MainForm();
  void setupUI();
};

#endif
