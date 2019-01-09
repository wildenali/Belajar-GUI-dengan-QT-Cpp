#ifndef MAINFORM_H
#define MAINFORM_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QTreeView>
#include <QFileSystemModel>

class MainForm: public QWidget{
  Q_OBJECT
private:
  QFileSystemModel *model;
  QLineEdit *lineEdit;
  QPushButton *dirButton;
  QTreeView *treeView;

private slots:
  void on_dirButton_clicked();

public:
  explicit MainForm(QWidget *parent);
  ~MainForm();
  void setupUI();
};

#endif
