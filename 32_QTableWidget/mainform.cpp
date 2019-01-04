#include "mainform.h"
#include <QVBoxLayout>
#include <QStringList>
#include <QTableWidgetItem>

MainForm::MainForm(QWidget *parent) : QWidget(parent) {
  this->setupUI();
}

MainForm::~MainForm() {
  delete tableWidget;
  delete lineEdit;
}

void MainForm::setupUI() {
  this->resize(400, 300);
  this->move(500, 200);
  this->setWindowTitle("QTableWidget");

  tableWidget = new QTableWidget();
  tableWidget->setRowCount(5);
  tableWidget->setColumnCount(3);

  QStringList columnHeaders;
  columnHeaders.append("Judul Buku");
  columnHeaders.append("Penulis");
  columnHeaders.append("Penerbit");

  tableWidget->setHorizontalHeaderLabels(columnHeaders);

  QStringList record1;
  record1.append("Data Structure and Algorithm Analysis in C++");
  record1.append("Mark Allen Weis");
  record1.append("Pearson Education");
  addRow(0, record1);

  QStringList record2;
  record2.append("An Introduction to Design Pattern in C++ with Qt 4");
  record2.append("Alan Ezust & Paul Ezust");
  record2.append("Prentice Hall");
  addRow(1, record2);

  QStringList record3;
  record3.append("Ruby Under a Microscope");
  record3.append("Pat Shaughnessy");
  record3.append("No Starch Press");
  addRow(2, record3);

  QStringList record4;
  record4.append("Beginning Ruby");
  record4.append("Peter Cooper");
  record4.append("Apress");
  addRow(3, record4);

  QStringList record5;
  record5.append("Numerical Python");
  record5.append("Robert Johansson");
  record5.append("Apress");
  addRow(4, record5);

  lineEdit = new QLineEdit();

  QVBoxLayout *layout = new QVBoxLayout();
  layout->addWidget(tableWidget);
  layout->addWidget(lineEdit);

  this->setLayout(layout);

  connect(tableWidget, SIGNAL(itemClicked(QTableWidgetItem*)), this, SLOT(on_tableWidget_itemClicked()));
}

void MainForm::on_tableWidget_itemClicked() {
  QTableWidgetItem *item = tableWidget->currentItem();
  QString sCurrentRow,  sCurrentColumn;
  sCurrentRow.setNum(tableWidget->currentRow());
  sCurrentColumn.setNum(tableWidget->currentColumn());
  lineEdit->setText(item->text() + " [baris: " + sCurrentRow + ", kolom " + sCurrentColumn + "]");
}

void MainForm::addRow(int row, QStringList itemLabels) {
  QTableWidgetItem *item;
  for (int i = 0; i < itemLabels.size(); i++) {
    item = new QTableWidgetItem();
    item->setText(itemLabels.at(i));
    tableWidget->setItem(row, i, item);
  }
}
