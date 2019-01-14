#include <QCoreApplication>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>


const int ID = 0;
const int NAMA = 1;
const int NOHP = 2;

int main(int argc, char *argv[]) {
  QCoreApplication apps(argc, argv);

  QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");

  db.setHostName("localhost");
  db.setDatabaseName("testdb");
  db.setUserName("root");
  db.setPassword("sari");

  if (db.open()) {
    qDebug() << "Koneksi ke MySQL SUKSES ... ";

    QSqlQuery query;

    // INSERT data
    // QString sqlInsert = "INSERT INTO phonebook VALUES(6, 'Anu', '081000006')";
    // QString sqlUpdate = "UPDATE phonebook SET nohp = '081000007' WHERE id = 1";
    // QString sqlDelete = "DELETE FROM phonebook WHERE id = 6";
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
    qDebug() << "ERROR : " + db.lastError().text();
  }
  return apps.exec();
}
