#include "mainform.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QMessageBox>

MainForm::MainForm(QWidget *parent) : QWidget(parent) {
  this->setupUI();
}

MainForm::~MainForm() {
  delete calendar;
  delete shortNamesCheck;
  delete dateEdit;
  delete setButton;
  delete getButton;
}

void MainForm::setupUI() {
  this->resize(400, 100);
  this->move(400, 250);
  this->setWindowTitle("Demo QCalendarWidget");

  calendar = new QCalendarWidget();
  calendar->setGridVisible(true);
  calendar->setHorizontalHeaderFormat(
    QCalendarWidget::LongDayNames
  );

  shortNamesCheck = new QCheckBox("Nama hari pendek");

  dateEdit = new QDateEdit();
  dateEdit->setDisplayFormat("dd/MM/yyyy");
  dateEdit->setDate(QDate::currentDate());

  setButton = new QPushButton("Tentukan Tanggal");
  getButton = new QPushButton("Ambil Tanggal");

  QHBoxLayout *hbox=new QHBoxLayout();
  hbox->addWidget(dateEdit);
  hbox->addWidget(setButton);
  hbox->addWidget(getButton);

  QVBoxLayout *layout = new QVBoxLayout();
  layout->addWidget(calendar);
  layout->addWidget(shortNamesCheck);
  layout->addLayout(hbox);

  this->setLayout(layout);

  connect(shortNamesCheck, SIGNAL(clicked(bool)), this, SLOT(on_shortNamesCheck_clicked()));
  connect(setButton, SIGNAL(clicked(bool)), this, SLOT(on_setButton_clicked()));
  connect(getButton, SIGNAL(clicked(bool)), this, SLOT(on_getButton_clicked()));

}


void MainForm::on_shortNamesCheck_clicked() {
  if (shortNamesCheck->isChecked()) {
    calendar->setHorizontalHeaderFormat(
      QCalendarWidget::ShortDayNames
    );
  } else {
    calendar->setHorizontalHeaderFormat(
      QCalendarWidget::LongDayNames
    );
  }

}

void MainForm::on_setButton_clicked() {
  calendar->setSelectedDate(dateEdit->date());
}

void MainForm::on_getButton_clicked() {
  QMessageBox::information(this, "Informasi", "Tanggal aktif: " + calendar->selectedDate().toString());
}
