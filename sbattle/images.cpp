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
    images.insert("dot", QImage("://img/dot.png"));
    images.insert("cross", QImage("://img/cross.png"));
    images.insert("empty", QImage("://img/empty.png"));
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
