#include "images.h"

Images pictures = Images();

Images::Images():
    _isLoaded(false)
{
}

void Images::load()
{
    if(_isLoaded)
        return;

    images.insert("field", QImage("://img/background.png"));
    images.insert("dot", QImage("://img/dot1.png"));
    images.insert("cross", QImage("://img/cross.png"));
    images.insert("empty", QImage("://img/empty.png"));
    images.insert("1", QImage("://img/1.png"));
    images.insert("2g", QImage("://img/2g.png"));
    images.insert("3g", QImage("://img/3g.png"));
    images.insert("4g", QImage("://img/4g.png"));
    images.insert("2v", QImage("://img/2v.png"));
    images.insert("3v", QImage("://img/3v.png"));
    images.insert("4v", QImage("://img/4v.png"));
    _isLoaded = true;
}

QImage& Images::get(const QString& imgName)
{
    QMap<QString, QImage>::iterator i = images.find(imgName);

    if(i == images.end())
        throw 1;

    return i.value();
}

bool Images::isLoaded()
{
    return _isLoaded;
}
