#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTime>
#include <QTimer>
#include <QDate>
#include <QDateTime>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void updateTime(); //Слот для обновления времени на экране

private:
    Ui::MainWindow *ui;
    QTimer *update_time;
//    QTimer *close_programm;
};

#endif // MAINWINDOW_H
