#ifndef MAINFORM_H
#define MAINFORM_H

#include <QWidget>
#include <QLabel>
#include <QCheckBox>
#include <QFrame>
#include <QPushButton>
#include <QStringList>

class MainForm: public QWidget {
  Q_OBJECT
private:
  QLabel *label;
  QCheckBox *pythonCheck;
  QCheckBox *cppCheck;
  QCheckBox *javaCheck;
  QCheckBox *golangCheck;
  QFrame *horizontalLine;
  QPushButton *okButton;
  QPushButton *closeButton;
  QString repr(QStringList list);

private slots:
  void on_okButton_clicked();

public:
  explicit MainForm(QWidget *parent);
  ~MainForm();
  void setupUI();
};

#endif
