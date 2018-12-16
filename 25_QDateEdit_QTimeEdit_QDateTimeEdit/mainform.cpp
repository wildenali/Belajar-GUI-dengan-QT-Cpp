#include "mainform.h"
#include <QHBoxLayout>
#include <QGridLayout>
#include <QMessageBox>

MainForm::MainForm(QWidget *parent) : QWidget(parent) {
  this->setupUI();
}

MainForm::~MainForm() {
  delete dateLabel;
  delete dateEdit;
  delete timeLabel;
  delete timeEdit;
  delete dateTimeLabel;
  delete dateTimeEdit;
  delete okButton;
}

void MainForm::setupUI() {
  this->resize(500,100);
  this->move(500,200);
  this->setWindowTitle("QDateEdit, QTimeEdit, QDateTimeEdit");

  dateLabel = new QLabel("Tanggal");
  dateEdit = new QDateEdit();
  dateEdit->setDisplayFormat("dddd dd/MM/yyyy");
  dateEdit->setDate(QDate::currentDate());

  timeLabel = new QLabel("Waktu");
  timeEdit = new QTimeEdit();
  timeEdit->setDisplayFormat("hh:mm");
  timeEdit->setTime(QTime::currentTime());

  dateTimeLabel = new QLabel("Tanggal dan Waktu");
  dateTimeEdit = new QDateTimeEdit();
  dateTimeEdit->setDisplayFormat("dddd dd/MM/yyyy hh:mm");
  dateTimeEdit->setDateTime(QDateTime::currentDateTime());

  okButton = new QPushButton("&Ok");

  QHBoxLayout *hbox = new QHBoxLayout();
  hbox->addStretch();
  hbox->addWidget(okButton);

  QGridLayout *layout = new QGridLayout();
  layout->addWidget(dateLabel, 0, 0);
  layout->addWidget(dateEdit, 0, 1);
  layout->addWidget(timeLabel, 1, 0);
  layout->addWidget(timeEdit, 1, 1);
  layout->addWidget(dateTimeLabel, 2, 0);
  layout->addWidget(dateTimeEdit, 2, 1);
  layout->addLayout(hbox, 3, 0, 1, 2);

  this->setLayout(layout);

  connect(okButton, SIGNAL(clicked()), this, SLOT(on_okButton_clicked()));
}

void MainForm::on_okButton_clicked() {
  QMessageBox::information(this, "informasi",
                          "Date: " + dateEdit->date().toString() + "<br>" +
                          "Time: " + timeEdit->time().toString() + "<br>" +
                          "DateTime: " + dateTimeEdit->dateTime().toString()
                        );
}
