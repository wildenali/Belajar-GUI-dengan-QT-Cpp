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
  QTreeWidgetItem *addTopLevel(QString category);
  QTreeWidgetItem *addChild(QTreeWidgetItem *parent,
                            QString title,
                            QString author,
                            QString publisher);

private slots:
  void on_treeWidget_itemClicked();

public:
  explicit MainForm(QWidget *parent);
  ~MainForm();
  void setupUI();
};

#endif
