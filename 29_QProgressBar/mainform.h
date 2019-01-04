#ifndef MAINFORM_H
#define MAINFORM_H

#include <QWidget>
#include <QLabel>
#include <QListWidget>
#include <QProgressBar>
#include <QPushButton>

class MainForm: public QWidget {
  Q_OBJECT
private:
  QLabel *label1;
  QListWidget *list1;
  QLabel *label2;
  QListWidget *list2;
  QProgressBar *progress;
  QPushButton *startButton;

private slots:
  void on_startButton_clicked();

public:
  explicit MainForm(QWidget *parent);
  ~MainForm();
  void setupUI();
};

#endif
