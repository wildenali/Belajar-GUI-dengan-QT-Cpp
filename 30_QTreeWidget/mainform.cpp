#include "mainform.h"
#include <QVBoxLayout>
#include <QTreeWidgetItem>

MainForm::MainForm(QWidget *parent) : QWidget(parent) {
  this->setupUI();
}

MainForm::~MainForm() {
  delete treeWidget;
  delete lineEdit;
}

void MainForm::setupUI() {
  this->resize(300, 350);
  this->move(500, 200);
  this->setWindowTitle("QTreeWidget");

  treeWidget = new QTreeWidget();
  treeWidget->setColumnCount(1);
  treeWidget->setHeaderHidden(true);

  QTreeWidgetItem *parent1 = addTopLevel("Induk 1");
  QTreeWidgetItem *child1 = addChild(parent1, "Anak 1-1");
  addChild(child1, "Cucu 1-1-1");
  addChild(child1, "Cucu 1-1-2");
  addChild(parent1, "Anak 1-2");
  addChild(parent1, "Anak 1-3");

  QTreeWidgetItem *parent2 = addTopLevel("Induk 2");
  addChild(parent2, "Anak 2-1");
  addChild(parent2, "Anak 2-2");

  QTreeWidgetItem *parent3 = addTopLevel("Induk 3");
  addChild(parent3, "Anak 3-1");
  addChild(parent3, "Anak 3-2");
  addChild(parent3, "Anak 3-3");
  addChild(parent3, "Anak 3-4");

  lineEdit = new QLineEdit();

  QVBoxLayout *layout = new QVBoxLayout();
  layout->addWidget(treeWidget);
  layout->addWidget(lineEdit);

  this->setLayout(layout);

  connect(treeWidget, SIGNAL(itemClicked(QTreeWidgetItem*, int)), this, SLOT(on_treeWidget_itemClicked()));
}

void MainForm::on_treeWidget_itemClicked() {
  QTreeWidgetItem *item = treeWidget->currentItem();
  lineEdit->setText(item->text(0));
}

QTreeWidgetItem* MainForm::addTopLevel(QString itemText) {
  QTreeWidgetItem *item = new QTreeWidgetItem();
  item->setText(0, itemText);
  treeWidget->addTopLevelItem(item);
  return item;
}

QTreeWidgetItem* MainForm::addChild(QTreeWidgetItem *parent, QString itemText) {
  QTreeWidgetItem *item = new QTreeWidgetItem(parent);
  item->setText(0, itemText);
  parent->addChild(item);
  return item;
}
