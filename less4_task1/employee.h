#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <iostream>

enum class Gender : int
{
    MALE = 0,
    FEMALE = 1
};

class Employee
{
public:
    Employee(std::string i_first_name, std::string i_last_name, Gender i_sex, unsigned i_category, unsigned i_age);

    ~Employee();

    //- увеличивает значение поля "категория" на 1
    void promote();

    //- уменьшает значение поля "категория" на 1
    void demote();

    //- выводит всю информацию о работнике в удобном для чтения формате
    void printInfo() const;

    // Категория
    unsigned getCategory() const;

    // Пол в человеческом виде ))
    std::string getSex() const;
private:
    std::string first_name;
    std::string last_name;
    Gender sex;
    unsigned category;
    unsigned age;
};


#endif // EMPLOYEE_H
