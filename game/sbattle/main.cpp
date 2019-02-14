#include "mainwindow.h"
#include <stdlib.h>
#include <QtGui>
#include <QtCore>
#include <QtNetwork>
#include <QApplication>
#include <QTcpServer>
#include <QTcpSocket>
#include <QMessageBox>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    QTcpServer *tcpServer = new QTcpServer();
    qDebug() << tcpServer->serverPort();

    QString ipAddress;
    QList<QHostAddress> ipAddressesList = QNetworkInterface::allAddresses();

    // используем первый не локальный адрес IPv4
    for (int i = 0; i < ipAddressesList.size(); ++i) {
        if (ipAddressesList.at(i) != QHostAddress::LocalHost &&
            ipAddressesList.at(i).toIPv4Address()) {
            ipAddress = ipAddressesList.at(i).toString();
            if (!tcpServer->listen(ipAddressesList.at(i), 35135)) {
                QMessageBox::critical(NULL, QObject::tr("Fortune Server"),
                                      QObject::tr("Unable to start the server: %1.")
                                      .arg(tcpServer->errorString()));
                qDebug() << "Can't start listen on port " << tcpServer->serverPort();
                return 1;
            }
            else {
                qDebug() << "Start listen on port " << tcpServer->serverPort();
//                QMessageBox::information(NULL, QObject::tr("SBattle Server"),
//                                      QObject::tr("Start the server: %1.")
//                                      .arg(tcpServer->errorString()));
            }
            break;
        }
    }

    w.show();

    return a.exec();
}
