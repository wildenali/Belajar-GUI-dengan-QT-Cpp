#include "mainform.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QModelIndex>
#include <QInputDialog>
#include <QDir>

using namespace std;

MainForm::MainForm(QWidget *parent) : QWidget(parent) {
  // membuat objek dari kelas QDirModel
  model = new QDirModel();
  model->setReadOnly(false);
  model->setSorting(QDir::DirsFirst | QDir::IgnoreCase | QDir::Name);

  this->setupUI();
}

MainForm::~MainForm() {
  delete model;

  delete treeView;
  delete createButton;
  delete removeButton;

}

void MainForm::setupUI() {
  this->resize(600, 350);
  this->move(500, 100);
  this->setWindowTitle("QDirModel");

  treeView = new QTreeView();
  treeView->setModel(model);

  // Contoh mengaktifkan direktori tertentu
  QModelIndex index = model->index("/home/password-sari/Documents");
  treeView->expand(index);
  treeView->scrollTo(index);
  treeView->setCurrentIndex(index);
  treeView->resizeColumnToContents(0);

  createButton = new QPushButton("Buat Direktori");
  removeButton = new QPushButton("Hapus");

  QHBoxLayout *hbox = new QHBoxLayout();
  hbox->addStretch();
  hbox->addWidget(createButton);
  hbox->addWidget(removeButton);

  QVBoxLayout *layout = new QVBoxLayout();
  layout->addWidget(treeView);
  layout->addLayout(hbox);

  this->setLayout(layout);

  connect(createButton, SIGNAL(clicked()), this, SLOT(on_createButton_clicked()));
  connect(removeButton, SIGNAL(clicked()), this, SLOT(on_removeButton_clicked()));
}

void MainForm::on_createButton_clicked() {
  QModelIndex index = treeView->currentIndex();
  if (!index.isValid()) return;;

  QString newDirName = QInputDialog::getText(this, "Membuat Direktori", "Masukan nama direktori yang akan dibuat:");

  if (newDirName.trimmed().size() == 0) return;

  model->mkdir(index, newDirName);
}

void MainForm::on_removeButton_clicked() {
  QModelIndex index = treeView->currentIndex();
  if (!index.isValid()) return;

  if (model->fileInfo(index).isDir()) {
    model->rmdir(index);
  } else {
    model->remove(index);
  }
}
