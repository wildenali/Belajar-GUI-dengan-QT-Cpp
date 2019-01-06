#include "mainform.h"
#include <QVBoxLayout>
#include <QFont>
#include <QDate>
#include <QTime>

using namespace std;

MainForm::MainForm(QWidget *parent) : QWidget(parent) {
  // membuat objek dari kelas QTimer
  timer = new QTimer();
  timer->setInterval(1000);    // 1 detik

  this->setupUI();
  timer->start();   // mengaktifkan timer
}

MainForm::~MainForm() {
  delete label1;
  delete label2;
  delete timer;
}

void MainForm::setupUI() {
  this->resize(250, 100);
  this->move(500, 200);
  this->setWindowTitle("QTimer");

  QFont font;
  font.setFamily("SansSerif");
  font.setPixelSize(30);

  label1 = new QLabel();
  QDate currentDate = QDate::currentDate();
  label1->setText(currentDate.toString());
  label1->setAlignment(Qt::AlignHCenter);

  label2 = new QLabel();
  label2->setAlignment(Qt::AlignHCenter);
  label2->setFont(font);

  QVBoxLayout *layout = new QVBoxLayout();
  layout->addWidget(label1);
  layout->addWidget(label2);

  this->setLayout(layout);

  connect(timer, SIGNAL(timeout()), this, SLOT(on_timer_timeout()));
}

void MainForm::on_timer_timeout() {
  QTime currentTime = QTime::currentTime();
  label2->setText(currentTime.toString());
}
