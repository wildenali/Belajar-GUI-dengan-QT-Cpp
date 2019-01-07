#include "mainform.h"
#include "dialogform.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QTableWidgetItem>

MainForm::MainForm(QWidget *parent) : QWidget(parent) {
  lastRecordNumber = -1;
  this->setupUI();
}

MainForm::~MainForm() {
  delete tableWidget;
  delete addButton;
  delete deleteButton;
  delete exitButton;
}

void MainForm::setupUI() {
  this->resize(450, 300);
  this->move(350, 250);
  this->setWindowTitle("QDialog::accept() dan QDialog::reject()");

  tableWidget = new QTableWidget();
  tableWidget->setRowCount(0);
  setColumnAndHeaders();

  addButton = new QPushButton("Tambah");
  deleteButton = new QPushButton("Hapus");
  exitButton = new QPushButton("Keluar");


  QVBoxLayout *vbox = new QVBoxLayout();
  vbox->addWidget(addButton);
  vbox->addWidget(deleteButton);
  vbox->addStretch();
  vbox->addWidget(exitButton);

  QHBoxLayout *layout = new QHBoxLayout();
  layout->addWidget(tableWidget);
  layout->addLayout(vbox);

  this->setLayout(layout);

  connect(addButton, SIGNAL(clicked()), this, SLOT(on_addButton_clicked()));
  connect(deleteButton, SIGNAL(clicked()), this, SLOT(on_deleteButton_clicked()));
  connect(exitButton, SIGNAL(clicked()), this, SLOT(on_exitButton_clicked()));
}

void MainForm::setColumnAndHeaders() {
  tableWidget->setColumnCount(2);
  QStringList columnHeaders;
  columnHeaders << "Bahasa Pemrograman" << "Nama Pencipta";
  tableWidget->setHorizontalHeaderLabels(columnHeaders);
}

void MainForm::addRow(int row, QStringList &itemLabels) {
  for (int i = 0; i < 2; i++) {
    QTableWidgetItem *item = new QTableWidgetItem();
    item->setText(itemLabels.at(i));
    tableWidget->setItem(row, i, item);
  }
}

void MainForm::on_addButton_clicked() {
  if (lastRecordNumber == tableWidget->rowCount()-1) {
    tableWidget->setRowCount(tableWidget->rowCount()+1);
    DialogForm *form = new DialogForm(this);
    if (form->exec() == QDialog::Accepted) {
      lastRecordNumber += 1;
      QString language = form->getLanguage();
      QString name = form->getName();
      QStringList data;
      data << language << name;
      addRow(lastRecordNumber, data);
    }
  }
}

void MainForm::on_deleteButton_clicked() {
  QList<QStringList> tableData;
  for (int i = 0; i < tableWidget->rowCount(); i++) {
    QString language = tableWidget->item(i, 0)->text();
    QString name = tableWidget->item(i, 1)->text();
    QStringList data;
    data << language << name;
    tableData.append(data);
  }

  int row = tableWidget->currentRow();
  tableData.removeAt(row);

  lastRecordNumber -= 1;
  tableWidget->clear();
  setColumnAndHeaders();
  tableWidget->setRowCount(tableData.size());
  for (int i = 0; i < tableData.size(); i++) {
    QStringList data = tableData.at(i);
    addRow(i, data);
  }
}

void MainForm::on_exitButton_clicked() {
  this->close();
}
