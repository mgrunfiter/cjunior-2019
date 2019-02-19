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


namespace Ui {
class MainWindow;
}

enum StateGame
{
    ST_PLACING_SHIPS,
    ST_WAITING_STEP,
    ST_MAKING_STEP
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionExit_triggered();

protected:
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *ev);

private:
    Ui::MainWindow *ui;
    bool MessBox(QString message);
    void closeEvent(QCloseEvent *event);
    StateGame state;
    bool gameover;
};

#endif // MAINWINDOW_H
