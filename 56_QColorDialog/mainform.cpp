#include "mainform.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QColorDialog>

MainForm::MainForm(QWidget *parent) : QWidget(parent) {
  this->setupUI();
}

MainForm::~MainForm() {
  delete textEdit;
  delete colorButton;
}

void MainForm::setupUI() {
  this->resize(300, 250);
  this->move(500, 250);
  this->setWindowTitle("QColorDialog");

  textEdit = new QTextEdit();
  colorButton = new QPushButton("Pilih Warna");

  QHBoxLayout *hbox = new QHBoxLayout();
  hbox->addWidget(colorButton);
  hbox->addStretch();

  QVBoxLayout *layout = new QVBoxLayout();
  layout->addWidget(textEdit);
  layout->addLayout(hbox);

  this->setLayout(layout);

  connect(colorButton, SIGNAL(clicked()), this, SLOT(on_colorButton_clicked()));
}

void MainForm::on_colorButton_clicked() {
  QColor color;
  color = QColorDialog::getColor(Qt::black, this, tr("Piliiih WarnAAAAAAAAAAAaa"));
  if (color.isValid()) {
    textEdit->setTextColor(color);
  }
}
