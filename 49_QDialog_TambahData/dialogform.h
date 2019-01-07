#ifndef DIALOGFORM_H
#define DIALOGFORM_H

#include <QWidget>
#include <QDialog>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>

class DialogForm: public QDialog {
  Q_OBJECT
private:
  QLabel *label1;
  QPushButton *okButton;
  QPushButton *cancelButton;
  QLineEdit *languageEdit;
  QLabel *label2;
  QLineEdit *nameEdit;

public:
  explicit DialogForm(QWidget *parent);
  ~DialogForm();
  void setupUI();
  QString getLanguage();
  QString getName();
};

#endif
