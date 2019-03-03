#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql>
#include <QtWidgets>
#include <iostream>
#include <QDebug>
#include <QCloseEvent>

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
    Ui::MainWindow *ui;
    bool MessBox(QString message);
    QSqlDatabase dbs = QSqlDatabase::addDatabase("QSQLITE");
    QString file_name_BD = "rzhd.db";
    QString version = "final task v0.1";
};

#endif // MAINWINDOW_H
