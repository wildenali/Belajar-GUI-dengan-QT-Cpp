#ifndef MAINFORM_H
#define MAINFORM_H

#include <QWidget>
#include <QTableWidget>
#include <QLineEdit>

class MainForm: public QWidget {
  Q_OBJECT
private:
  QTableWidget *tableWidget;
  QLineEdit *lineEdit;
  void addRow(int row, QStringList itemLabels);

private slots:
  void on_tableWidget_itemClicked();

public:
  explicit MainForm(QWidget *parent);
  ~MainForm();
  void setupUI();
};

#endif
