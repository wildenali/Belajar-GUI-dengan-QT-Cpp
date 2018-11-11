#include "mainform.h"
#include <QToolTip>
#include <QFont>

MainForm::MainForm(QWidget *parent) : QWidget(parent) {
  this -> setupUI();
}

MainForm::~MainForm() {
  delete closeButton;
}

void MainForm::setupUI() {
  this->resize(600,300);
  this->move(300,300);
  this->setWindowTitle("Testing ToolTip atau Mouse Hover");

  QToolTip::setFont(QFont("SansSerif", 10));
  this->setToolTip(tr("toooool tiiiiip <i>dimiring miring</i>") + tr("<b>hahahaaaa</b>"));

  closeButton = new QPushButton("Keluar");
  closeButton->move(50,50);
  closeButton->setParent(this);
  closeButton->setToolTip(tr("ini adalah tooooooool ool tiiip") + tr("<b>TombOOOL</b>"));

  connect(closeButton, SIGNAL(clicked()), this, SLOT(on_closeButton_clicked()));
}

void MainForm::on_closeButton_clicked() {
  this->close();
}
