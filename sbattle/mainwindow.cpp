#include "mainwindow.h"
#include "ui_mainwindow.h"

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

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle(version);

    QImage back_img("://img/background.png");

    ui->lbBackground->setPixmap(QPixmap::fromImage(back_img));
    ui->lbBackground->setScaledContents(true);



    gameover = false;
    state = ST_PLACING_SHIPS;
    ui->lbState->setText("Расставьте корабли");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    event->ignore();
    if (MessBox("Завершить работу?"))
        event->accept();
}

void MainWindow::on_actionExit_triggered()
{
    close();
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    //
}

void MainWindow::mousePressEvent(QMouseEvent *ev)
{
    QPoint pos = ev->pos();

    int f1_left = 44;
    int f_top = 70;

    int f2_left = 333;

    int fild_x = 225;
    int fild_y = 225;

    // длина и высота одной ячейки
    int cell_len = 23;

    qDebug() << "!!!! x =" << pos.x() << "y =" << pos.y();

    if (state == ST_PLACING_SHIPS)
    {
        if (((pos.x() >= f1_left) && (pos.x() <= f1_left + fild_x)) &&
            ((pos.y() >= f_top) && (pos.y() <= f_top + fild_y)))
        {
            qDebug() << "Корабль здесь: x =" << pos.x() << "y =" << pos.y();
         }
    }
    else if (state == ST_MAKING_STEP)
         {
             if (((pos.x() >= f2_left) && (pos.x() <= f2_left + fild_x)) &&
                 ((pos.y() >= f_top) && (pos.y() <= f_top + fild_y)))
             {
                 qDebug() << "Выстрел:  x =" << pos.x() << "y =" << pos.y();
                 state = ST_WAITING_STEP;
                 ui->lbState->setText("Ждите: ход соперника");
             }
         }
         else if (state == ST_WAITING_STEP)
              {
                  if (((pos.x() >= f1_left) && (pos.x() <= f1_left + fild_x)) &&
                      ((pos.y() >= f_top) && (pos.y() <= f_top + fild_y)))
                  {
                      qDebug() << "В нас стреляли:  x =" << pos.x() << "y =" << pos.y();
                      state = ST_MAKING_STEP;
                      ui->lbState->setText("Ваш ход");
                  }
              }
}

void MainWindow::on_actionReady_triggered()
{
    state = ST_MAKING_STEP;
    ui->lbState->setText("Ваш ход");
}
