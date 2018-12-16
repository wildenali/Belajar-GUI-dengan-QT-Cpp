#ifndef MAINFORM_H
#define MAINFORM_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QRadioButton>
#include <QPushButton>

class MainForm: public QWidget {
  Q_OBJECT
private:
  QLabel *label1;
  QLineEdit *numberEdit1;
  QLabel *label2;
  QLineEdit *numberEdit2;
  QRadioButton *addRadio;
  QRadioButton *substractRadio;
  QRadioButton *mulRadio;
  QRadioButton *divRadio;
  QLabel *resultLabel;
  QPushButton *calculateButton;
  void setResultLabel(const QString& text);

private slots:
  void on_addRadio_clicked();
  void on_substractRadio_clicked();
  void on_mulRadio_clicked();
  void on_divRadio_clicked();
  void on_calculateButton_clicked();

public:
  explicit MainForm(QWidget *parent);
  ~MainForm();
  void setupUI();
};

#endif
