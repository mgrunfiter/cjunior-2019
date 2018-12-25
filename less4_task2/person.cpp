#include "person.h"

Person::Person(std::string f_name, std::string l_name, int b_year)
{
    first_name.push_back(f_name);
    last_name.push_back(l_name);
    year.push_back(b_year);
}

void Person::ChangeFirstName(int year, const std::string& first_name) {
  // добавить факт изменения имени на first_name в год year
}

void Person::ChangeLastName(int year, const std::string& last_name) {
  // добавить факт изменения фамилии на last_name в год year
}

std::string Person::GetFullName(int year) {
  // получить имя и фамилию по состоянию на конец года year
}

std::string Person::GetFullNameWithHistory(int year) {
  //  история изменения имени и фамилии с рождения до конца года year
    return first_name[0];
}
