#ifndef MAINFORM_H
#define MAINFORM_H

#include <QWidget>
#include <QGroupBox>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QDir>

class MainForm: public QWidget {
  Q_OBJECT
private:
  QDir *directory;

  QGroupBox *groupBox1;
  QLabel *label1;
  QLineEdit *newDirEdit;
  QPushButton *createButton;

  QGroupBox *groupBox2;
  QLabel *label2;
  QLineEdit *oldDirNameEdit;
  QLabel *label3;
  QLineEdit *newDirNameEdit;
  QPushButton *renameButton;

  QGroupBox *groupBox3;
  QLabel *label4;
  QLineEdit *dirNameEdit;
  QPushButton *removeButton;

private slots:
  void on_createButton_clicked();
  void on_renameButton_clicked();
  void on_removeButton_clicked();

public:
  explicit MainForm(QWidget *parent);
  ~MainForm();
  void setupUI();
};

#endif
