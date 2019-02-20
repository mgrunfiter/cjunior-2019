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
    pictures.load();

    this->resize(600, 390);          // Устанавливаем размеры окна приложения
    this->setFixedSize(600, 390);
    this->setWindowTitle(version);


    gameover = false;
    state = ST_PLACING_SHIPS;
    ui->pbGame->setText("Старт");
    ui->pbAuto->setEnabled(true);
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
    Q_UNUSED(event);
    const int deltaY =this->centralWidget()->y();

    QPainter painter(this); // Создаём объект отрисовщика
        painter.drawImage(
            0,
            deltaY,
            pictures.get("field")
        );
}

void MainWindow::mousePressEvent(QMouseEvent *ev)
{
    QPoint pos = ev->pos();

//    int f1_left = 44;
//    int f_top = 56;

//    int f2_left = 333;

//    int fild_x = 225;
//    int fild_y = 225;

//    const int FIELD1_X = 44;
//    const int FIELD1_Y = 56;
//    const int FIELD2_X = 44;
//    const int FIELD2_Y = 333;
//    const int FIELD_WIDTH = 225;
//    const int FIELD_HEIGHT = 225;

    // длина и высота одной ячейки
    int cell_len = 23;

    qDebug() << "!!!! x =" << pos.x() << "y =" << pos.y();

    if (state == ST_PLACING_SHIPS)
    {
        if (((pos.x() >= FIELD1_X) && (pos.x() <= FIELD1_X + FIELD_WIDTH)) &&
            ((pos.y() >= FIELD1_Y) && (pos.y() <= FIELD1_Y + FIELD_HEIGHT)))
        {
            qDebug() << "Корабль здесь: x =" << pos.x() << "y =" << pos.y();
         }
    }
    else if (state == ST_MAKING_STEP)
         {
             if (((pos.x() >= FIELD2_X) && (pos.x() <= FIELD2_X + FIELD_WIDTH)) &&
                 ((pos.y() >= FIELD2_Y) && (pos.y() <= FIELD2_Y + FIELD_HEIGHT)))
             {
                 qDebug() << "Выстрел:  x =" << pos.x() << "y =" << pos.y();
                 state = ST_WAITING_STEP;
                 ui->lbState->setText("Ждите: ход соперника");
             }
         }
         else if (state == ST_WAITING_STEP)
              {
                  if (((pos.x() >= FIELD1_X) && (pos.x() <= FIELD1_X + FIELD_WIDTH)) &&
                      ((pos.y() >= FIELD1_Y) && (pos.y() <= FIELD1_Y + FIELD_HEIGHT)))
                  {
                      qDebug() << "В нас стреляли:  x =" << pos.x() << "y =" << pos.y();
                      state = ST_MAKING_STEP;
                      ui->lbState->setText("Ваш ход");
                  }
              }
              else if (state == ST_PAUSE)
                   {
                        //

                   }

}

void MainWindow::StartGame()
{
    state = ST_MAKING_STEP;
    previos_state = ST_PLACING_SHIPS;
    ui->lbState->setText("Ваш ход");
    ui->pbGame->setText("Стоп");
    ui->pbAuto->setEnabled(false);
    ui->actionReady->setText("Стоп");
    ui->actionAutoranging->setDisabled(true);
}

void MainWindow::StartStopGame()
{
    if (state == ST_PAUSE)
    {
        state = previos_state;
        ui->pbGame->setText("Стоп");
        ui->pbAuto->setEnabled(false);
        ui->actionReady->setText("Стоп");
        ui->actionAutoranging->setDisabled(true);
        if (state == ST_MAKING_STEP)
            ui->lbState->setText("Ваш ход");
        if (state == ST_WAITING_STEP)
            ui->lbState->setText("Ждите: ход соперника");
    }
    else if (state == ST_PLACING_SHIPS)
         {
            StartGame();
         }
         else
         {
             previos_state = state;
             state = ST_PAUSE;
             ui->pbGame->setText("Старт");
             ui->actionReady->setText("Старт");
             ui->actionAutoranging->setDisabled(false);
             ui->pbAuto->setEnabled(true);
             ui->lbState->setText("Пауза");
    }
}

void MainWindow::on_actionReady_triggered()
{
    StartStopGame();
}

void MainWindow::on_pbGame_clicked()
{
    StartStopGame();
}

void MainWindow::on_pbAuto_clicked()
{
    state = ST_PLACING_SHIPS;
    ui->pbGame->setText("Старт");
    ui->pbAuto->setEnabled(true);
    ui->lbState->setText("Расставьте корабли");
}

void MainWindow::on_actionAutoranging_triggered()
{
    state = ST_PLACING_SHIPS;
    ui->pbGame->setText("Старт");
    ui->pbAuto->setEnabled(true);
    ui->lbState->setText("Расставьте корабли");
}
