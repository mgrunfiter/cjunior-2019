// ======================================================================
//  main.cpp
// ======================================================================
//                   This file is a part of the book 
//             "Qt 5.10 Professional programming with C++"
//                       http://qt-book.com
// ======================================================================
//  Copyright (c) 2017 by Max Schlee
// ======================================================================

#include <QtWidgets>
#include "PluginsWindow.h"


// ----------------------------------------------------------------------
int main(int argc, char** argv)
{
    QApplication  app(argc, argv);

    PluginsWindow win;

    win.show();

    return app.exec();
}
