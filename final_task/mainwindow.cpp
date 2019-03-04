#include "mainwindow.h"
#include "ui_mainwindow.h"

//QMessageBox::warning(0,"Warning", "Warning message text");
//QMessageBox::information(0, "Information", "Information message text");
//QMessageBox::critical(0, "Critical", "Critical message text");

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->resize(680, 340);          // Устанавливаем размеры окна приложения
    this->setPosition(*this, parent);
    this->setWindowTitle(version);

    ui->leBaseFile->setText(file_name_BD);

    if (! QFile::exists(file_name_BD))
    {
        QMessageBox::warning(0, version, "Файл БД не доступен! \n Для продолжения укажите файл БД.");
        file_name_BD = getFilenameBD();
        ui->leBaseFile->setText(file_name_BD);
    }
    if (! dbs.open())
    {
       qDebug() << "Can't open";
       QMessageBox::warning(0, version, "Соединение с БД не установлено!");
    }
    else
    {
        QSqlQuery qu;
        int numRows = 0;
        qu.prepare("SELECT name, sql FROM sqlite_master WHERE type='table'");
        qu.exec();

        QSqlDatabase defaultDB = QSqlDatabase::database();
        if (defaultDB.driver()->hasFeature(QSqlDriver::QuerySize)) {
            numRows = qu.size();
        } else {
            // это может быть очень медленно
            qu.last();
            numRows = qu.at() + 1;
        }

        if ( numRows <= 0)
//        if ( ! qu.exec("SELECT name, sql FROM sqlite_master WHERE type='table' ;"))
        {
           qDebug() << "corrupt or invalid sqlite file";
           QMessageBox::critical(0, "Critical", "Файл БД поврежден или или недействителен!");
        }
        else
        {
            while (qu.next())
            {
//                std::string name;
//                std::string sql;
//                name = qu.value(0).toString().toStdString();
//                sql = qu.value(1).toString().toStdString();
//                std::cout << " name = " << name << " sql = " << sql << std::endl;
                QString name = qu.value(0).toString();
                QString sql = qu.value(1).toString();
                qDebug() << " name = " << name << " sql = " << sql;

            }
        }
    }
    // TODO:
    // Процедура чтения из БД и перерисовки

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
    // TODO:
    // Процедура чтения из БД и перерисовки
}
