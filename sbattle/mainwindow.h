#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QImage>
#include <QPainter>
#include <QMouseEvent>
#include <QDebug>
#include <QPoint>
#include <QMessageBox>
#include <QString>
#include <QCloseEvent>
#include <QtWidgets>
#include "images.h"
#include "defines.h"
#include "cell.h"
#include "battlefield.h"

#include <iostream>

namespace Ui {
class MainWindow;
}

enum StateGame
{
    ST_PLACING_SHIPS,
    ST_WAITING_STEP,
    ST_MAKING_STEP,
    ST_PAUSE
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionExit_triggered();
    void on_actionReady_triggered();
    void on_pbGame_clicked();
    void on_pbAuto_clicked();
    void on_actionAutoranging_triggered();

protected:
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *ev);
    void closeEvent(QCloseEvent *event);
    void setPosition(QWidget & current, QWidget * parrent = 0);

private:
    Ui::MainWindow *ui;
    bool MessBox(QString message);
    void StartGame();
    void StartStopGame();
    int ShutInFild(int x, int y);
    StateGame state;
    StateGame previos_state;
    QString version = "Sea Battle v0.1";
    bool gameover;
};

#endif // MAINWINDOW_H
