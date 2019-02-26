#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    //Рисуем график y=x*x

        //Сгенерируем данные
        //Для этого создадим два массива точек:
        //один для созранения x координат точек,
        //а второй для y соответственно

        double a = -1; //Начало интервала, где рисуем график по оси Ox
        double b =  1; //Конец интервала, где рисуем график по оси Ox
        double h = 0.01; //Шаг, с которым будем пробегать по оси Ox

        int N=(b-a)/h + 2; //Вычисляем количество точек, которые будем отрисовывать
        QVector<double> x(N), y(N); //Массивы координат точек

        //Вычисляем наши данные
        int i=0;
        for (double X=a; X<=b; X+=h)//Пробегаем по всем точкам
        {
            x[i] = X;
            y[i] = X*X;//Формула нашей функции
            i++;
        }

        ui->widget->clearGraphs();//Если нужно, но очищаем все графики
        //Добавляем один график в widget
        ui->widget->addGraph();
        //Говорим, что отрисовать нужно график по нашим двум массивам x и y
        ui->widget->graph(0)->setData(x, y);

        //Подписываем оси Ox и Oy
        ui->widget->xAxis->setLabel("x");
        ui->widget->yAxis->setLabel("y");

        //Установим область, которая будет показываться на графике
        ui->widget->xAxis->setRange(a, b);//Для оси Ox

        //Для показа границ по оси Oy сложнее, так как надо по правильному
        //вычислить минимальное и максимальное значение в векторах
        double minY = y[0], maxY = y[0];
        for (int i=1; i<N; i++)
        {
            if (y[i]<minY) minY = y[i];
            if (y[i]>maxY) maxY = y[i];
        }
        ui->widget->yAxis->setRange(minY, maxY);//Для оси Oy

        //И перерисуем график на нашем widget
        ui->widget->replot();
}

void MainWindow::on_pushButton_2_clicked()
{
    //Рисуем график точками y=x*x

       //Сгенерируем данные
       //Для этого создадим два массива точек:
       //один для созранения x координат точек,
       //а второй для y соответственно

       double a = -1; //Начало интервала, где рисуем график по оси Ox
       double b =  1; //Конец интервала, где рисуем график по оси Ox
       double h = 0.1; //Шаг, с которым будем пробегать по оси Ox

       int N=(b-a)/h + 2; //Вычисляем количество точек, которые будем отрисовывать
       QVector<double> x(N), y(N); //Массивы координат точек

       //Вычисляем наши данные
       int i=0;
       for (double X=a; X<=b; X+=h)//Пробегаем по всем точкам
       {
           x[i] = X;
           y[i] = X*X;//Формула нашей функции
           i++;
       }

       ui->widget->clearGraphs();//Если нужно, но очищаем все графики
       //Добавляем один график в widget
       ui->widget->addGraph();
       //Говорим, что отрисовать нужно график по нашим двум массивам x и y
       ui->widget->graph(0)->setData(x, y);

       ui->widget->graph(0)->setPen(QColor(50, 50, 50, 255));//задаем цвет точки
       ui->widget->graph(0)->setLineStyle(QCPGraph::lsNone);//убираем линии
       //формируем вид точек
       ui->widget->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 4));

       //Подписываем оси Ox и Oy
       ui->widget->xAxis->setLabel("x");
       ui->widget->yAxis->setLabel("y");

       //Установим область, которая будет показываться на графике
       ui->widget->xAxis->setRange(a, b);//Для оси Ox

       //Для показа границ по оси Oy сложнее, так как надо по правильному
       //вычислить минимальное и максимальное значение в векторах
       double minY = y[0], maxY = y[0];
       for (int i=1; i<N; i++)
       {
           if (y[i]<minY) minY = y[i];
           if (y[i]>maxY) maxY = y[i];
       }
       ui->widget->yAxis->setRange(minY, maxY);//Для оси Oy

       //И перерисуем график на нашем widget
       ui->widget->replot();
}

void MainWindow::on_pushButton_3_clicked()
{
    //Рисуем точки

        int N=5; //Допустим, что у нас пять точек
        QVector<double> x(N), y(N); //Массивы координат точек

        //Зададим наши точки
        x[0] = 1.0; y[0] = 2.0;
        x[1] = 4.0; y[1] = 1.0;
        x[2] = 3.0; y[2] = 0.0;
        x[3] = 0.5; y[3] = 2.2;
        x[4] = 1.5; y[4] = 0.7;

        ui->widget->clearGraphs();//Если нужно, но очищаем все графики
        //Добавляем один график в widget
        ui->widget->addGraph();
        //Говорим, что отрисовать нужно график по нашим двум массивам x и y
        ui->widget->graph(0)->setData(x, y);

        ui->widget->graph(0)->setPen(QColor(50, 50, 50, 255));//задаем цвет точки
        ui->widget->graph(0)->setLineStyle(QCPGraph::lsNone);//убираем линии
        //формируем вид точек
        ui->widget->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 4));

        //Подписываем оси Ox и Oy
        ui->widget->xAxis->setLabel("x");
        ui->widget->yAxis->setLabel("y");

        //Установим область, которая будет показываться на графике
        ui->widget->xAxis->setRange(-1, 5);//Для оси Ox
        ui->widget->yAxis->setRange(-1, 3);//Для оси Oy

        //И перерисуем график на нашем widget
        ui->widget->replot();
}

void MainWindow::on_pushButton_4_clicked()
{
    // generate some data:
        QVector<double> x(101), y(101); // initialize with entries 0..100
        for (int i=0; i<101; ++i)
        {
          x[i] = i/50.0 - 1; // x goes from -1 to 1
          y[i] = x[i]*x[i]; // let's plot a quadratic function
        }
        // create graph and assign data to it:
        ui->widget->addGraph();
        ui->widget->graph(0)->setData(x, y);
        // give the axes some labels:
        ui->widget->xAxis->setLabel("x");
        ui->widget->yAxis->setLabel("y");
        // set axes ranges, so we see all data:
        ui->widget->xAxis->setRange(-1, 1);
        ui->widget->yAxis->setRange(0, 1);
        ui->widget->replot();
}

void MainWindow::on_pushButton_5_clicked()
{
    ui->widget->clearGraphs();//Если нужно, но очищаем все графики
    //Подписываем оси Ox и Oy
    ui->widget->xAxis->setLabel("");
    ui->widget->yAxis->setLabel("");
    //Установим область, которая будет показываться на графике
    ui->widget->xAxis->setRange(0, 5);//Для оси Ox
    ui->widget->yAxis->setRange(0, 5);//Для оси Oy
    ui->widget->replot();
}

void MainWindow::on_pushButton_6_clicked()
{
    QVector<double> x(2), y(2); //Массивы координат точек

    //Зададим наши точки
    x[0] = ui->leX_1->text().toDouble();
    y[0] = ui->leY_1->text().toDouble();
    x[1] = ui->leX_2->text().toDouble();
    y[1] = ui->leY_2->text().toDouble();
    ui->widget_2->clearGraphs();//Если нужно, то очищаем все графики
    //Добавляем один график в widget
    ui->widget_2->addGraph();
    //Говорим, что отрисовать нужно график по нашим двум массивам x и y
    ui->widget_2->graph(0)->setData(x, y);
    //Установим область, которая будет показываться на графике

    double max_x = 0;
    double min_x = 0;
    double max_y = 0;
    double min_y = 0;

    if (x[0] > x[1]) {
        min_x = x[1] - 1;
        max_x = x[0] + 1;
    }
    else {
        min_x = x[0] - 1;
        max_x = x[1] + 1;
    }
    if (y[0] > y[1]) {
        min_y = y[1] - 1;
        max_y = y[0] + 1;
    }
    else {
        min_y = y[0] - 1;
        max_y = y[1] + 1;
    }

    ui->widget_2->xAxis->setRange(min_x, max_x);//Для оси Ox
    ui->widget_2->yAxis->setRange(min_y, max_y);//Для оси Oy

    ui->widget_2->replot();
}
