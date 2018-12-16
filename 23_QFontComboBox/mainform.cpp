#include "mainform.h"
#include <QVBoxLayout>
#include <QFont>

MainForm::MainForm(QWidget *parent) : QWidget(parent) {
  this->setupUI();
}

MainForm::~MainForm() {
  delete fontCombo;
  delete label;
}

void MainForm::setupUI() {
  this->resize(300,100);
  this->move(500,200);
  this->setWindowTitle("QFontComboBox");

  fontCombo = new QFontComboBox();
  fontCombo->setEditable(false);

  label = new QLabel("Contoh Teks");
  label->setFont(QFont("DejaVu Sans", 18));

  QVBoxLayout *layout = new QVBoxLayout();
  layout->addWidget(fontCombo);
  layout->addWidget(label);
  layout->addStretch();

  this->setLayout(layout);

  connect(fontCombo, SIGNAL(activated(QString)), this, SLOT(on_fontCombo_activated()));
}

void MainForm::on_fontCombo_activated() {
  label->setFont(QFont(fontCombo->currentText(), 18));
}
