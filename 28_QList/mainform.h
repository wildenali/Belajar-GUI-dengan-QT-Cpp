#ifndef MAINFORM_H
#define MAINFORM_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QListWidget>

class MainForm: public QWidget {
  Q_OBJECT
private:
  QLabel *label;
  QLineEdit *itemEdit;
  QPushButton *addItemButton;
  QListWidget *list1;
  QPushButton *moveRightButton;
  QPushButton *moveRightAllButton;
  QPushButton *moveLeftButton;
  QPushButton *moveLeftAllButton;
  QListWidget *list2;

private slots:
  void on_addItemButton_clicked();
  void on_moveRightButton_clicked();
  void on_moveRightAllButton_clicked();
  void on_moveLeftButton_clicked();
  void on_moveLeftAllButton_clicked();

public:
  explicit MainForm(QWidget *parent);
  ~MainForm ();
  void setupUI();
};

#endif
