#include <QCoreApplication>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

const int ID = 0;
const int NAMA = 1;
const int NOHP = 2;

int main(int argc, char *argv[]) {
  QCoreApplication apps(argc, argv);

  QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
  db.setDatabaseName("testdb_nih");

  if (db.open()) {
    QSqlQuery query;

    query.exec("SELECT * FROM phonebook");

    while (query.next()) {
      int id = query.value(ID).toInt();
      QString nama = query.value(NAMA).toString();
      QString nohp = query.value(NOHP).toString();
      qDebug() << id
               << "\t"
               << nama
               << "\t"
               << nohp;
    }

  } else {
    qDebug() << "ERROR: " + db.lastError().text();
  }

  return apps.exec();
}
