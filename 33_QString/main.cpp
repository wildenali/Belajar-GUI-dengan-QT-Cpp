#include <QCoreApplication>
#include <QDebug>
#include <QStringList>  //Contoh No 9. ketika menggunakan QStringList, kita harus memasukan #include <QStringList>

int main(int argc, char *argv[]) {
  QCoreApplication apps(argc, argv);

  QString pemisah = "                           ";

  // 1. Hello world nya QString
    QString nomor1 = "1. Hellonya String";
    // Deklarasi pointer ke tipe QString
    QString *hello;
    // Membuat objek yang ditunjuk oleh pointer s
    hello = new QString("C++ dan Qt");
    qDebug() << nomor1;
    qDebug() << *hello;
    qDebug() << pemisah;
    // Menghapus objek QString setelah digunakan
    delete hello;


  // 2. mengGABUNGkan string string
    QString nomor2 = "2. mengGABUNGkan String";
    QString a = "Ini A";
    QString b = "Ini B";
    QString c = "Ini C";

    QString gabungkan = a + " " + b + " " + c;

    qDebug() << nomor2;
    qDebug() << a << b << c;
    qDebug() << gabungkan;
    qDebug() << pemisah;


  // 3. memBANDINGkan string
    QString nomor3 = "3. memBANDINGkan string";
    QString siA = "XXXX";
    QString siB = "XXx";
    qDebug() << nomor3;
    qDebug() << "siA:" << siA << "siB:"<< siB;
    if (siA == siB) {
      qDebug() << "siA dan siB SAMA";
    } else {
      qDebug() << "siA dan siB BEDA";
    }
    qDebug() << pemisah;


  // 4. memBANDINGkan string pakai fungsi -> toLower() atau to Upper()
    QString nomor4 = "4. memBANDINGkan string dgn fungsi toLower() atau toUpper()";
    QString siC = "XXXX";
    QString siD = "xxxx";

    qDebug() << nomor4;
    qDebug() << "siC:" << siC << "siD:"<< siD;
    if (siC.toLower() == siD.toLower()) {
      qDebug() << "siC dan siD SAMA";
    } else {
      qDebug() << "siC dan siD BEDA";
    }
    qDebug() << pemisah;


  // 5. memBANDINGkan string pakai fungsi compare()
    QString nomor5 = "5. memBANDINGkan string pakai fungsi compare()";
    QString siE = "XXXX";
    QString siF = "xxxx";

    qDebug() << nomor5;
    qDebug() << "siE:" << siE << "siF:"<< siF;
    if (siE.compare(siF, Qt::CaseInsensitive) == 0) {   // Qt::CaseInsensitive dan Qt::CaseSensitive
      qDebug() << "siE dan siF SAMA";
    } else {
      qDebug() << "siE dan siF BEDA";
    }
    qDebug() << pemisah;


  // 6. get Character in Index with at()
    QString nomor6 = "6. get Character in Index with at()";
    QString siG = "wilden";

    qDebug() << nomor6;
    qDebug() << "siG:" << siG;
    qDebug() << "siG.at(0)" << siG.at(0);
    qDebug() << "siG.at(2)" << siG.at(2);
    qDebug() << "siG.at(5)" << siG.at(5);
    qDebug() << pemisah;


  // 7. menCARI indek pada Karakter atau Substring
    // jadi gini, kita cari posisi huruf P dan n di dalam siH dan posisi substring BULAN ada dimana
    QString nomor7 = "7. menCARI indek pada Karakter atau Substring";
    QString siH = "Pada hari minggu terbang ke BULAN dengan Delman";

    qDebug() << nomor7;
    qDebug() << "siH:" << siH;
    qDebug() << "posisi huruf P" << siH.indexOf('P');
    qDebug() << "posisi hurug n" << siH.indexOf('n');
    qDebug() << "posisi hurug BULAN" << siH.indexOf("BULAN");
    qDebug() << pemisah;


  // 8. get JUMLAH karakter dalam string
    QString nomor8 = "8. get JUMLAH karakter dalam string";
    QString siI = "Pada hari minggu terbang ke BULAN dengan Delman";

    qDebug() << nomor8;
    qDebug() << "siI:" << siI;
    qDebug() << "size()  -> Jumlah hurufnya ada: " << siI.size();
    qDebug() << "count() -> Jumlah hurufnya ada: " << siI.count();
    qDebug() << pemisah;


  // 9. meMECAH string
    // ketika menggunakan QStringList, kita harus include di atas #include <QStringList>
    QString nomor9 = "9. meMECAH string";
    QString siJ = "C++,Java,C#,Python,Javascript";
    QStringList bahasa = siJ.split(",");

    qDebug() << nomor9;
    qDebug() << "siJ:" << siJ;
    for (int i = 0; i < bahasa.count(); i++) {
      qDebug() << "Indeks ke:" << i << bahasa.at(i);
    }
    qDebug() << pemisah;


  // 10. meNGAMBIL substring dengan fungsi left() mid() right()
    QString nomor10 = "10. meNGAMBIL substring dengan fungsi left() mid() right()";
    QString siK = "C++ Java C# Python Javascript";

    qDebug() << nomor10;
    qDebug() << "siK:" << siK;
    qDebug() << "Sampai Indek ke:" << 5 << "dari KIRI ->"<< siK.left(6);
    qDebug() << "Sampai Indek ke:" << 7 << "dari KANAN ->"<< siK.right(7);
    qDebug() << "Sampai Indek ke:" << 6 << "dari KANAN ->"<< siK.mid(6);
    qDebug() << "Dari Indek ke:" << 4 << "dari KANAN sebanyak 2 huruf->"<< siK.mid(4, 2);
    qDebug() << pemisah;


  // 11. meNGAMBIL substring dengan fungsi section()
    QString nomor11 = "11. meNGAMBIL substring dengan fungsi section()";
    QString siL = "C++**Java**C#**Python**Javascript";

    qDebug() << nomor11;
    qDebug() << "siL:" << siL;
    qDebug() << siL.section("**", 0, 0);
    qDebug() << siL.section("**", 0, 2);
    qDebug() << siL.section("**", 1, 0);
    qDebug() << siL.section("**", 2, 3);
    qDebug() << pemisah;


  // 12. meGANTI substring dengan fungsi replace()
    QString nomor12 = "12. meGANTI substring dengan fungsi replace()";
    QString siM = "Saya suka cireng";

    qDebug() << nomor12;
    qDebug() << "siM:" << siM;
    siM.replace("cireng", "cilok", Qt::CaseSensitive);
    qDebug() << "siM:" << siM;
    qDebug() << pemisah;


  // 13. meNYISIPkan substring dengan fungsi insert()
    QString nomor13 = "13. meNYISIPkan substring dengan fungsi insert()";
    QString siN = "Saya suka cireng";

    qDebug() << nomor13;
    qDebug() << "siN:" << siN;
    siN.insert(10, "cilok dan ");
    qDebug() << "siN:" << siN;
    qDebug() << pemisah;


  // 14. mengHAPUS substring dengan fungsi remove()
    QString nomor14 = "14. mengHAPUS substring dengan fungsi remove()";
    QString siO = "Saya suka cireng";

    qDebug() << nomor14;
    qDebug() << "siO:" << siO;
    siO.remove("reng");
    qDebug() << "siO:" << siO;
    qDebug() << pemisah;


  // 15. KONVERSI string ke NUMERIK
    // fungsi2 nya
    // toShort(), toInt(), toLong(), toLongLong(),
    // toUShort(), toUInt(), toULong(), toULongLong(),
    // toFloat(), toDouble()
    QString nomor15 = "15. KONVERSI string ke NUMERIK";
    QString siP = "3.14";

    qDebug() << nomor15;
    qDebug() << "siP:" << siP;
    // konversi ke Double
    double siPdouble = siP.toDouble();
    qDebug() << "siPdouble:" << siPdouble;
    qDebug() << pemisah;


  // 16. NUMERIK ke STRING dengan fungsi setNum() dan number()
    QString nomor16 = "16. NUMERIK ke STRING dengan fungsi setNum() dan number()";
    double siQ = 3.14;
    double siR = 9.8;
    QString siQstring;

    qDebug() << nomor16;
    qDebug() << "siQ:" << siQ;
    qDebug() << "siR:" << siR;
    siQstring.setNum(siQ);
    qDebug() << "setNum()-> siQstring:" << siQstring;
    qDebug() << "number()-> siQstring:" << QString::number(siR);
    qDebug() << pemisah;

  return apps.exec();
}
