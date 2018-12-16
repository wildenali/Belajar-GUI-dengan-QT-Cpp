#include "mainform.h"
#include <QGridLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>

MainForm::MainForm(QWidget *parent) : QWidget(parent) {
  this->setupUI();
}

MainForm::~MainForm() {
  delete label1;
  delete numberEdit1;
  delete label2;
  delete numberEdit2;
  delete addRadio;
  delete substractRadio;
  delete mulRadio;
  delete divRadio;
  delete resultLabel;
  delete calculateButton;
}

void MainForm::setupUI() {
  this->resize(400,100);
  this->move(500,200);
  this->setWindowTitle("QRadioButton dalam Calculator");

  label1 = new QLabel();
  label1->setText("Bilangan Pertama");
  numberEdit1 = new QLineEdit();

  label2 = new QLabel();
  label2->setText("Bilangan Kedua");
  numberEdit2 = new QLineEdit();

  QGridLayout *grid = new QGridLayout();
  grid->addWidget(label1, 0, 0);
  grid->addWidget(numberEdit1, 0, 1);
  grid->addWidget(label2, 1, 0);
  grid->addWidget(numberEdit2, 1, 1);

  addRadio = new QRadioButton();
  addRadio->setText("&Tambah");     // fungsi tanda '&' adalah untuk shortcut (ALT+T)
  addRadio->setChecked(true);

  substractRadio = new QRadioButton();
  substractRadio->setText("&Kurang");     // fungsi tanda '&' adalah untuk shortcut (ALT+K)

  mulRadio = new QRadioButton();
  mulRadio->setText("K&ali");     // fungsi tanda '&' adalah untuk shortcut (ALT+a)

  divRadio = new QRadioButton();
  divRadio->setText("&Bagi");     // fungsi tanda '&' adalah untuk shortcut (ALT+B)

  QHBoxLayout *hbox = new QHBoxLayout();
  hbox->addWidget(addRadio);
  hbox->addWidget(substractRadio);
  hbox->addWidget(mulRadio);
  hbox->addWidget(divRadio);

  resultLabel = new QLabel("<b>Hasil Penjumlahan: </b>");

  calculateButton = new QPushButton("Berapa ya");

  QVBoxLayout *layout = new QVBoxLayout();
  layout->addLayout(grid);
  layout->addLayout(hbox);
  layout->addWidget(resultLabel);
  layout->addWidget(calculateButton);
  layout->addStretch();

  this->setLayout(layout);

  connect(addRadio, SIGNAL(clicked()), this, SLOT(on_addRadio_clicked()));
  connect(substractRadio, SIGNAL(clicked()), this, SLOT(on_substractRadio_clicked()));
  connect(mulRadio, SIGNAL(clicked()), this, SLOT(on_mulRadio_clicked()));
  connect(divRadio, SIGNAL(clicked()), this, SLOT(on_divRadio_clicked()));
  connect(calculateButton, SIGNAL(clicked()), this, SLOT(on_calculateButton_clicked()));
}

void MainForm::setResultLabel(const QString& text) {
  resultLabel->setText("<b>" + text + "</b>");
}

void MainForm::on_addRadio_clicked() {
  this->setResultLabel("Hasil Penjumlahan: ");
}

void MainForm::on_substractRadio_clicked() {
  this->setResultLabel("Hasil Pengurangan: ");
}

void MainForm::on_mulRadio_clicked() {
  this->setResultLabel("Hasil Perkalian: ");
}

void MainForm::on_divRadio_clicked() {
  this->setResultLabel("Hasil Pembagian: ");
}

void MainForm::on_calculateButton_clicked() {
  double a = numberEdit1->text().toDouble();
  double b = numberEdit2->text().toDouble();
  double c = 0.0;

  if (addRadio->isChecked()) {
    c = a + b;
  } else if (substractRadio->isChecked()) {
    c = a - b;
  } else if (mulRadio->isChecked()) {
    c = a * b;
  } else if (divRadio->isChecked()) {
    c = a / b;
  }

  int index = resultLabel->text().indexOf(':');
  QString prefix = resultLabel->text().section("",0,index+2);
  QString s;
  resultLabel->setText(prefix + s.setNum(c) + "</b>");


}
