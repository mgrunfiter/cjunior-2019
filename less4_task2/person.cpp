#include "person.h"
//#include <algorithm>

void Person::SortNames()
{
    int i = 0, flag;
    sNames tNames;

    i = 0;
    do {
        flag = 0;
        for (int j = vNames.size() - 2; j >= i; j--) {
             if (vNames[j].year > vNames[j + 1].year) {
                 tNames = vNames[j];
                 vNames[j] = vNames[j + 1];
                 vNames[j + 1] = tNames;
                 flag = 1;
             }
       }
       i++;
    } while (flag);
}

int Person::YearFound(int year) const
{
    int index = -1;
//    int size = static_cast<int>(vNames.size());
//    for (int i = 0; i < size; i++) {
    for (unsigned i = 0; i < vNames.size(); i++) {
        if (vNames[i].year == year)
            index = i;
            break;
        }
    return index;
}

bool Person::FirstNameChanged(int year) const
{
    bool flag = false;
    int index = 0;

    index = YearFound(year);
    if ((index >= 0) && (vNames.at(index).first_name != "")) {
        flag = true;
    }
    return flag;
}

bool Person::LastNameChanged(int year) const
{
    bool flag = false;
    int index = 0;

    index = YearFound(year);
    if ((index >= 0) && (vNames.at(index).last_name != "")) {
        flag = true;
    }
    return flag;
}

// конструктор
Person::Person(const std::string f_name, const std::string l_name, const int b_year)
// не получилось здесь проинициализировать ((
   // Names.first_name(f_name),
   // Names.last_name(l_name),
   // Names.year(b_year)
{
    Names.first_name = f_name;
    Names.last_name = l_name;
    Names.year = b_year;
    vNames.push_back(Names);
}

// добавить факт изменения имени на first_name в год year
void Person::ChangeFirstName(int year, const std::string& first_name) {
    sNames tNames;
    int index = 0;

    index = YearFound(year);
    if (index >= 0) {
        if (not FirstNameChanged(year)) {
            vNames.at(index).first_name = first_name;
        }
        else {
            return;
        }
    }
    else {
        tNames.first_name = first_name;
        tNames.last_name = "";
        tNames.year = year;
        vNames.push_back(tNames);
    }
    SortNames();
}

// добавить факт изменения фамилии на last_name в год year
void Person::ChangeLastName(int year, const std::string& last_name) {
    sNames tNames;
    int index = 0;

    index = YearFound(year);
    if (index >= 0) {
        if (not LastNameChanged(year)) {
            vNames.at(index).first_name = last_name;
        }
        else {
            return;
        }
    }
    else {
        tNames.first_name = "";
        tNames.last_name = last_name;
        tNames.year = year;
        vNames.push_back(tNames);
    }
    SortNames();
}

// получить имя и фамилию по состоянию на конец года year
std::string Person::GetFullName(int year)  const
{

    std::string result = "Incognito";
    std::string f_name = "with unknown first name";
    std::string l_name = "with unknown last name";

    if (Names.year > year) {
      return "No person";
    }
    for (int i = 0; i < vNames.size(); i++) {
        if (vNames.at(i).year > year) {
            break;
        }
        if (vNames.at(i).year <= year) {
            if (vNames.at(i).first_name != "")
                f_name = vNames.at(i).first_name;
            if (vNames.at(i).last_name != "")
                l_name = vNames.at(i).last_name;
            result = f_name + " " + l_name;
        }
    }
    if ((f_name == "with unknown first name") && (l_name == "with unknown last name"))
        result = "Incognito";
    return result;
}

// TODO: продолжать здесь
// история изменения имени и фамилии с рождения до конца года year
std::string Person::GetFullNameWithHistory(int year)  const
{
    std::string result = "Incognito";
    std::string f_name = Names.first_name;
    std::string l_name = Names.last_name;

    if (Names.year > year) {
      return "No person";
    }
    for (int i = 0; i < vNames.size(); i++) {
        if (vNames.at(i).year > year) {
            break;
        }
        if (vNames.at(i).year <= year) {
            if (vNames.at(i).first_name != "")
                if (f_name != vNames.at(i).first_name)
                    f_name = vNames.at(i).first_name + " (" + f_name + ")";
            if (vNames.at(i).last_name != "")
                if (l_name != vNames.at(i).last_name)
                    l_name = vNames.at(i).last_name + " (" + l_name + ")";
            result = f_name + " " + l_name;
        }
    }
    return result;
}
