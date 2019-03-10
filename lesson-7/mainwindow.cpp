#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    count(0),
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_addButton_clicked()
{
    count++;
    QPushButton *button = new QPushButton(this);
    button->setText("Button " + QString::number(count));
    ui->layout_buttons->addWidget(button);

    connect(button, &QPushButton::clicked, [this, button](){
        ui->label_button_name->setText(button->text());
    });

    QPushButton *button1 = new QPushButton(this);
    button1->setText("Button1 " + QString::number(count));
    ui->layout_buttons1->addWidget(button1);

    connect(button1, &QPushButton::clicked, [this, button1](){
        ui->label_button_name->setText(button1->text());
    });
}
