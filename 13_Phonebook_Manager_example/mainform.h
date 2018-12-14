#ifndef MAINFORM_H
#define MAINFORM_H

#include "entryform.h"
#include <QWidget>
#include <QListWidget>
#include <QPushButton>

class MainForm: public QWidget {
  Q_OBJECT

private:
  QListWidget *contactList;
  QPushButton *addButton;
  QPushButton *editButton;
  QPushButton *deleteButton;
  QPushButton *clearButton;
  QPushButton *exitButton;

private slots:
  void on_addButton_clicked();
  void on_editButton_clicked();
  void on_deleteButton_clicked();

public:
  explicit MainForm(QWidget *parent);
  ~MainForm();
  void setupUI();
};

#endif
