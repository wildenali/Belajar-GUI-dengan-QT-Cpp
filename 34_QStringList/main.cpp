#include <QCoreApplication>
#include <QDebug>
#include <QStringList>  //Contoh No 9. ketika menggunakan QStringList, kita harus memasukan #include <QStringList>

int main(int argc, char *argv[]) {
  QCoreApplication apps(argc, argv);

  QString pemisah = "---------------------------------------------------------";

  // 1. ADD element -> append()
    QString no1 = "1. ADD element -> append()";
    QStringList siA;

    siA.append("C++");
    siA.append("Python");
    siA.append("Java");
    siA.prepend("Javascript");
    qDebug() << no1;
    qDebug() << siA;
    qDebug() << pemisah;

  // 2. INSERT element -> insert()
    QString no2 = "2. INSERT element -> insert()";
    QStringList siB;

    siB.append("C++");
    siB.append("Python");
    siB.append("Java");
    siB.insert(2,"Golang");
    qDebug() << no2;
    qDebug() << siB;
    qDebug() << pemisah;

  // 3. GET element -> at()
    QString no3 = "3. GET element -> at()";
    QStringList siC;

    siC.append("C++");
    siC.append("Python");
    siC.append("Java");
    qDebug() << no3;
    qDebug() << "Element ke:" << 0 << siC.at(0);
    qDebug() << "Element ke:" << 1 << siC.at(1);
    qDebug() << "Element ke:" << 2 << siC.at(2);
    qDebug() << pemisah;

  // 4. Jumlah element -> size(), count()
    QString no4 = "4. Jumlah element -> size(), count()";
    QStringList siD;

    siD.append("C++");
    siD.append("Python");
    siD.append("Java");
    qDebug() << no4;

    QString D = "[";
    for (int i = 0; i < siD.size(); i++) {
      D += siD.at(i);
      if (i < siD.size()-1) {
        D += ", ";
      }
    }
    D += "]";
    qDebug() << D;

    qDebug() << pemisah;

  // 5. Change element -> replace()
    QString no5 = "5. Change element -> replace()";
    QStringList siE;

    siE.append("C++");
    siE.append("Python");
    siE.append("Java");
    qDebug() << no5;
    qDebug() << "Awalnya ini" << siE;
    siE.replace(1, "Golang");
    qDebug() << "Menjadi ini"<< siE;
    qDebug() << pemisah;

  // 6. Remove element -> remove()
    // fungsi2nya
    // removeAll(QString &value), removeOne(Qstring &value), removeFirst()
    // removeAt(int index), removeLast(), clear()
    QString no6 = "6. Remove element -> remove()";
    QStringList siF;

    siF.append("C++");
    siF.append("Python");
    siF.append("Java");
    siF.append("C#");
    siF.append("C#");
    siF.append("C#");
    siF.append("Go");
    qDebug() << no6;
    qDebug() << siF;
    siF.removeOne("C++");
    qDebug() << "removeOne(''C++'') -> " << siF;

    siF.removeFirst();
    qDebug() << "removeFirst() -> " << siF;

    siF.removeAt(2);
    qDebug() << "removeAt(2) -> " << siF;

    siF.removeLast();
    qDebug() << "removeLast() -> " << siF;

    siF.removeAll("C#");
    qDebug() << "removeAll(''C++'') -> " << siF;

    qDebug() << pemisah;

  return apps.exec();
}
