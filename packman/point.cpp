#include "point.h"

Point::Point(QObject *parent):
    QObject(parent),
//    QGraphictsIten()
{

}

QRectF Point::boundingRect() const
{
    return QRectF(0, 0, 20, 20);
}
