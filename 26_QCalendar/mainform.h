#ifndef MAINFORM_H
#define MAINFORM_H


#include <QWidget>
#include <QCalendarWidget>
#include <QCheckBox>
#include <QDateEdit>
#include <QPushButton>

class MainForm: public QWidget {
  Q_OBJECT

private:
  QCalendarWidget *calendar;
  QCheckBox *shortNamesCheck;
  QDateEdit *dateEdit;
  QPushButton *setButton;
  QPushButton *getButton;

private slots:
void on_shortNamesCheck_clicked();
void on_setButton_clicked();
void on_getButton_clicked();

public:
  explicit MainForm(QWidget *parent);
  ~MainForm ();
  void setupUI();
};

#endif
