#include <QCoreApplication>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

int main(int argc, char *argv[]) {
  QCoreApplication apps(argc, argv);

  QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
  db.setDatabaseName("testdb_nih");

  if (db.open()) {
    QSqlQuery query;

    // meNAMBAHkan tiga baris data ke dalam database
    query.exec("INSERT INTO phonebook VALUES(1, 'Ana', '0810000001')");
    query.exec("INSERT INTO phonebook VALUES(2, 'Ani', '0810000002')");
    query.exec("INSERT INTO phonebook VALUES(3, 'Anu', '0810000003')");

  } else {
    qDebug() << "ERROR: " + db.lastError().text();
  }

  return apps.exec();
}
