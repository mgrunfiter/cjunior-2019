#ifndef IMAGES_H
#define IMAGES_H

#pragma once
#include <QMap>
#include <QImage>
#include <QString>

class Images
{
public:
    Images();
    void load();
    QImage &get(const QString &imgName);
    bool isLoaded();

private:
    QMap<QString, QImage> images;
    bool _isLoaded;
};

extern Images pictures;

#endif // IMAGES_H
