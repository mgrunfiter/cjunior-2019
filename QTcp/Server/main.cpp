#include <stdlib.h>
#include <QtGui>
#include <QtCore>
#include <QtNetwork>
#include <QApplication>
#include <QTcpServer>
#include <QTcpSocket>
#include <QMessageBox>
#include <QCheckBox>
#include "MyServer.h"


// ----------------------------------------------------------------------
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MyServer  server(2323);

    server.show();

    return app.exec();
}
