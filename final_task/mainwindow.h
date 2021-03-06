#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql>
#include <QtWidgets>
#include <iostream>
#include <QDebug>
#include <QCloseEvent>
#include <vector>
#include "logger.h"
#include "defines.h"

struct GeoLine {
    int id;
    double x1;
    double y1;
    double x2;
    double y2;
};


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    QString getFilenameBD();
    ~MainWindow();

protected:
    void closeEvent(QCloseEvent *event);
    void setPosition(QWidget & current, QWidget * parrent);

private slots:
    void on_tbBaseFile_clicked();

private:
    std::vector<GeoLine>GeoLines;
    Ui::MainWindow *ui;
    bool MessBox(QString message);
    QSqlDatabase dbs = QSqlDatabase::addDatabase("QSQLITE");
    QSqlQuery query;
//    QString file_name_BD = "rzhd.db";
//    QString file_name_BD = "D:/_git/cpp/cjunior-2019/final_task/db/rzhd.db";
    QString file_name_BD = "/home/csv/study/github/cjunior-2019/final_task/db/rzhd.db";
    QString version = "final task v0.1";
};

#endif // MAINWINDOW_H
