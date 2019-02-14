#include <QtGui>
#include <QtNetwork>
#include <stdlib.h>
#include <QLabel>
#include <QPushButton>
#include <QMessageBox>
#include <QHBoxLayout>

#include "server.h"

 Server::Server(QWidget *parent)
     : QDialog(parent)
 {
     statusLabel = new QLabel;
     quitButton = new QPushButton(tr("Quit"));
     quitButton->setAutoDefault(false);

     tcpServer = new QTcpServer(this);
     qDebug() << tcpServer->serverPort();
//     if (!tcpServer->listen()) {
//         QMessageBox::critical(this, tr("Fortune Server"),
//                               tr("Unable to start the server: %1.")
//                               .arg(tcpServer->errorString()));
//         close();
//         return;
//     }
     QString ipAddress;
     QList<QHostAddress> ipAddressesList = QNetworkInterface::allAddresses();
     // используем первый не локальный адрес IPv4
     for (int i = 0; i < ipAddressesList.size(); ++i) {
         if (ipAddressesList.at(i) != QHostAddress::LocalHost &&
             ipAddressesList.at(i).toIPv4Address()) {
             ipAddress = ipAddressesList.at(i).toString();
             if (!tcpServer->listen(ipAddressesList.at(i), 35135)) {
                 QMessageBox::critical(this, tr("Fortune Server"),
                                       tr("Unable to start the server: %1.")
                                       .arg(tcpServer->errorString()));
                 close();
                 return;
             }
             break;
         }
     }
     // если мы ни одного не нашли, то используем IPv4 localhost
     qDebug() << tcpServer->serverPort();
     if (ipAddress.isEmpty())
         ipAddress = QHostAddress(QHostAddress::LocalHost).toString();
     statusLabel->setText(tr("The server is running on\n\nIP: %1\nport: %2\n\n"
                             "Run the Fortune Client example now.")
                          .arg(ipAddress).arg(tcpServer->serverPort()));

     fortunes << tr("You've been leading a dog's life. Stay off the furniture.")
              << tr("You've got to think about tomorrow.")
              << tr("You will be surprised by a loud noise.")
              << tr("You will feel hungry again in another hour.")
              << tr("You might have mail.")
              << tr("You cannot kill time without injuring eternity.")
              << tr("Computers are not intelligent. They only think they are.");

     connect(quitButton, SIGNAL(clicked()), this, SLOT(close()));
     connect(tcpServer, SIGNAL(newConnection()), this, SLOT(sendFortune()));

     QHBoxLayout *buttonLayout = new QHBoxLayout;
     buttonLayout->addStretch(1);
     buttonLayout->addWidget(quitButton);
     buttonLayout->addStretch(1);

     QVBoxLayout *mainLayout = new QVBoxLayout;
     mainLayout->addWidget(statusLabel);
     mainLayout->addLayout(buttonLayout);
     setLayout(mainLayout);

     setWindowTitle(tr("Fortune Server"));
 }

 void Server::sendFortune()
 {
     QByteArray block;
     QDataStream out(&block, QIODevice::WriteOnly);
     out.setVersion(QDataStream::Qt_4_0);
     out << (quint16)0;
     out << fortunes.at(qrand() % fortunes.size());
     out.device()->seek(0);
     out << (quint16)(block.size() - sizeof(quint16));

     QTcpSocket *clientConnection = tcpServer->nextPendingConnection();
     connect(clientConnection, SIGNAL(disconnected()),
             clientConnection, SLOT(deleteLater()));

     clientConnection->write(block);
     clientConnection->disconnectFromHost();
 }
