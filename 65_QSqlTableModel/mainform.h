#ifndef MAINFORM_H
#define MAINFORM_H

#include <QWidget>
#include <QTableView>
#include <QPushButton>
#include <QSqlDatabase>
#include <QSqlTableModel>

class MainForm: public QWidget{
  Q_OBJECT
private:
  QSqlDatabase db;
  QSqlTableModel *model;
  QTableView *tableView;
  QPushButton *addButton;
  QPushButton *deleteButton;

private slots:
  void on_addButton_clicked();
  void on_deleteButton_clicked();

public:
  explicit MainForm(QWidget *parent);
  ~MainForm();
  void setupUI();
};

#endif
