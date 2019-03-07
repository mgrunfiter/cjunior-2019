/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *pushButton;
    QCustomPlot *widget;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QCustomPlot *widget_2;
    QPushButton *pushButton_6;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *leX_1;
    QLineEdit *leY_1;
    QLabel *label_3;
    QLineEdit *leX_2;
    QLineEdit *leY_2;
    QLabel *label_4;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(667, 334);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(10, 0, 80, 23));
        widget = new QCustomPlot(centralWidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(20, 40, 301, 201));
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(100, 0, 80, 23));
        pushButton_3 = new QPushButton(centralWidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(190, 0, 80, 23));
        pushButton_4 = new QPushButton(centralWidget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(280, 0, 80, 23));
        pushButton_5 = new QPushButton(centralWidget);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(300, 250, 80, 23));
        widget_2 = new QCustomPlot(centralWidget);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setGeometry(QRect(350, 60, 301, 181));
        pushButton_6 = new QPushButton(centralWidget);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setGeometry(QRect(580, 0, 80, 23));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(379, 2, 21, 20));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(470, 3, 21, 20));
        leX_1 = new QLineEdit(centralWidget);
        leX_1->setObjectName(QString::fromUtf8("leX_1"));
        leX_1->setGeometry(QRect(390, 0, 71, 23));
        leY_1 = new QLineEdit(centralWidget);
        leY_1->setObjectName(QString::fromUtf8("leY_1"));
        leY_1->setGeometry(QRect(490, 0, 71, 23));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(470, 31, 21, 20));
        leX_2 = new QLineEdit(centralWidget);
        leX_2->setObjectName(QString::fromUtf8("leX_2"));
        leX_2->setGeometry(QRect(390, 28, 71, 23));
        leY_2 = new QLineEdit(centralWidget);
        leY_2->setObjectName(QString::fromUtf8("leY_2"));
        leY_2->setGeometry(QRect(490, 28, 71, 23));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(379, 30, 21, 20));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 667, 20));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButton->setText(QApplication::translate("MainWindow", "1 \320\277\321\200\320\270\320\274\320\265\321\200", nullptr));
        pushButton_2->setText(QApplication::translate("MainWindow", "2 \320\277\321\200\320\270\320\274\320\265\321\200", nullptr));
        pushButton_3->setText(QApplication::translate("MainWindow", "3 \320\277\321\200\320\270\320\274\320\265\321\200", nullptr));
        pushButton_4->setText(QApplication::translate("MainWindow", "4 \320\277\321\200\320\270\320\274\320\265\321\200", nullptr));
        pushButton_5->setText(QApplication::translate("MainWindow", "\320\236\321\207\320\270\321\201\321\202\320\270\321\202\321\214", nullptr));
        pushButton_6->setText(QApplication::translate("MainWindow", "Go!", nullptr));
        label->setText(QApplication::translate("MainWindow", "X:", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "Y:", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "Y:", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "X:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
