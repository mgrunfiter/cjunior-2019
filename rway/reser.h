#ifndef RESER_H
#define RESER_H

#pragma once
#include <iostream>

class reser
{
public:
    int pnr;
    int tno;
    char tname[100];
    char bp[10];
    char dest[100];
    char pname[10][100];
    int age[20];
    char clas[10];
    int nosr;
    int i;
    int d, m, y;
    int con;
    float amc;
    void getresdet();
    void displayresdet();
};

#endif // RESER_H
