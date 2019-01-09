#ifndef MAINFORM_H
#define MAINFORM_H

#include <QWidget>
#include <QPushButton>

class MainForm: public QWidget{
  Q_OBJECT
private:
  QPushButton *aboutButton;
  QPushButton *critialButton;
  QPushButton *informationButton;
  QPushButton *questionButton;
  QPushButton *warningButton;

private slots:
  void on_aboutButton_clicked();
  void on_criticalButton_clicked();
  void on_informationButton_clicked();
  void on_questionButton_clicked();
  void on_warningButton_clicked();

public:
  explicit MainForm(QWidget *parent);
  ~MainForm();
  void setupUI();
};

#endif
