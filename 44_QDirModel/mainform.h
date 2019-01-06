#ifndef MAINFORM_H
#define MAINFORM_H

#include <QWidget>
#include <QTreeView>
#include <QPushButton>
#include <QDirModel>

class MainForm: public QWidget {
  Q_OBJECT
private:
  QDirModel *model;

  QTreeView *treeView;
  QPushButton *createButton;
  QPushButton *removeButton;

private slots:
  void on_createButton_clicked();
  void on_removeButton_clicked();

public:
  explicit MainForm(QWidget *parent);
  ~MainForm();
  void setupUI();
};

#endif
