#include "server.h"
#include <QtCore>
#include <stdlib.h>
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

     Server server;
     server.show();

     qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
     return server.exec();
 }
