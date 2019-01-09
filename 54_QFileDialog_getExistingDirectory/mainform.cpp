#include "mainform.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QFileDialog>
#include <QDir>

MainForm::MainForm(QWidget *parent) : QWidget(parent) {
  model = new QFileSystemModel();
  this->setupUI();
}

MainForm::~MainForm() {
  delete model;
  delete lineEdit;
  delete dirButton;
  delete treeView;
}

void MainForm::setupUI() {
  this->resize(500, 450);
  this->move(450, 150);
  this->setWindowTitle("Cara Mengambil Folder/Directory");

  lineEdit = new QLineEdit();
  dirButton = new QPushButton("Pilih Directory");

  QHBoxLayout *hbox = new QHBoxLayout();
  hbox->addWidget(lineEdit);
  hbox->addWidget(dirButton);

  treeView = new QTreeView();

  QVBoxLayout *layout = new QVBoxLayout();
  layout->addLayout(hbox);
  layout->addWidget(treeView);

  this->setLayout(layout);

  connect(dirButton, SIGNAL(clicked()), this, SLOT(on_dirButton_clicked()));
}

void MainForm::on_dirButton_clicked() {
  QString path;
  path = QFileDialog::getExistingDirectory(this, tr("Pilih Folder"), tr("/home/password-sari/"), QFileDialog::ShowDirsOnly);
  if (path.trimmed().size() == 0) return;
  lineEdit->setText(path);

  model->setRootPath(path);
  model->setFilter(QDir::AllDirs | QDir::Files);
  treeView->setModel(model);
  treeView->setRootIndex(model->index(path));
}
