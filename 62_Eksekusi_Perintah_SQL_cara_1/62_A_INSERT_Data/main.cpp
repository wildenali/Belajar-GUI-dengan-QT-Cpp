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

    // meNYISIPkan perintah SQL
    query.prepare("INSERT INTO phonebook VALUES(?,?,?)");

    // meNAMBAHkan nilai parameter
    query.addBindValue((QVariant) 4);   //id(tanda tanya pertama),  4 menunjukan id ke 4
    query.addBindValue((QVariant) "Ane");  //name(tanda tanya kedua), Ane adalah namanya
    query.addBindValue((QVariant) "0810000004");  //nohp(tanda tanya ketida), nohp nya

    query.exec();

  } else {
    qDebug() << "ERROR: " + db.lastError().text();
  }

  return apps.exec();
}
