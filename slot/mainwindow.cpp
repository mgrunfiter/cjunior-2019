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

void MainWindow::setName(QString n_name)
{
    name = n_name;
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
//    if (event->type() == QEvent::KeyPress)
//    {
//        QKeyEvent *ke = static_cast<QKeyEvent *>(event);
//        if (ke->key() == Qt::Key_Enter) {
//            QMessageBox::information(0, "Information", "Enter pressed");
//        }

//    }
//    if ((event->key() == Qt::Key_F10) && (event->modifiers() == Qt::ControlModifier))
    if ( (event->modifiers() == Qt::ControlModifier) && (event->key() == Qt::Key_F10) )
    {
         QMessageBox::information(0, "Information", "Enter pressed");
         this_message = Message(ui->textEdit->toPlainText(), name);
         emit sendMessage(this_message);
    }
}

void MainWindow::mousePressEvent(QMouseEvent *ev)
{
    QPoint pos = ev->pos();
    qDebug() << "x =" << pos.x() << "y =" << pos.y();
}

void MainWindow::getMessage(const Message &msg)
{
    this_message = msg;
    QString message = "from :" + this_message.getAddress() + "\nmessage: " + this_message.body();
    ui->textEdit->setPlainText(message);
//    ui->textEdit->setPlainText(this_message.body());
}

void MainWindow::on_send_clicked()
{
    this_message = Message(ui->textEdit->toPlainText(), name);
    emit sendMessage(this_message);
    // send signal
}
