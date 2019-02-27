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

    BattleField MyField(FIELD1_X, FIELD1_Y);
    BattleField EnemyField(FIELD2_X, FIELD2_Y);

    Cell cell(FIELD1_X, FIELD1_Y);
    MyField.navy[0][0] = cell;

    MyField.navy[0][0].setState(ST_SHIP);

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
        int x = 68;
        int y = 81;
        painter.drawImage(x, y, pictures.get("cross"));
        x += CELL_LENX;
        painter.drawImage(x, y, pictures.get("dot"));
        x += CELL_LENX;
        painter.drawImage(x, y, pictures.get("1"));
        x = 68;
        y += 2 * CELL_LENY;
        painter.drawImage(x, y, pictures.get("2g"));
        y += 2 * CELL_LENY;
        painter.drawImage(x, y, pictures.get("3g"));
        y += 2 * CELL_LENY;
        painter.drawImage(x, y, pictures.get("4g"));
        x += 4 * CELL_LENX;
        y = 81;
        painter.drawImage(x, y, pictures.get("2v"));
        x += 2 * CELL_LENX;
        painter.drawImage(x, y, pictures.get("3v"));
        y += 4 * CELL_LENY;
        painter.drawImage(x, y, pictures.get("4v"));

}

int MainWindow::ShutInFild(int x, int y)
{
    if (((x >= FIELD1_X) && (x <= FIELD1_X + FIELD_WIDTH)) &&
        ((y >= FIELD1_Y) && (y <= FIELD1_Y + FIELD_HEIGHT)))
        return 1;
    if (((x >= FIELD2_X) && (x <= FIELD2_X + FIELD_WIDTH)) &&
        ((y >= FIELD2_Y) && (y <= FIELD2_Y + FIELD_HEIGHT)))
        return 2;
}

void MainWindow::mousePressEvent(QMouseEvent *ev)
{
    QPoint pos = ev->pos();

    // длина и высота одной ячейки
    //int cell_len = 23;

    qDebug() << "!!!! x =" << pos.x() << "y =" << pos.y();

    if (state == ST_PLACING_SHIPS)
    {
        if (ShutInFild(pos.x(), pos.y()) == 1)
        {
            qDebug() << "Корабль здесь: x =" << pos.x() << "y =" << pos.y();
         }
    }
    else if (state == ST_MAKING_STEP)
         {
             if (ShutInFild(pos.x(), pos.y()) == 2)
             {
                 qDebug() << "Выстрел:  x =" << pos.x() << "y =" << pos.y();
                 state = ST_WAITING_STEP;
                 ui->lbState->setText("Ждите: ход соперника");
             }
         }
         else if (state == ST_WAITING_STEP)
              {
                  if (ShutInFild(pos.x(), pos.y()) == 1)
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
