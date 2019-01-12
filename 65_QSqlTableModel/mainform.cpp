#include "mainform.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#include <QModelIndexList>
#include <QModelIndex>

MainForm::MainForm(QWidget *parent) : QWidget(parent) {
  db = QSqlDatabase::addDatabase("QSQLITE");
  db.setDatabaseName("testdb");

  if (!db.open()) {
    QMessageBox::critical(this, "Kesalahan", tr("ERROR: ") + db.lastError().text());
    return;
  }

  model = new QSqlTableModel(this, db);
  model->setTable("phonebook");
  model->setEditStrategy(QSqlTableModel::OnFieldChange);
  model->select();

  this->setupUI();
}

MainForm::~MainForm() {
  delete model;
  delete tableView;
  delete addButton;
  delete deleteButton;
}

void MainForm::setupUI() {
  this->resize(350, 300);
  this->move(500, 250);
  this->setWindowTitle("pakai QSqlTableModel");

  tableView = new QTableView();
  tableView->setModel(model);

  addButton = new QPushButton("tambah");
  deleteButton = new QPushButton("delete");

  QHBoxLayout *hbox = new QHBoxLayout();
  hbox->addWidget(addButton);
  hbox->addWidget(deleteButton);
  hbox->addStretch();

  QVBoxLayout *layout = new QVBoxLayout();
  layout->addWidget(tableView);
  layout->addLayout(hbox);

  this->setLayout(layout);

  connect(addButton, SIGNAL(clicked()), this, SLOT(on_addButton_clicked()));
  connect(deleteButton, SIGNAL(clicked()), this, SLOT(on_deleteButton_clicked()));
}

void MainForm::on_addButton_clicked() {
  model->insertRows(model->rowCount(), 1);
}

void MainForm::on_deleteButton_clicked() {
  QModelIndexList indexList = tableView->selectionModel()->selection().indexes();
  for (int i = 0; i < indexList.size(); i++) {
    QModelIndex index = indexList.at(i);
    int row = index.row();
    model->removeRows(row, 1);
  }
  model->select();
}
