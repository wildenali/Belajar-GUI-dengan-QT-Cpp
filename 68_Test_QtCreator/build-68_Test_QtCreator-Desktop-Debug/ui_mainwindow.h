/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QWidget *widget;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout;
    QLabel *label1;
    QLineEdit *lineEdit1;
    QVBoxLayout *verticalLayout_2;
    QLabel *label1_2;
    QLineEdit *lineEdit1_2;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QWidget *widget1;
    QFormLayout *formLayout;
    QLabel *label1_3;
    QLineEdit *lineEdit1_3;
    QLabel *label1_4;
    QLineEdit *lineEdit1_4;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QSplitter *splitter;
    QPushButton *pushButton_6;
    QPushButton *pushButton_5;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(667, 496);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        widget = new QWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(90, 10, 461, 149));
        verticalLayout_4 = new QVBoxLayout(widget);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label1 = new QLabel(widget);
        label1->setObjectName(QStringLiteral("label1"));

        verticalLayout->addWidget(label1);

        lineEdit1 = new QLineEdit(widget);
        lineEdit1->setObjectName(QStringLiteral("lineEdit1"));

        verticalLayout->addWidget(lineEdit1);


        verticalLayout_3->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label1_2 = new QLabel(widget);
        label1_2->setObjectName(QStringLiteral("label1_2"));

        verticalLayout_2->addWidget(label1_2);

        lineEdit1_2 = new QLineEdit(widget);
        lineEdit1_2->setObjectName(QStringLiteral("lineEdit1_2"));

        verticalLayout_2->addWidget(lineEdit1_2);


        verticalLayout_3->addLayout(verticalLayout_2);


        verticalLayout_4->addLayout(verticalLayout_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(widget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        horizontalLayout->addWidget(pushButton_2);


        verticalLayout_4->addLayout(horizontalLayout);

        widget1 = new QWidget(centralWidget);
        widget1->setObjectName(QStringLiteral("widget1"));
        widget1->setGeometry(QRect(120, 171, 226, 97));
        formLayout = new QFormLayout(widget1);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        label1_3 = new QLabel(widget1);
        label1_3->setObjectName(QStringLiteral("label1_3"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label1_3);

        lineEdit1_3 = new QLineEdit(widget1);
        lineEdit1_3->setObjectName(QStringLiteral("lineEdit1_3"));

        formLayout->setWidget(0, QFormLayout::FieldRole, lineEdit1_3);

        label1_4 = new QLabel(widget1);
        label1_4->setObjectName(QStringLiteral("label1_4"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label1_4);

        lineEdit1_4 = new QLineEdit(widget1);
        lineEdit1_4->setObjectName(QStringLiteral("lineEdit1_4"));

        formLayout->setWidget(1, QFormLayout::FieldRole, lineEdit1_4);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        pushButton_3 = new QPushButton(widget1);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        horizontalLayout_2->addWidget(pushButton_3);

        pushButton_4 = new QPushButton(widget1);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));

        horizontalLayout_2->addWidget(pushButton_4);


        formLayout->setLayout(2, QFormLayout::SpanningRole, horizontalLayout_2);

        splitter = new QSplitter(centralWidget);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setGeometry(QRect(150, 290, 281, 91));
        splitter->setOrientation(Qt::Horizontal);
        pushButton_6 = new QPushButton(splitter);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        splitter->addWidget(pushButton_6);
        pushButton_5 = new QPushButton(splitter);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        splitter->addWidget(pushButton_5);
        MainWindow->setCentralWidget(centralWidget);
        pushButton->raise();
        pushButton_2->raise();
        lineEdit1->raise();
        label1->raise();
        pushButton->raise();
        pushButton_2->raise();
        pushButton_5->raise();
        pushButton_6->raise();
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 667, 25));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);
        QObject::connect(pushButton, SIGNAL(clicked()), lineEdit1, SLOT(clear()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        label1->setText(QApplication::translate("MainWindow", "Nama", 0));
        label1_2->setText(QApplication::translate("MainWindow", "Password", 0));
        pushButton->setText(QApplication::translate("MainWindow", "Login", 0));
        pushButton_2->setText(QApplication::translate("MainWindow", "Exit", 0));
        label1_3->setText(QApplication::translate("MainWindow", "Nama", 0));
        label1_4->setText(QApplication::translate("MainWindow", "Email", 0));
        pushButton_3->setText(QApplication::translate("MainWindow", "Login", 0));
        pushButton_4->setText(QApplication::translate("MainWindow", "Exit", 0));
        pushButton_6->setText(QApplication::translate("MainWindow", "PushButton", 0));
        pushButton_5->setText(QApplication::translate("MainWindow", "PushButton", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
