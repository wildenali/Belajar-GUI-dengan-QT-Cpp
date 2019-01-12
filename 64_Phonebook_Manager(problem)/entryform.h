#ifndef ENTRYFORM_H
#define ENTRYFORM_H

#include <QDialog>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

class EntryForm: public QDialog{
  Q_OBJECT
private:
  QLabel *label1;
  QLineEdit *nameLineEdit;
  QLabel *label2;
  QLineEdit *phoneLineEdit;
  QPushButton *okButton;
  QPushButton *cancelButton;

public:
  EntryForm();
  ~EntryForm();
  void setupUI();
  void setName(QString name);
  QString getName();
  void setPhoneNumber(QString phoneNumber);
  QString getPhoneNumber();
};

#endif
