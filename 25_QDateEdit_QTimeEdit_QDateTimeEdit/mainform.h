#ifndef MAINFORM_H
#define MAINFORM_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QDateEdit>
#include <QTimeEdit>
#include <QDateTimeEdit>

class MainForm: public QWidget {
  Q_OBJECT

private:
  QLabel *dateLabel;
  QDateEdit *dateEdit;
  QLabel *timeLabel;
  QTimeEdit *timeEdit;
  QLabel *dateTimeLabel;
  QDateTimeEdit *dateTimeEdit;
  QPushButton *okButton;

private slots:
  void on_okButton_clicked();

public:
  explicit MainForm(QWidget *parent);
  ~MainForm();
  void setupUI();
};

#endif
