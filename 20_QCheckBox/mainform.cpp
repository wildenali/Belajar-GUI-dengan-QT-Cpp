#include "mainform.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QMessageBox>

MainForm::MainForm(QWidget *parent) : QWidget(parent) {
  this->setupUI();
}

MainForm::~MainForm() {
  delete label;
  delete pythonCheck;
  delete cppCheck;
  delete javaCheck;
  delete golangCheck;
  delete horizontalLine;
  delete okButton;
  delete closeButton;
}

void MainForm::setupUI() {
  this->resize(300,100);
  this->move(500,200);
  this->setWindowTitle("QCheckBox");

  label = new QLabel();
  label->setText("Pilih dulu coy");

  pythonCheck = new QCheckBox();
  pythonCheck->setText("Python");
  cppCheck = new QCheckBox();
  cppCheck->setText("C++");
  javaCheck = new QCheckBox();
  javaCheck->setText("Java");
  golangCheck = new QCheckBox();
  golangCheck->setText("Go");

  QHBoxLayout *hbox1 = new QHBoxLayout();
  hbox1->addWidget(pythonCheck);
  hbox1->addWidget(cppCheck);
  hbox1->addWidget(javaCheck);
  hbox1->addWidget(golangCheck);

  horizontalLine = new QFrame();
  horizontalLine->setFrameShape(QFrame::HLine);
  horizontalLine->setFrameShadow(QFrame::Sunken);
  okButton = new QPushButton("&Ok");
  closeButton = new QPushButton("&Keluar");

  QHBoxLayout *hbox2 = new QHBoxLayout();
  hbox2->addStretch();
  hbox2->addWidget(okButton);
  hbox2->addWidget(closeButton);

  QVBoxLayout *layout = new QVBoxLayout();
  layout->addWidget(label);
  layout->addLayout(hbox1);
  layout->addWidget(horizontalLine);
  layout->addLayout(hbox2);
  layout->addStretch();

  this->setLayout(layout);

  connect(okButton, SIGNAL(clicked()), this, SLOT(on_okButton_clicked()));
  connect(closeButton, SIGNAL(clicked()), this, SLOT(close()));
}

QString MainForm::repr(QStringList aList) {
  QString s = "[";
  for (int i = 0; i < aList.size(); i++) {
    s += "'"+ aList.at(i) + "'";
    if (i != aList.size()-1) {
      s += ", ";
    }
  }
  s += "]";
  return s;
}


void MainForm::on_okButton_clicked() {
  QStringList choices;
  if (pythonCheck->isChecked()) {
    choices.append(pythonCheck->text());
  }
  if (cppCheck->isChecked()) {
    choices.append(cppCheck->text());
  }
  if (javaCheck->isChecked()) {
    choices.append(javaCheck->text());
  }
  if (golangCheck->isChecked()) {
    choices.append(golangCheck->text());
  }

  QMessageBox::information(this, "Informasi", repr(choices));
}
