#include "mainform.h"
#include <QGridLayout>
#include <QFont>

MainForm::MainForm(QWidget *parent) : QWidget(parent) {
  this->setupUI();
}

MainForm::~MainForm() {
  delete fontLabel;
  delete fontCombo;
  delete sizeLabel;
  delete sizeSpinBox;
  delete sampleLabel;
}

void MainForm::setupUI() {
  this->resize(300,100);
  this->move(500,200);
  this->setWindowTitle("QSpinBox");

  fontLabel = new QLabel("Jenis huruf");
  fontCombo = new QFontComboBox();
  fontCombo->setEditable(false);

  sizeLabel = new QLabel("Ukuran huruf");
  sizeSpinBox = new QSpinBox();
  sizeSpinBox->setRange(5, 40);
  sizeSpinBox->setSingleStep(1);
  sizeSpinBox->setValue(18);

  sampleLabel = new QLabel("Contoh Teks");
  sampleLabel->setFont(QFont("DejaVu Sans", 19));

  QGridLayout *layout = new QGridLayout();
  layout->addWidget(fontLabel, 0, 0);
  layout->addWidget(fontCombo, 0, 1);
  layout->addWidget(sizeLabel, 1, 0);
  layout->addWidget(sizeSpinBox, 1, 1);
  layout->addWidget(sampleLabel, 2, 0, 1, 2);

  this->setLayout(layout);

  connect(fontCombo, SIGNAL(activated(QString)), this, SLOT(changeFont()));
  connect(sizeSpinBox, SIGNAL(valueChanged(int)), this, SLOT(changeFont()));
}

void MainForm::changeFont() {
  sampleLabel->setFont(QFont(fontCombo->currentText(),sizeSpinBox->value()));
}
