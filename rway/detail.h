#ifndef DETAIL_H
#define DETAIL_H

#pragma once
#include <iostream>

class detail
{
public:
    int tno;
    char tname[100];

    char bp[100];
    char dest[100];
    int c1, c1fare;
    int c2, c2fare;
    int d, m, y;
    void getdetail();
    void displaydetail();
};

#endif // DETAIL_H
