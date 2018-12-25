/*
Задача 1.
Реализовать класс Employee. Объявление в файле employee.h, реализация в employee.cpp.
Класс должен содержать приватные поля для хранения:

имени
фамилии
пола
возраста
категории (число от 0).
Пол сотрудника можно хранить в строковых константах "male"/"female" или завести для этого enum class.
Класс должен иметь один констуктор, который принимает 5 параметров (имя, фамилия, пол, возраст, категория),
для инициализации полей класса должен использоваться список инициализации.
Реализовать методы класса:

promote - увеличивает значение поля "категория" на 1
demote - уменьшает значение поля "категория" на 1
printInfo - выводит всю информацию о работнике в удобном для чтения формате
*/
#include <iostream>
#include "employee.h"

int main()
{
    Gender male = Gender::MALE;
    Gender female = Gender::FEMALE;

    Employee Emp0("Василий", "Чапаев", male, 10, 32);
    Employee Emp1("Василиса", "Прекрасная", female, 15, 25);
    Employee Emp2("John", "Smith", male, 55, 40);
    Emp0.printInfo();
    Emp1.printInfo();
    Emp2.printInfo();
    for (int i = 0; i < 100; i++) Emp0.promote();
    for (int i = 0; i < 5; i++) Emp1.promote();
    for (int i = 0; i < 200; i++) Emp2.demote();
    std::cout << "After pro-/demotion:" << std::endl;
    std::cout << "======================" << std::endl;
    Emp0.printInfo();
    Emp1.printInfo();
    Emp2.printInfo();
    return 0;
}
