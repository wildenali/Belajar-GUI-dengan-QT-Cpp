#include "mainform.h"
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QIODevice>
#include <QFileDialog>
#include <QFontDialog>
#include <QDir>

MainForm::MainForm(QWidget *parent) : QMainWindow(parent) {
  currentFileName = "";
  this->setupUI();
}

MainForm::~MainForm() {
  delete fileMenu;
  delete fileNewAction;
  delete fileOpenAction;
  delete fileSaveAction;
  delete fileSaveAsAction;
  delete fileExitAction;
  delete editMenu;
  delete editCutAction;
  delete editCopyAction;
  delete editPasteAction;
  delete formatMenu;
  delete formatFontAction;
  delete toolBar;
  delete textEdit;
}

void MainForm::setupUI() {
  this->resize(550, 450);
  this->move(450, 150);
  this->setWindowTitle(PROGRAM_NAME + tr(" - Untitled"));

  // inisialisasi teks pada statusbar
  this->statusBar()->showMessage("Ketikkan teks yang Anda inginkan");

  // mendapatkan objek menubar
  // menubar = this->menuBar();

  // membuat menu file dan menempatkannya ke dalam menubar
  fileMenu = this->menuBar()->addMenu("&File");

// membuat aksi untuk menu file
  // New File
  fileNewAction = new QAction(QIcon("icons/New.png"), "&New", this);
  fileNewAction->setShortcut(QKeySequence("Ctrl+N"));
  fileNewAction->setStatusTip("Buat teks baru");
  connect(fileNewAction, SIGNAL(triggered(bool)), this, SLOT(on_fileNewAction_triggered()));
  fileMenu->addAction(fileNewAction);

  // Open File
  fileOpenAction = new QAction(QIcon("icons/Open.png"), "&Open", this);
  fileOpenAction->setShortcut(QKeySequence("Ctrl+O"));
  fileOpenAction->setStatusTip("Buka File");
  connect(fileOpenAction, SIGNAL(triggered(bool)), this, SLOT(on_fileOpenAction_triggered()));
  fileMenu->addAction(fileOpenAction);

  fileMenu->addSeparator();

  // Save File
  fileSaveAction = new QAction(QIcon("icons/Save.png"), "&Save", this);
  fileSaveAction->setShortcut(QKeySequence("Ctrl+S"));
  fileSaveAction->setStatusTip("Simpan File");
  connect(fileSaveAction, SIGNAL(triggered(bool)), this, SLOT(on_fileSaveAction_triggered()));
  fileMenu->addAction(fileSaveAction);

  // Save File
  fileSaveAsAction = new QAction(QIcon("icons/Save.png"), "Save &As...", this);
  fileSaveAsAction->setStatusTip("Simpan File Baru");
  connect(fileSaveAsAction, SIGNAL(triggered(bool)), this, SLOT(on_fileSaveAsAction_triggered()));
  fileMenu->addAction(fileSaveAsAction);

  fileMenu->addSeparator();

  // Exit File
  fileExitAction = new QAction(QIcon("icons/Exit.png"), "&Exit", this);
  fileExitAction->setShortcut(QKeySequence("Ctrl+Q"));
  fileExitAction->setStatusTip("Keluar");
  connect(fileExitAction, SIGNAL(triggered(bool)), this, SLOT(on_fileExitAction_triggered()));
  fileMenu->addAction(fileExitAction);

  // membuat manu Edit dan menempatkannya ke dalam menubar
  editMenu = this->menuBar()->addMenu("&Edit");

  // Cut File
  editCutAction = new QAction(QIcon("icons/Cut.png"), "C&ut", this);
  editCutAction->setShortcut(QKeySequence("Ctrl+X"));
  editCutAction->setStatusTip("Potong Text");
  connect(editCutAction, SIGNAL(triggered(bool)), this, SLOT(on_editCutAction_triggered()));
  editMenu->addAction(editCutAction);

  editMenu->addSeparator();

  // Copy File
  editCopyAction = new QAction(QIcon("icons/Copy.png"), "&Copy", this);
  editCopyAction->setShortcut(QKeySequence("Ctrl+C"));
  editCopyAction->setStatusTip("Copy fileee");
  connect(editCopyAction, SIGNAL(triggered(bool)), this, SLOT(on_editCopyAction_triggered()));
  editMenu->addAction(editCopyAction);

  editMenu->addSeparator();

  // Paste File
  editPasteAction = new QAction(QIcon("icons/Paste.png"), "&Paste", this);
  editPasteAction->setShortcut(QKeySequence("Ctrl+V"));
  editPasteAction->setStatusTip("Tempel teks ");
  connect(editPasteAction, SIGNAL(triggered(bool)), this, SLOT(on_editPasteAction_triggered()));
  editMenu->addAction(editPasteAction);

  // membuat menu format dan menempatkannya ke dalam menubar
  formatMenu = this->menuBar()->addMenu("F&ormat");

  // membuat aksi untuk menu Format
  formatFontAction = new QAction(QIcon(""), "F&ont", this);
  formatFontAction->setStatusTip("Menentukan jenis dan ukuran huruf pada teks yang disorot");
  connect(formatFontAction, SIGNAL(triggered(bool)), this, SLOT(on_formatFontAction_triggered()));
  formatMenu->addAction(formatFontAction);

  // membuat toolbar
  toolBar = this->addToolBar("");
  toolBar->addAction(fileNewAction);
  toolBar->addAction(fileOpenAction);
  toolBar->addAction(fileSaveAction);
  toolBar->addSeparator();
  toolBar->addAction(editCutAction);
  toolBar->addAction(editCopyAction);
  toolBar->addAction(editPasteAction);

  // membuat objek QTextEdit dan menempatkannya ke dalam widget
  textEdit = new QTextEdit();
  this->setCentralWidget(textEdit);
}

void MainForm::confirmation() {
  if (textEdit->document()->isModified()) {
    QMessageBox::StandardButton response;
    response = QMessageBox::question(this, "Konfirmasi", "Teks telah dimodifikasi. SIMPAN?");
    if (response == QMessageBox::Yes) {
      on_fileSaveAction_triggered();
    }
  }
}

void MainForm::writeToFile() {
  QFile fileHandle(currentFileName);
  if (!fileHandle.open(QIODevice::WriteOnly)) return;
  QTextStream stream(&fileHandle);
  stream << textEdit->document()->toPlainText();
  stream.flush();
  fileHandle.close();
  textEdit->document()->setModified(false);
}

void MainForm::on_fileNewAction_triggered() {
  confirmation();
  textEdit->document()->clear();
  currentFileName = "";
  setWindowTitle(PROGRAM_NAME + tr(" - Untitled"));
}

void MainForm::on_fileOpenAction_triggered() {
  confirmation();
  currentFileName = QFileDialog::getOpenFileName(
    this, "Pilih file", QDir::currentPath(), "Text File (*.txt)"
  );
  if (currentFileName.trimmed().size() == 0) return;
  this->setWindowTitle(PROGRAM_NAME + tr(" - ") + currentFileName);

  QFile fileHandle(currentFileName);
  if (!fileHandle.open(QIODevice::ReadOnly)) return;
  QTextStream stream(&fileHandle);
  textEdit->setPlainText(stream.readAll());
  fileHandle.close();
}

void MainForm::on_fileSaveAction_triggered() {
  if (currentFileName.trimmed().size() == 0) {
    // mengeksekusi aksi Save As
    on_fileSaveAsAction_triggered();
  } else {
    writeToFile();
  }
}

void MainForm::on_fileSaveAsAction_triggered() {
  currentFileName = QFileDialog::getSaveFileName(
    this, "Simpan file", "", "Text File (*.txt)"
  );
  if (currentFileName.trimmed().size() == 0) return;
  this->setWindowTitle(PROGRAM_NAME + tr(" - ") + currentFileName);
  writeToFile();
}

void MainForm::on_fileExitAction_triggered() {
  this->close();
}

void MainForm::on_editCutAction_triggered() {
  textEdit->cut();
}

void MainForm::on_editCopyAction_triggered() {
  textEdit->copy();
}

void MainForm::on_editPasteAction_triggered() {
  textEdit->paste();
}

void MainForm::on_formatFontAction_triggered() {
  bool ok;
  QFont font;
  font = QFontDialog::getFont(&ok, QFont("Sans Serif", 11), this, "Pilih font");

  if (ok) {
    textEdit->setCurrentFont(font);
  }
}
