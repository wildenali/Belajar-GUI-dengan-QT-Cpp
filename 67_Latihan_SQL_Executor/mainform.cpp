#include "mainform.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlQueryModel>
#include <QMessageBox>

MainForm::MainForm(QWidget *parent) : QWidget(parent) {
  db = QSqlDatabase::addDatabase("QMYSQL");
  db.setHostName("localhost");
  db.setDatabaseName("testdb");
  db.setUserName("root");
  db.setPassword("sari");

  if (!db.open()) {
    QMessageBox::critical(this, "Kesalahan", tr("Error: ") + db.lastError().text());
    return;
  }
  this->setupUI();
}

MainForm::~MainForm() {
  delete label1;
  delete sqlTextEdit;
  delete emptyLabel;
  delete executeButton;
  delete label2;
  delete tableView;
  delete label3;
  delete logList;
}

void MainForm::setupUI() {
  this->resize(450, 400);
  this->move(500, 150);
  this->setWindowTitle("SQL Executoooor");

  label1 = new QLabel("Tulis perintah SQL");
  sqlTextEdit = new QTextEdit();

  QVBoxLayout *vbox1 = new QVBoxLayout();
  vbox1->addWidget(label1);
  vbox1->addWidget(sqlTextEdit);

  emptyLabel = new QLabel("");
  executeButton = new QPushButton("&jooos");

  QVBoxLayout *vbox2 = new QVBoxLayout();
  vbox2->addWidget(emptyLabel);
  vbox2->addWidget(executeButton);
  vbox2->addStretch();

  QHBoxLayout *hbox = new QHBoxLayout();
  hbox->addLayout(vbox1);
  hbox->addLayout(vbox2);

  label2 = new QLabel("Hasil query");
  tableView = new QTableView();
  label3 = new QLabel("Log");
  logList = new QListWidget();

  QVBoxLayout *layout = new QVBoxLayout();
  layout->addLayout(hbox);
  layout->addWidget(label2);
  layout->addWidget(tableView);
  layout->addWidget(label3);
  layout->addWidget(logList);

  this->setLayout(layout);

  connect(executeButton, SIGNAL(clicked()), this, SLOT(on_executeButton_clicked()));

}

void MainForm::on_executeButton_clicked() {
  QStringList specialCommands;
  specialCommands << "SHOW" << "DESC"
                  << "DESCRIBE" << "SELECT";
  QString sql = sqlTextEdit->document()->toPlainText();

  bool isSpecialCommand = false;
  for (int i = 0; i < specialCommands.size(); i++) {
    QString firstCommand = specialCommands.at(i);
    if (sql.toUpper().startsWith(firstCommand)) {
      isSpecialCommand = true;
      break;
    }
  }
  if (isSpecialCommand) {
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery(sql);
    tableView->setModel(model);
    tableView->show();
  } else {
    QSqlQuery query;
    query.exec(sql);
  }
  logList->addItem(sql);
}
