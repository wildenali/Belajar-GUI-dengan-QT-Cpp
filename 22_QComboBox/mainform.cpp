#include "mainform.h"
#include <QVBoxLayout>
#include <QMessageBox>

MainForm::MainForm(QWidget *parent) : QWidget(parent) {
  this->setupUI();
}

MainForm::~MainForm() {
  delete combo;
  delete getTextButton;
}

void MainForm::setupUI() {
  this->resize(300,100);
  this->move(500,200);
  this->setWindowTitle("QComboBox");

  combo = new QComboBox();

  for (int i = 0; i < 10; i++) {
    QString s;
    combo->addItem("Item ke-" + s.setNum(++i));
  }

  getTextButton = new QPushButton("Ambil Teks");

  QVBoxLayout *layout = new QVBoxLayout();
  layout->addWidget(combo);
  layout->addWidget(getTextButton);
  layout->addStretch();

  this->setLayout(layout);

  connect(getTextButton, SIGNAL(clicked()), this, SLOT(on_getTextButton_clicked()));
}

void MainForm::on_getTextButton_clicked() {
  QMessageBox::information(this, "informasi", "Anda Memilih: " + combo->currentText());
}
