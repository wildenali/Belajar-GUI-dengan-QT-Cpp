#ifndef MAINFORM_H
#define MAINFORM_H

#include <QWidget>
#include <QLabel>
#include <QTextEdit>
#include <QPushButton>
#include <QTableView>
#include <QListWidget>
#include <QSqlDatabase>

class MainForm: public QWidget{
  Q_OBJECT
private:
  QSqlDatabase db;
  QLabel *label1;
  QTextEdit *sqlTextEdit;
  QLabel *emptyLabel;
  QPushButton *executeButton;
  QLabel *label2;
  QTableView *tableView;
  QLabel *label3;
  QListWidget *logList;

private slots:
  void on_executeButton_clicked();

public:
  explicit MainForm(QWidget *parent);
  ~MainForm();
  void setupUI();
};

#endif
