#ifndef POINT_H
#define POINT_H

#include <QObject>
#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QPainter>

class Point : public QObject, public QGraphicsItem
{
public:
    explicit Point(QObject *parent = nullptr);

protected:
    QRectF boundingRect() const;
//    void paint(QPainter *painter)

};

#endif // POINT_H
