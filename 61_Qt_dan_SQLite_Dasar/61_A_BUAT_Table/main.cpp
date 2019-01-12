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
    bool ok;
    QSqlQuery query;
    ok = query.exec(
          " \
          CREATE TABLE phonebook (\
            id INTEGER NOT NULL PRIMARY KEY, \
            nama VARCHAR(25), \
            nohp VARCHAR(15) \
          ) \
          "
        );
        if (ok) {
          qDebug() << "Tabel berhasil DIBUAT";
        } else {
          qDebug() << "Tabel gagal dibuat";
        }
  } else {
    qDebug() << "ERROR: " + db.lastError().text();
  }

  return apps.exec();
}
