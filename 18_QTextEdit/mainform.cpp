#include "mainform.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QMessageBox>

MainForm::MainForm(QWidget *parent) : QWidget(parent) {
  this->setupUI();
}

MainForm::~MainForm() {
  delete label1;
  delete nameLineEdit;
  delete label2;
  delete commentTextEdit;
  delete horizontalLine;
  delete getTextButton;
  delete exitButton;
}

void MainForm::setupUI() {
  this->resize(400,200);
  this->move(500,200);
  this->setWindowTitle("QTextEdit");

  label1 = new QLabel();
  label1->setText("Nama");

  nameLineEdit = new QLineEdit();

  label2 = new QLabel();
  label2->setText("Komentar");

  commentTextEdit = new QTextEdit();

  getTextButton = new QPushButton("Ambil Tekss");
  exitButton = new QPushButton("Keluar");

  horizontalLine = new QFrame();
  horizontalLine->setFrameShape(QFrame::HLine);
  horizontalLine->setFrameShadow(QFrame::Sunken);

  QHBoxLayout *hbox = new QHBoxLayout();
  hbox->addStretch();
  hbox->addWidget(getTextButton);
  hbox->addWidget(exitButton);

  QVBoxLayout *layout = new QVBoxLayout();
  layout->addWidget(label1);
  layout->addWidget(nameLineEdit);
  layout->addWidget(label2);
  layout->addWidget(commentTextEdit);
  layout->addStretch();
  layout->addWidget(horizontalLine);
  layout->addLayout(hbox);

  this->setLayout(layout);

  connect(getTextButton, SIGNAL(clicked()), this, SLOT(on_getTextButton_clicked()));
  connect(exitButton, SIGNAL(clicked()), this, SLOT(close()));
}

void MainForm::on_getTextButton_clicked() {
  QString name = nameLineEdit->text();
  QString comment = commentTextEdit->document()->toPlainText();
  QMessageBox::about(this, "Data yang di masukan", "<b>" + name + "</b><br><br>" + comment);
}
