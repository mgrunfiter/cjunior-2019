#include "detail.h"

void detail::getdetail()
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
    std::cout << "No of seats in first class & fare per ticket:";
    std::cin >> c1 >> c1fare;
    std::cout << "No of seats in second class & fare per ticket:";
    std::cin >> c2 >> c2fare;
    std::cout << "Date of travel:";
    std::cin >> d >> m >> y;
}

void detail::displaydetail()
{
    std::cout << tno << "\t" << tname << "\t" << bp << "\t" << dest << "\t";
    std::cout << c1 << "\t" << c1fare << "\t" << c2 << "\t" << c2fare << "\t";
    std::cout << d << "-" << m<< "-" << y<< "\t" << std::endl;
}
