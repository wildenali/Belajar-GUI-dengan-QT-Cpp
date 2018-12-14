#include "mainform.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QDialog>
#include <QStringList>

MainForm::MainForm(QWidget *parent) : QWidget(parent) {
  this->setupUI();
}

MainForm::~MainForm() {
  delete contactList;
  delete addButton;
  delete editButton;
  delete deleteButton;
  delete clearButton;
  delete exitButton;
}

void MainForm::setupUI() {
  this->resize(450,350);
  this->move(500,200);
  this->setWindowTitle("Phonebook Manager");

  addButton = new QPushButton("Tambah");
  editButton = new QPushButton("Ubah");
  deleteButton = new QPushButton("Hapus");
  clearButton = new QPushButton("Kosongkan");
  exitButton = new QPushButton("Keluar");

  QHBoxLayout *hbox = new QHBoxLayout();
  hbox->addWidget(addButton);
  hbox->addWidget(editButton);
  hbox->addWidget(deleteButton);
  hbox->addWidget(clearButton);
  hbox->addWidget(exitButton);

  contactList = new QListWidget();

  QVBoxLayout *layout = new QVBoxLayout();
  layout->addWidget(contactList);
  layout->addLayout(hbox);

  this->setLayout(layout);

  connect(addButton, SIGNAL(clicked()), this, SLOT(on_addButton_clicked()));
  connect(editButton, SIGNAL(clicked()), this, SLOT(on_editButton_clicked()));
  connect(deleteButton, SIGNAL(clicked()), this, SLOT(on_deleteButton_clicked()));
  connect(clearButton, SIGNAL(clicked()), this, SLOT(clear()));
  connect(exitButton, SIGNAL(clicked()), this, SLOT(close()));
}

void MainForm::on_addButton_clicked() {
  EntryForm *entryForm = new EntryForm();
  if (entryForm->exec() == QDialog::Accepted) {
    contactList->addItem(entryForm->getName() + " - " + entryForm->getPhoneNumber());
  }
}

void MainForm::on_editButton_clicked() {
  if (contactList->currentRow() < 0) return;
  EntryForm *entryForm = new EntryForm();
  QString s = contactList->currentItem()->text();
  QStringList list = s.split(" - ");
  entryForm->setName(list.at(0));
  entryForm->setPhoneNumber(list.at(1));
  if (entryForm->exec() == QDialog::Accepted) {
    contactList->currentItem()->setText(entryForm->getName() + " - " + entryForm->getPhoneNumber());
  }
}

void MainForm::on_deleteButton_clicked() {
  int row = contactList->currentRow();
  if (row >= 0) {
    contactList->takeItem(row);
  }
}
