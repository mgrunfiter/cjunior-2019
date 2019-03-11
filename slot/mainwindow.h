#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QKeyEvent>
#include <QMouseEvent>
#include <QDebug>
#include <QPoint>
#include "message.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void setName(QString n_name);

protected:
    void keyPressEvent(QKeyEvent *event);
    void mousePressEvent(QMouseEvent *ev);

signals:
    void sendMessage(const Message &msg);

public slots:
    void getMessage(const Message &msg);

private slots:
    void on_send_clicked();


private:
    Ui::MainWindow *ui;
    Message this_message;
    QString name;
};

#endif // MAINWINDOW_H
