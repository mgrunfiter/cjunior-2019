#include "reser.h"

void reser::getresdet()
{
    std::cout << "Enter the details as follows\n";
    std::cout << "Train no:";
    std::cin >> tno;
    std::cout << "Train name:";
    std::cin >> tname;
    std::cout << "Boarding point:";
    std::cin >> bp;
    std::cout << "Destination pt:";
    std::cin >> dest;
    std::cout << "No of seats required:";
    std::cin >> nosr;
    for (i = 0; i < nosr ; i++)
    {
        std::cout << "Passenger name:";
        std::cin >> pname[i];
        std::cout << "Passenger age:";
        std::cin >> age[i];
    }
    std::cout << "Enter the class f-first class s-second class:";
    std::cin >> clas;
    std::cout << "Date of travel:";
    std::cin >> d >> m >> y;
    std::cout << "Enter the concession category\n";
    std::cout << "1.Military\n2.Senior citizen\n";
    std::cout << "3.Children below 5 yrs\n4.None\n";
    std::cin >> con;
    std::cout << "............END OF GETTING DETAILS............\n";
}

void reser::displayresdet()
{
    std::cout << "...............................................\n";
    std::cout << "...............................................\n";
    std::cout << "Pnr no:" << pnr;
    std::cout << "\nTrain no:" << tno;
    std::cout << "\nTrain name:";
    std::cout << tname;
    std::cout << "Boarding point:";
    std::cout << bp;
    std::cout << "Destination pt:";
    std::cout << dest;
    std::cout << "No of seats reserved:"<<nosr;
    for (i = 0; i < nosr; i++)
    {
        std::cout << "Passenger name:";
        std::cout << pname[i];
        std::cout << "Passenger age:" << age[i];
    }
    std::cout << "\nYour class:";
    std::cout << clas;
    std::cout << "\nDate of reservation:" << d << "-" << m << "-" << y;
    std::cout << "\nYour concession category:" << con;
    std::cout << "\nYou must pay:" << amc << std::endl;
    std::cout << "***********************************************\n";
    std::cout << ".........END OF RESERVATION.................\n";
    std::cout << "***********************************************\n";
}
