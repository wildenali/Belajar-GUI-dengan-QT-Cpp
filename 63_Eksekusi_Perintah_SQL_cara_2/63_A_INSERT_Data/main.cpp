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

    // meNYIAPkan perintah SQL
    query.prepare("INSERT INTO phonebook VALUES(:id,:nama,:nohp)");

    // meNAMBAHkan nilai parameter
    query.bindValue(0, (QVariant) 5);
    query.bindValue(1, (QVariant) "Ano");
    query.bindValue(2, (QVariant) "0810000005");

    query.exec();

  } else {
    qDebug() << "ERROR: " + db.lastError().text();
  }

  return apps.exec();
}
