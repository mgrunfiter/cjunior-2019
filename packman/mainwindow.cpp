#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    view = new QGraphicsView();
    scene = new QGraphicsScene();

    view->setScene(scene);
    ui->verticalLayout->addWidget(view);
    view->setBackgroundBrush(Qt::black);


}

MainWindow::~MainWindow()
{
    delete ui;
}
