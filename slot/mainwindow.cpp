#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->textEdit->installEventFilter(this);
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setName(QString n_name)
{
    name = n_name;
}

bool MainWindow::eventFilter(QObject *obj, QEvent *event)
{
    if (event->type() == QEvent::KeyPress) {
        QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);
        if ((keyEvent->key() == Qt::Key_Return) && (keyEvent->modifiers() == Qt::ControlModifier))
        {
//            QMessageBox::information(0, "Information", "Enter pressed");
            this_message = Message(ui->textEdit->toPlainText(), name);
            emit sendMessage(this_message);
            return true;
        }
        return false;
    }
    return QObject::eventFilter(obj, event);
}

void MainWindow::wheelEvent(QWheelEvent *event)
{
    qDebug() << "Wheel event " << event->pos();
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    QPoint pos = event->pos();

    qDebug() << "x =" << pos.x() << "y =" << pos.y();

}

void MainWindow::getMessage(const Message &msg)
{
    this_message = msg;
    QString message = "from :" + this_message.getAddress() + "\nmessage: " + this_message.body();
    ui->textEdit->setPlainText(message);
}

void MainWindow::on_send_clicked()
{
    this_message = Message(ui->textEdit->toPlainText(), name);
    emit sendMessage(this_message);
    // send signal
}
