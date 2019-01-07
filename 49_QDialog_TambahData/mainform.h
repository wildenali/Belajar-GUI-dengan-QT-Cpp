#ifndef MAINFORM_H
#define MAINFORM_H

#include <QWidget>
#include <QPushButton>
#include <QTableWidget>

class MainForm: public QWidget{
  Q_OBJECT
private:
  int lastRecordNumber;
  QTableWidget *tableWidget;
  QPushButton *addButton;
  QPushButton *deleteButton;
  QPushButton *exitButton;
  void setColumnAndHeaders();
  void addRow(int row, QStringList &itemLabels);

private slots:
  void on_addButton_clicked();
  void on_deleteButton_clicked();
  void on_exitButton_clicked();

public:
  explicit MainForm(QWidget *parent);
  ~MainForm();
  void setupUI();
};

#endif
