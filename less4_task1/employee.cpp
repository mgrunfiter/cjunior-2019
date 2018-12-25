#include "employee.h"
#include <cassert>

Employee::Employee(std::string i_first_name, std::string i_last_name, Gender i_sex, unsigned i_category, unsigned i_age) :
    first_name(i_first_name),
    last_name(i_last_name),
    sex(i_sex),
    category(i_category),
    age(i_age)
{
}

Employee::~Employee()
{
}

void Employee::promote()
{
    category++;
}

void Employee::demote()
{
    if (category > 0)
        category--;
    else
        category = 0;
}

unsigned Employee::Get_category() const
{
    return category;
}

std::string Employee::Get_sex() const
{
    if (sex == Gender::MALE)
        return "Мужской";
    return "Женский";
}

void Employee::printInfo() const
{
    std::cout << "      Имя: " << first_name << std::endl;
    std::cout << "  Фамилия: " << last_name << std::endl;
    std::cout << "      Пол: " << Get_sex() << std::endl;
    std::cout << "  Возраст: " << age << std::endl;
    std::cout << "Категория: " << Get_category() << std::endl;
    std::cout << "======================" << std::endl;
}
