#include <QCoreApplication>
#include <QtSql>
#include <iostream>
#include <QDebug>
#include <string>


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QSqlDatabase dbs = QSqlDatabase::addDatabase("QSQLITE");
    dbs.setDatabaseName("rzhd.db");

    if (! dbs.open()) {
        std::cout << dbs.lastError().text().toStdString() << std::endl;
        std::cout << "Can't open" << std::endl;
    }
    else {
        std::cout << "OK" << std::endl;
    }

    //select * from RAILWAY_OBJ where ID < 100920;
    QSqlQuery qu("select * from RAILWAY_OBJ where ID < 100920");
//QSqlQuery qu("select * from GEO_LINE where ID = 481");

    while (qu.next())
    {
        int id = 0;
        std::string name;
        bool type_id;

        id = qu.value(0).toInt();
        name = qu.value(1).toString().toStdString();
        type_id =qu.value(2).toBool();

        std::cout << "id = " << id << " name = " << name << " type_id = " << type_id << std::endl;
    }

    return 0;
//    return a.exec();
}
