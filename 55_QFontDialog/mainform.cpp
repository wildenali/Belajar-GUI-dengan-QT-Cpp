#include "mainform.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QFontDialog>

MainForm::MainForm(QWidget *parent) : QWidget(parent) {
  this->setupUI();
}

MainForm::~MainForm() {
  delete textEdit;
  delete fontButton;
}

void MainForm::setupUI() {
  this->resize(300, 250);
  this->move(500, 250);
  this->setWindowTitle("QFontDialog");

  textEdit = new QTextEdit();
  fontButton = new QPushButton("Pilih Font");

  QHBoxLayout *hbox = new QHBoxLayout();
  hbox->addWidget(fontButton);
  hbox->addStretch();

  QVBoxLayout *layout = new QVBoxLayout();
  layout->addWidget(textEdit);
  layout->addLayout(hbox);

  this->setLayout(layout);

  connect(fontButton, SIGNAL(clicked()), this, SLOT(on_fontButton_clicked()));
}

void MainForm::on_fontButton_clicked() {
  bool ok;
  QFont font;
  font = QFontDialog::getFont(&ok, QFont("Sans Serif", 11), this, tr("Piliiih font"));
  if (ok) {
    textEdit->setCurrentFont(font);
  }
}
