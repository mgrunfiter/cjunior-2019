#include "mainwindow.h"
#include "ui_mainwindow.h"

//Несколько "быстрых" вариантов создания MessageBox
//QMessageBox::warning(0,"Warning", "Warning message text");
//QMessageBox::information(0, "Information", "Information message text");
//QMessageBox::critical(0, "Critical", "Critical message text");

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->resize(680, 340);          // Устанавливаем размеры окна приложения
//    this->setFixedSize(680, 340);
    this->setPosition(*this, parent);
    this->setWindowTitle(version);

    ui->leBaseFile->setText(file_name_BD);
/*
if(!QFile::exists("C:\\sqlite\\newDB.db")){
    //file does not exist
}
QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
db.setDatabaseName("C:\\sqlite\\newDB.db");
if(!db.open()){
    //Database open error
}
{
    QSqlQuery q;
    if(!q.exec("SELECT name, sql FROM sqlite_master WHERE type='table' ;")){
        //corrupt or invalid sqlite file
}
*/
    bool FileBD = QFile::exists(file_name_BD);
    while (! FileBD)
    {
        qDebug() << dbs.lastError().text();
        qDebug() << "Can't open";
//        QMessageBox::warning(0, version, "Файл БД не найден!");
        if (MessBox("Файл БД не найден! Завершить работу?"))
        {
            FileBD = true;
            this->close();
        }
        else
        {
            file_name_BD = getFilenameBD();
            ui->leBaseFile->setText(file_name_BD);
            dbs.open();
        }
        FileBD = QFile::exists(file_name_BD);
    }
//    dbs.setDatabaseName(file_name_BD);
//    dbs.open();

//    while (! dbs.isOpen()) {
//        qDebug() << dbs.lastError().text();
//        qDebug() << "Can't open";
//        QMessageBox::warning(0, version, "Файл БД не найден!");
//        file_name_BD = getFilenameBD();
//        ui->leBaseFile->setText(file_name_BD);
//        dbs.open();
//    }
//    if (dbs.isOpen()) {
//        qDebug() << "OK";
//    }

}

void MainWindow::setPosition(QWidget & current, QWidget * parrent)
{
    int left, top;
    if ( parrent ){
        left = parrent->pos().x() + (parrent->frameGeometry().width() / 2) -
               (current.frameGeometry().width() / 2);
        top = parrent->pos().y() + (parrent->frameGeometry().height() / 2) -
              (current.frameGeometry().height() / 2);
    } else{
        left = (qApp->desktop()->width() / 2) - (current.frameGeometry().width() / 2);
        top = (qApp->desktop()->height() / 2) - (current.frameGeometry().height() / 2);
    }
    current.setGeometry(QRect(left, top,
               current.frameGeometry().width(),
               current.frameGeometry().height()));
}

bool MainWindow::MessBox(QString message)
{
    QMessageBox msgBox;
    msgBox.setWindowTitle(version);
    msgBox.setText(message);
    msgBox.setIcon(QMessageBox::Question);
    msgBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
    msgBox.setDefaultButton(QMessageBox::Ok);
    int ret = msgBox.exec();
    switch (ret) {
        case QMessageBox::Save:
            return false;
        case QMessageBox::Ok:
            return true;
        default:
            return false;
    }
}

void MainWindow::closeEvent(QCloseEvent *event)
{
//    event->ignore();
//    if (MessBox("Завершить работу?"))
//        event->accept();
}

MainWindow::~MainWindow()
{
    delete ui;
}

QString MainWindow::getFilenameBD()
{
    QString str = QFileDialog::getOpenFileName(0, "Open Dialog", "", "*.db");
    return str;
}

void MainWindow::on_tbBaseFile_clicked()
{
    file_name_BD = getFilenameBD();
    dbs.setDatabaseName(file_name_BD);
    ui->leBaseFile->setText(file_name_BD);
    dbs.open();
}
