#include "mainform.h"
#include "entryform.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#include <QTableWidgetItem>

MainForm::MainForm(QWidget *parent) : QWidget(parent) {
  db = QSqlDatabase::addDatabase("QSQLITE");
  db.setDatabaseName("testdb");

  if (!db.open()) {
    QMessageBox::critical(this, "Kesalahan", tr("ERROR: ") + db.lastError().text());
    return;
  }
  this->setupUI();
  loadData();
}

MainForm::~MainForm() {
  delete tableWidget;
  delete addButton;
  delete editButton;
  delete deleteButton;
}

void MainForm::setupUI() {
  this->resize(350, 300);
  this->move(300, 300);
  this->setWindowTitle("Phonebook Manager");

  addButton = new QPushButton("Tambah");
  editButton = new QPushButton("Ubah");
  deleteButton = new QPushButton("Hapus");

  QHBoxLayout *hbox = new QHBoxLayout();
  hbox->addWidget(addButton);
  hbox->addWidget(editButton);
  hbox->addWidget(deleteButton);
  hbox->addStretch();

  QVBoxLayout *layout = new QVBoxLayout();
  layout->addWidget(tableWidget);
  layout->addLayout(hbox);

  this->setLayout(layout);

  connect(addButton, SIGNAL(clicked()), this, SLOT(on_addButton_clicked()));
  connect(editButton, SIGNAL(clicked()), this, SLOT(on_editButton_clicked()));
  connect(deleteButton, SIGNAL(clicked()), this, SLOT(on_deleteButton_clicked()));
}

void MainForm::loadData() {
  tableWidget->clear();
  tableWidget->setRowCount(getRowCount());
  tableWidget->setColumnCount(3);

  QStringList columnHeaders;
  columnHeaders << "ID" << "Nama" << "No. HP";
  tableWidget->setHorizontalHeaderLabels(columnHeaders);

  QSqlQuery query;
  int row = 0;
  query.exec("SELECT * FROM phonebook");
  while (query.next()) {
    for (int i = 0; i < 3; i++) {
      QTableWidgetItem *item = new QTableWidgetItem();
      if (i == 0) {
        item->setText(QString::number(query.value(i).toInt()));
      } else {
        item->setText(query.value(i).toString());
      }
      tableWidget->setItem(row, i, item);
    }
    row++;
  }
}

int MainForm::getRowCount() {
  QSqlQuery query;
  query.exec("SELECT COUNT(*) FROM phonebook");
  query.next();
  return query.value(0).toInt();
}

void MainForm::on_addButton_clicked() {
  EntryForm entryForm;
  entryForm.setName("");
  entryForm.setPhoneNumber("");
  if (entryForm.exec() == QDialog::Accepted) {
    int id = getRowCount() + 1;
    QSqlQuery query;
    query.prepare("INSERT INTO phonebook VALUES(?,?,?)");
    query.addBindValue((QVariant) id);
    query.addBindValue((QVariant) entryForm.getName());
    query.addBindValue((QVariant) entryForm.getPhoneNumber());
    query.exec();
    loadData();
  }
}

void MainForm::on_editButton_clicked() {
  EntryForm entryForm;
  entryForm.setName(tableWidget->item(tableWidget->currentRow(),1)->text());
  entryForm.setPhoneNumber(tableWidget->item(tableWidget->currentRow(),2)->text());
  if (entryForm.exec() == QDialog::Accepted) {
    int id = tableWidget->item(tableWidget->currentRow(),0)->text().toInt();
    QSqlQuery query;
    query.prepare(tr("UPDATE phonebook ") + tr("SET nama ?, nohp = ? ") + tr("WHERE id = ?"));
    query.addBindValue((QVariant) entryForm.getName());
    query.addBindValue((QVariant) entryForm.getPhoneNumber());
    query.addBindValue((QVariant) id);
    query.exec();
    loadData();
  }
}

void MainForm::on_deleteButton_clicked() {
  int id = tableWidget->item(tableWidget->currentRow(),0)->text().toInt();
  QSqlQuery query;
  query.prepare(tr("DELETE FROM phonebook ") + tr("WHERE id = ?"));
  query.addBindValue((QVariant) id);
  query.exec();
  loadData();
}
