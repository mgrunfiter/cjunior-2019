#ifndef CANC_H
#define CANC_H

#pragma once

#include <iostream>

class canc
{
public:
    int pnr;
    int tno;
    char tname[100];
    char bp[10];
    char dest[100];
    char pname[10][100];
    int age[20];
    int i;
    char clas[10];
    int nosc;
    int d, m, y;
    float amr;
    void getcancdet();
    void displaycancdet();

};

#endif // CANC_H
