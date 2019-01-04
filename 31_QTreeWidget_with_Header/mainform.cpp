#include "mainform.h"
#include <QVBoxLayout>
#include <QStringList>
#include <QTreeWidgetItem>

MainForm::MainForm(QWidget *parent) : QWidget(parent) {
  this->setupUI();
}

MainForm::~MainForm() {
  delete treeWidget;
  delete lineEdit;
}

void MainForm::setupUI() {
  this->resize(800, 350);
  this->move(300, 200);
  this->setWindowTitle("QTreeWidget with Header");

  treeWidget = new QTreeWidget();
  treeWidget->setColumnCount(3);

  QStringList headers;
  headers.append("Judul Buku");
  headers.append("Penulis");
  headers.append("Penerbit");

  treeWidget->setHeaderLabels(headers);

  QTreeWidgetItem *parent1 = addTopLevel("C++");
  addChild(parent1,
            "Data Structure and Algorithm Analysis in C++",
            "Mark Allen Weis",
            "Pearson Education");
  addChild(parent1,
            "An Introduction to Design Pattern in C++ with Qt 4",
            "Alan Ezust & Paul Ezust",
            "Prentice Hall");

  QTreeWidgetItem *parent2 = addTopLevel("Ruby");
  addChild(parent2,
            "Ruby Under a Microscope",
            "Pat Shaughnessy",
            "No Starch Press");
  addChild(parent2,
            "Beginning Ruby",
            "Peter Cooper",
            "Apress");

  QTreeWidgetItem *parent3 = addTopLevel("Python");
  addChild(parent3,
            "Numerical Python",
            "Robert Johansson",
            "Apress");
  addChild(parent3,
            "A Primer Scientific Programming with Python",
            "Hans Peter Langtangen",
            "Springer");

  addChild(parent3,
            "Python 3 Object Oriented Programming",
            "Dusty Philips",
            "PACKT Publishing");

  lineEdit = new QLineEdit();

  QVBoxLayout *layout = new QVBoxLayout();
  layout->addWidget(treeWidget);
  layout->addWidget(lineEdit);

  this->setLayout(layout);

  connect(treeWidget, SIGNAL(itemClicked(QTreeWidgetItem*, int)), this, SLOT(on_treeWidget_itemClicked()));
}

void MainForm::on_treeWidget_itemClicked() {
  QTreeWidgetItem *item = treeWidget->currentItem();
  lineEdit->setText(item->text(0) + ", " + item->text(1) + ", " + item->text(2));
}

QTreeWidgetItem* MainForm::addTopLevel(QString category) {
  QTreeWidgetItem *item = new QTreeWidgetItem();
  item->setText(0, category);
  treeWidget->addTopLevelItem(item);
  return item;
}

QTreeWidgetItem* MainForm::addChild(QTreeWidgetItem *parent, QString title, QString author, QString publisher) {
  QTreeWidgetItem *item = new QTreeWidgetItem(parent);
  item->setText(0, title);
  item->setText(1, author);
  item->setText(2, publisher);
  parent->addChild(item);
  return item;
}
