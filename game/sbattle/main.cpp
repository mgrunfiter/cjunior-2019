#include "mainwindow.h"
#include <stdlib.h>
#include <QtGui>
#include <QtCore>
#include <QApplication>
#include <QMessageBox>


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow w;

    w.show();

    return app.exec();
}
