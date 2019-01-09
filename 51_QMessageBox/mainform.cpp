#include "mainform.h"
#include <QHBoxLayout>
#include <QMessageBox>

MainForm::MainForm(QWidget *parent) : QWidget(parent) {
  this->setupUI();
}

MainForm::~MainForm() {
  delete aboutButton;
  delete critialButton;
  delete informationButton;
  delete questionButton;
  delete warningButton;
}

void MainForm::setupUI() {
  this->resize(450, 100);
  this->move(500, 300);
  this->setWindowTitle("QMessageBox");

  aboutButton = new QPushButton("About");
  critialButton = new QPushButton("Critical");
  informationButton = new QPushButton("Information");
  questionButton = new QPushButton("Question");
  warningButton = new QPushButton("Warning");

  QHBoxLayout *layout = new QHBoxLayout();
  layout->addWidget(aboutButton);
  layout->addWidget(critialButton);
  layout->addWidget(informationButton);
  layout->addWidget(questionButton);
  layout->addWidget(warningButton);

  this->setLayout(layout);

  connect(aboutButton, SIGNAL(clicked()), this, SLOT(on_aboutButton_clicked()));
  connect(critialButton, SIGNAL(clicked()), this, SLOT(on_criticalButton_clicked()));
  connect(informationButton, SIGNAL(clicked()), this, SLOT(on_informationButton_clicked()));
  connect(questionButton, SIGNAL(clicked()), this, SLOT(on_questionButton_clicked()));
  connect(warningButton, SIGNAL(clicked()), this, SLOT(on_warningButton_clicked()));
}

void MainForm::on_aboutButton_clicked() {
  QMessageBox::about(this, "Tentang Program", tr("Image Editor<br>") + tr("Versi XXX<br>") + tr("Hak Cipta YYY"));
}

void MainForm::on_criticalButton_clicked() {
  QMessageBox::critical(this, "Kesalahan", "Laah salah coooy");
}

void MainForm::on_informationButton_clicked() {
  QMessageBox::information(this, "Info info nih", "Mantaaap infonya");
}

void MainForm::on_questionButton_clicked() {
  QMessageBox::StandardButton button;
  button = QMessageBox::question(this, "Konfirmasi", "Apa anda Yaquin???");
  if (button == QMessageBox::Yes) {
    QMessageBox::about(this, "Respon", "Anda memilih YEEEeeess");
  } else {
    QMessageBox::about(this, "Respon", "Anda memilih NNooooooo");
  }
}

void MainForm::on_warningButton_clicked() {
  QMessageBox::about(this, "Peringatan", tr("Dengan melakukan klik OK<br>") + tr("Semua data di HAPUUS"));
}
