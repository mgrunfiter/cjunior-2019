/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *pbConnect;
    QLineEdit *leIP;
    QPlainTextEdit *pteText;
    QLineEdit *leMsg;
    QPushButton *pbSend;
    QCheckBox *cbServer;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(400, 300);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        pbConnect = new QPushButton(centralWidget);
        pbConnect->setObjectName(QStringLiteral("pbConnect"));
        pbConnect->setGeometry(QRect(310, 20, 80, 23));
        leIP = new QLineEdit(centralWidget);
        leIP->setObjectName(QStringLiteral("leIP"));
        leIP->setGeometry(QRect(180, 20, 113, 23));
        pteText = new QPlainTextEdit(centralWidget);
        pteText->setObjectName(QStringLiteral("pteText"));
        pteText->setGeometry(QRect(10, 100, 381, 151));
        leMsg = new QLineEdit(centralWidget);
        leMsg->setObjectName(QStringLiteral("leMsg"));
        leMsg->setGeometry(QRect(10, 60, 291, 23));
        pbSend = new QPushButton(centralWidget);
        pbSend->setObjectName(QStringLiteral("pbSend"));
        pbSend->setGeometry(QRect(310, 60, 80, 23));
        cbServer = new QCheckBox(centralWidget);
        cbServer->setObjectName(QStringLiteral("cbServer"));
        cbServer->setGeometry(QRect(20, 20, 121, 17));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        pbConnect->setText(QApplication::translate("MainWindow", "Connect", nullptr));
        leIP->setPlaceholderText(QApplication::translate("MainWindow", "192.168.15.90", nullptr));
        leMsg->setPlaceholderText(QApplication::translate("MainWindow", "Hello!", nullptr));
        pbSend->setText(QApplication::translate("MainWindow", "Send msg", nullptr));
        cbServer->setText(QApplication::translate("MainWindow", "Start server", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
