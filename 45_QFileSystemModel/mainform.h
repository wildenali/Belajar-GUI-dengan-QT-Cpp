#ifndef MAINFORM_H
#define MAINFORM_H

#include <QWidget>
#include <QTreeView>
#include <QListView>
#include <QSplitter>
#include <QFileSystemModel>

class MainForm: public QWidget {
  Q_OBJECT
private:
  QFileSystemModel *dirModel;
  QFileSystemModel *fileModel;

  QTreeView *treeView;
  QListView *listView;
  QSplitter *splitter;

private slots:
  void on_treeView_clicked();

public:
  explicit MainForm(QWidget *parent);
  ~MainForm();
  void setupUI();
};

#endif
