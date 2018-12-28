#ifndef LOGIN_H
#define LOGIN_H

#pragma once
#include <iostream>

class login
{
public:
    char id[100];
    char pass[100];
   // char *password;
    std::string password;
//    void getpass(std::string str_in);
    void getid();
    void displayid();
};

#endif // LOGIN_H
