#include "mainform.h"
#include "dialogform.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QMessageBox>

MainForm::MainForm(QWidget *parent) : QWidget(parent) {
  this->setupUI();
}

MainForm::~MainForm() {
  delete label;
  delete showDialogButton;
}

void MainForm::setupUI() {
  this->resize(350, 100);
  this->move(500, 250);
  this->setWindowTitle("QDialog::accept() dan QDialog::reject()");

  label=new QLabel("Form Utama");
  showDialogButton = new QPushButton("Tampilkan Dialog");

  QVBoxLayout *layout = new QVBoxLayout();
  layout->addWidget(label);
  layout->addWidget(showDialogButton);

  this->setLayout(layout);

  connect(showDialogButton, SIGNAL(clicked()), this, SLOT(on_showDialogButton_clicked()));
}

void MainForm::on_showDialogButton_clicked() {
  DialogForm *form = new DialogForm(this);
  if (form->exec() == QDialog::Accepted) {
    QMessageBox::information(this, "Informasi", "Anda Memilih tombol OK");
  } else {
    QMessageBox::information(this, "Informasi", "Anda Memilih tombol Cancel");
  }
}
