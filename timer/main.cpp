#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    QTimer *close_pr = new QTimer;
    close_pr->setInterval(5000);
    close_pr->setSingleShot(true);

    QObject::connect(close_pr, &QTimer::timeout, &w, &MainWindow::close);
    close_pr->start();

    return a.exec();
}
