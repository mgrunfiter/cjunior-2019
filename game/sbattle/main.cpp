#include "mainwindow.h"
#include <QApplication>
#include "battleserver.h"
#include <QUdpSocket>
#include <QTcpServer>
#include <QTcpSocket>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    QTcpServer server();

    w.show();

    return a.exec();
}
