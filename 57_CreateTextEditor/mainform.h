#ifndef MAINFORM_H
#define MAINFORM_H

#include <QWidget>
#include <QMainWindow>
#include <QStatusBar>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QToolBar>
#include <QToolButton>
#include <QTextEdit>

const QString PROGRAM_NAME = "Qt Text Editooor";

class MainForm: public QMainWindow{
  Q_OBJECT
private:
  QString currentFileName;
  QMenu *fileMenu;
  QAction *fileNewAction;
  QAction *fileOpenAction;
  QAction *fileSaveAction;
  QAction *fileSaveAsAction;
  QAction *fileExitAction;
  QMenu *editMenu;
  QAction *editCutAction;
  QAction *editCopyAction;
  QAction *editPasteAction;
  QMenu *formatMenu;
  QAction *formatFontAction;
  QToolBar *toolBar;
  QTextEdit *textEdit;
  void confirmation();
  void writeToFile();

private slots:
  void on_fileNewAction_triggered();
  void on_fileOpenAction_triggered();
  void on_fileSaveAction_triggered();
  void on_fileSaveAsAction_triggered();
  void on_fileExitAction_triggered();
  void on_editCutAction_triggered();
  void on_editCopyAction_triggered();
  void on_editPasteAction_triggered();
  void on_formatFontAction_triggered();

public:
  explicit MainForm(QWidget *parent);
  ~MainForm();
  void setupUI();
};

#endif
