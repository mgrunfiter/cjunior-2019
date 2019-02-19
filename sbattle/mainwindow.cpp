#include "mainwindow.h"
#include "ui_mainwindow.h"

bool MainWindow::MessBox(QString message)
{
    QMessageBox msgBox;
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

    //ui->lbBackground->setStyleSheet(":res/sb_fon.png");
    QImage back_img(":res/sb_fon.png");
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
    int f1_left = 39;
    int f_top = 63;

    int f2_left = 406;

    int fild_x = 280;
    int fild_y = 225;

//    qDebug() << "!!!! x =" << pos.x() << "y =" << pos.y();

    if (state == ST_PLACING_SHIPS)
    {
        if (((pos.x() > f1_left) && (pos.x() < f1_left + fild_x)) &&
            ((pos.y() > f_top) && (pos.y() < f_top + fild_y)))
        {
            qDebug() << "x =" << pos.x() << "y =" << pos.y();
            qDebug() << "Корабли расставлены!";
            state = ST_MAKING_STEP;
            ui->lbState->setText("Ваш ход");
         }
    }
    else if (state == ST_MAKING_STEP)
         {
             if (((pos.x() > f2_left) && (pos.x() < f2_left + fild_x)) &&
                 ((pos.y() > f_top) && (pos.y() < f_top + fild_y)))
             {
                 qDebug() << "Выстрел:  x =" << pos.x() << "y =" << pos.y();
                 state = ST_WAITING_STEP;
                 ui->lbState->setText("Ждите: ход соперника");
             }
         }
         else if (state == ST_WAITING_STEP)
              {
                  if (((pos.x() > f1_left) && (pos.x() < f1_left + fild_x)) &&
                      ((pos.y() > f_top) && (pos.y() < f_top + fild_y)))
                  {
                      qDebug() << "В нас стреляли:  x =" << pos.x() << "y =" << pos.y();
                      state = ST_MAKING_STEP;
                      ui->lbState->setText("Ваш ход");
                  }
              }
}
