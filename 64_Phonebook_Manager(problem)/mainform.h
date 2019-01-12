#ifndef MAINFORM_H
#define MAINFORM_H

#include <QWidget>
#include <QTableWidget>
#include <QPushButton>
#include <QSqlDatabase>

class MainForm: public QWidget{
  Q_OBJECT
private:
  QSqlDatabase db;
  QTableWidget *tableWidget;
  QPushButton *addButton;
  QPushButton *editButton;
  QPushButton *deleteButton;
  void loadData();
  int getRowCount();

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
