#ifndef MAINFORM_H
#define MAINFORM_H

#include <QWidget>
#include <QTreeWidget>
#include <QLineEdit>

class MainForm: public QWidget {
  Q_OBJECT
private:
  QTreeWidget *treeWidget;
  QLineEdit *lineEdit;
  QTreeWidgetItem *addTopLevel(QString itemText);
  QTreeWidgetItem *addChild(QTreeWidgetItem *parent, QString itemText);

private slots:
  void on_treeWidget_itemClicked();

public:
  explicit MainForm(QWidget *parent);
  ~MainForm();
  void setupUI();
};

#endif
