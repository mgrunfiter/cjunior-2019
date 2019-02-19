#include <QtGui>
#include <QtNetwork>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
#include <QGridLayout>
#include <QDialogButtonBox>
#include <QMessageBox>

#include "client.h"

 Client::Client(QWidget *parent)
     : QDialog(parent)
 {
     hostLabel = new QLabel(tr("&Server name:"));
     portLabel = new QLabel(tr("S&erver port:"));

     // выясняем, с каким IP соединяться
     QString ipAddress;
     QList<QHostAddress> ipAddressesList = QNetworkInterface::allAddresses();
     // используем первый не локальный адрес IPv4
     for (int i = 0; i < ipAddressesList.size(); ++i) {
         if (ipAddressesList.at(i) != QHostAddress::LocalHost &&
             ipAddressesList.at(i).toIPv4Address()) {
             ipAddress = ipAddressesList.at(i).toString();
             break;
         }
     }
     // если мы ни одного не нашли, то используем IPv4 localhost
     if (ipAddress.isEmpty())
         ipAddress = QHostAddress(QHostAddress::LocalHost).toString();

     hostLineEdit = new QLineEdit(ipAddress);
     portLineEdit = new QLineEdit;
     portLineEdit->setValidator(new QIntValidator(1, 65535, this));

     hostLabel->setBuddy(hostLineEdit);
     portLabel->setBuddy(portLineEdit);

     statusLabel = new QLabel(tr("This examples requires that you run the "
                                 "Fortune Server example as well."));

     getFortuneButton = new QPushButton(tr("Get Fortune"));
     getFortuneButton->setDefault(true);
     getFortuneButton->setEnabled(false);

     quitButton = new QPushButton(tr("Quit"));

     buttonBox = new QDialogButtonBox;
     buttonBox->addButton(getFortuneButton, QDialogButtonBox::ActionRole);
     buttonBox->addButton(quitButton, QDialogButtonBox::RejectRole);

     tcpSocket = new QTcpSocket(this);

     connect(hostLineEdit, SIGNAL(textChanged(QString)),
             this, SLOT(enableGetFortuneButton()));
     connect(portLineEdit, SIGNAL(textChanged(QString)),
             this, SLOT(enableGetFortuneButton()));
     connect(getFortuneButton, SIGNAL(clicked()),
             this, SLOT(requestNewFortune()));
     connect(quitButton, SIGNAL(clicked()), this, SLOT(close()));
     connect(tcpSocket, SIGNAL(readyRead()), this, SLOT(readFortune()));
     connect(tcpSocket, SIGNAL(error(QAbstractSocket::SocketError)),
             this, SLOT(displayError(QAbstractSocket::SocketError)));

     QGridLayout *mainLayout = new QGridLayout;
     mainLayout->addWidget(hostLabel, 0, 0);
     mainLayout->addWidget(hostLineEdit, 0, 1);
     mainLayout->addWidget(portLabel, 1, 0);
     mainLayout->addWidget(portLineEdit, 1, 1);
     mainLayout->addWidget(statusLabel, 2, 0, 1, 2);
     mainLayout->addWidget(buttonBox, 3, 0, 1, 2);
     setLayout(mainLayout);

     setWindowTitle(tr("Fortune Client"));
     portLineEdit->setFocus();

 }

 void Client::requestNewFortune()
 {
     getFortuneButton->setEnabled(false);
     blockSize = 0;
     tcpSocket->abort();
     tcpSocket->connectToHost(hostLineEdit->text(),
                              portLineEdit->text().toInt());
 }

 void Client::readFortune()
 {
     QDataStream in(tcpSocket);
     in.setVersion(QDataStream::Qt_4_0);

     if (blockSize == 0) {
         if (tcpSocket->bytesAvailable() < (int)sizeof(quint16))
             return;

         in >> blockSize;
     }

     if (tcpSocket->bytesAvailable() < blockSize)
         return;

     QString nextFortune;
     in >> nextFortune;

     if (nextFortune == currentFortune) {
         QTimer::singleShot(0, this, SLOT(requestNewFortune()));
         return;
     }

     currentFortune = nextFortune;
     statusLabel->setText(currentFortune);
     getFortuneButton->setEnabled(true);
 }

 void Client::displayError(QAbstractSocket::SocketError socketError)
 {
     switch (socketError) {
     case QAbstractSocket::RemoteHostClosedError:
         break;
     case QAbstractSocket::HostNotFoundError:
         QMessageBox::information(this, tr("Fortune Client"),
                                  tr("The host was not found. Please check the "
                                     "host name and port settings."));
         break;
     case QAbstractSocket::ConnectionRefusedError:
         QMessageBox::information(this, tr("Fortune Client"),
                                  tr("The connection was refused by the peer. "
                                     "Make sure the fortune server is running, "
                                     "and check that the host name and port "
                                     "settings are correct."));
         break;
     default:
         QMessageBox::information(this, tr("Fortune Client"),
                                  tr("The following error occurred: %1.")
                                  .arg(tcpSocket->errorString()));
     }

     getFortuneButton->setEnabled(true);
 }

 void Client::enableGetFortuneButton()
 {
     getFortuneButton->setEnabled(!hostLineEdit->text().isEmpty()
                                  && !portLineEdit->text().isEmpty());
 }