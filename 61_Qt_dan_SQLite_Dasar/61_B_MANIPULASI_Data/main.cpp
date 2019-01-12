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

    // meNAMBAHkan data ke dalam database
    QString sqlInsert = " \
            INSERT INTO phonebook \
            VALUE(1, 'usr bin python', '08123456789') \
            ";
    query.exec(sqlInsert);


    // meNGUBAH data di dalam databse
    QString sqlUpdate = " \
            UPDATE phonebook \
            SET nohp = '081111111') \
            WHERE id = 1 \
            ";
    query.exec(sqlUpdate);

    // mengHAPUS data dari database
    QString sqlDelete = " \
            DELETE FROM phonebook \
            WHERE id = 1 \
            ";
    query.exec(sqlDelete);


  } else {
    qDebug() << "ERROR: " + db.lastError().text();
  }

  return apps.exec();
}
