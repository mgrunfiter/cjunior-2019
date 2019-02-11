#include "login.h"

void login::getid()
{
    std::cout << "Enter your id:";
    std::cin >> id;
}

void login::displayid()
{
    std::cout << "Id:";
    std::cout << id;
    std::cout << "Password:";
    std::cout << pass;
}

