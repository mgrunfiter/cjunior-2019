#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w1;
    MainWindow w2;
    w1.setName("w1");
    w2.setName("W2");

    QObject::connect(&w1, &MainWindow::sendMessage, &w2, &MainWindow::getMessage);
    QObject::connect(&w2, &MainWindow::sendMessage, &w1, &MainWindow::getMessage);
//    QObject::connect(&w1, w1.sendMessage, &w2, w2.getMessage);
//    QObject::connect(&w2, w2.sendMessage, &w1, w1.getMessage);

    w1.show();
    w2.show();

    return a.exec();
}
