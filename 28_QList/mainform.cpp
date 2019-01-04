#include "mainform.h"
#include <QHBoxLayout>
#include <QVBoxLayout>

MainForm::MainForm(QWidget *parent) : QWidget(parent) {
  this->setupUI();
}

MainForm::~MainForm() {
  delete label;
  delete itemEdit;
  delete addItemButton;
  delete list1;
  delete moveRightButton;
  delete moveRightAllButton;
  delete moveLeftButton;
  delete moveLeftAllButton;
  delete list2;
}

void MainForm::setupUI() {
  this->resize(400, 300);
  this->move(400, 200);
  this->setWindowTitle("QListWidget");

  label = new QLabel("&Elemen baru");

  itemEdit = new QLineEdit();
  label->setBuddy(itemEdit);

  addItemButton = new QPushButton("Tambah");

  QHBoxLayout *hbox1 = new QHBoxLayout();
  hbox1->addWidget(itemEdit);
  hbox1->addWidget(addItemButton);
  hbox1->addStretch();

  list1 = new QListWidget();

  moveRightButton = new QPushButton(">");
  moveRightAllButton = new QPushButton(">>");
  moveLeftButton = new QPushButton("<");
  moveLeftAllButton = new QPushButton("<<");

  QVBoxLayout *vbox = new QVBoxLayout();
  vbox->addWidget(moveRightButton);
  vbox->addWidget(moveRightAllButton);
  vbox->addWidget(moveLeftButton);
  vbox->addWidget(moveLeftAllButton);
  vbox->addStretch();   // coba pakai addStretch dan tanpa addStretch

  list2 = new QListWidget();

  QHBoxLayout *hbox2 = new QHBoxLayout();
  hbox2->addWidget(list1);
  hbox2->addLayout(vbox);
  hbox2->addWidget(list2);

  QVBoxLayout *layout = new QVBoxLayout();
  layout->addWidget(label);
  layout->addLayout(hbox1);
  layout->addLayout(hbox2);

  this->setLayout(layout);

  list1->setSortingEnabled(true);   // ini supaya di list 1 apa yang di masukan dapat di urutkan sesuai abjad atau angka,
                                    // kalau ga mau di urutkan tingga kasil bool false, atau hapus aja programnya

  connect(addItemButton, SIGNAL(clicked()), this, SLOT(on_addItemButton_clicked()));
  connect(moveRightButton, SIGNAL(clicked()), this, SLOT(on_moveRightButton_clicked()));
  connect(moveRightAllButton, SIGNAL(clicked()), this, SLOT(on_moveRightAllButton_clicked()));
  connect(moveLeftButton, SIGNAL(clicked()), this, SLOT(on_moveLeftButton_clicked()));
  connect(moveLeftAllButton, SIGNAL(clicked()), this, SLOT(on_moveLeftAllButton_clicked()));
}

void MainForm::on_addItemButton_clicked() {
  if (itemEdit->text().size() == 0) return;
  QString itemLabel = itemEdit->text();
  list1->addItem(itemLabel);
  itemEdit->clear();
  itemEdit->setFocus();
}

void MainForm::on_moveRightButton_clicked() {
  if (list1->currentRow() < 0) return;
  list2->addItem(list1->currentItem()->text());   // ini buat menambahkan item di list2 dari list 1
  list1->takeItem(list1->currentRow());           // ini untuk mangambil item yang ada di list1 (kaya semacam menghilangkan)
}

void MainForm::on_moveRightAllButton_clicked() {
  for (int i = 0; i < list1->count(); i++) {
    list2->addItem(list1->item(i)->text());
  }
  list1->clear();
}

void MainForm::on_moveLeftButton_clicked() {
  if (list2->currentRow() < 0) return;
  list1->addItem(list2->currentItem()->text());
  list2->takeItem(list2->currentRow());
}

void MainForm::on_moveLeftAllButton_clicked() {
  for (int i = 0; i < list2->count(); i++) {
    list1->addItem(list2->item(i)->text());
  }
  list2->clear();
}
