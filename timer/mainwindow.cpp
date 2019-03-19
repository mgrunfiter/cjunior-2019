#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    update_time(new QTimer)
//    close_programm(new QTimer)
{
    ui->setupUi(this);
    ui->label->setText(QTime::currentTime().toString());
    update_time->setInterval(1000); // Задаем интервал таймера
    //connect(update_time, SIGNAL(timeout()), this, SLOT(updateTime())); // Подключаем сигнал таймера к нашему слоту
    connect(update_time, QTimer::timeout, this, &MainWindow::updateTime);
    update_time->start(); // Запускаем таймер

    QDate *date = new QDate(2019, 3, 19);
    QTime *time = new QTime(19, 20, 4, 10);
    QDateTime *datetime = new QDateTime(*date, *time);

    QString str;
    str = time->toString("HH:mm:ss:sss");
    ui->textEdit->append(str);

    str = date->toString("dd.MM.yyyy");
    ui->textEdit->append(str);

    str = datetime->toUTC().toString("dd.MM.yyyy HH:mm:ss:sss");
    ui->textEdit->append(str);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateTime()
{
    ui->label->setText(QTime::currentTime().toString());

//    QString str;
//    str = time->toString("HH:MM:SS:SSS");
//    ui->textEdit->append(str);
}
