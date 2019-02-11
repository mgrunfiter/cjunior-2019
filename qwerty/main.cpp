#include "mainwindow.h"
#include <QApplication>
#include <QWidget>
#include <QLabel>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

//    QLabel label("sdgbsb");
//    w.setCentralWidget(&label);

    w.show();

    return a.exec();
}
