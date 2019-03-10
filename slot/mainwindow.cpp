#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setName(QString &n_name)
{
    name = n_name;
}

void MainWindow::getMessage(const Message &msg)
{
    this_message = msg;
    QString message = "from :" + this_message.getAddress() + "\nmessage: " + this_message.body();
    ui->textEdit->setPlainText(this_message.body(), this_message.getAddress());
}

void MainWindow::on_send_clicked()
{
    this_message = Message(ui->textEdit->toPlainText(), name);
    emit sendMessage(this_message);
    // send signal
}
