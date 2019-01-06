#include "mainform.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QDir>

using namespace std;

MainForm::MainForm(QWidget *parent) : QWidget(parent) {
  // membuat objek dari kelas QFileSystemModel (untuk direktori)
  dirModel = new QFileSystemModel();
  dirModel->setFilter(QDir::NoDotAndDotDot | QDir::AllDirs);
  dirModel->setRootPath("/");

  // Membuat objek dari kelas QFileSystemModel (untuk file)
  fileModel = new QFileSystemModel();
  fileModel->setFilter(QDir::NoDotAndDotDot | QDir::AllDirs | QDir::Files);

  this->setupUI();
}

MainForm::~MainForm() {
  delete dirModel;
  delete fileModel;

  delete treeView;
  delete listView;
  delete splitter;

}

void MainForm::setupUI() {
  this->resize(600, 350);
  this->move(500, 100);
  this->setWindowTitle("QFileSystemModel");

  treeView = new QTreeView();
  treeView->setModel(dirModel);
  for (int i = 1; i < 4; i++) {
    treeView->hideColumn(i);
  }
  treeView->setColumnWidth(0, 120);
  treeView->setHeaderHidden(true);

  listView = new QListView();
  listView->setModel(fileModel);

  splitter = new QSplitter();
  splitter->setOrientation(Qt::Horizontal);
  splitter->addWidget(treeView);
  splitter->addWidget(listView);

  QHBoxLayout *layout = new QHBoxLayout();
  layout->addWidget(splitter);

  this->setLayout(layout);

  connect(treeView, SIGNAL(clicked(QModelIndex)), this, SLOT(on_treeView_clicked()));
}

void MainForm::on_treeView_clicked() {
    QModelIndex index = treeView->currentIndex();
    QString currentPath = dirModel->fileInfo(index).absoluteFilePath();
    listView->setRootIndex(fileModel->setRootPath(currentPath));
}
