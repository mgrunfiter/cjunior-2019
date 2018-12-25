#ifndef PERSON_H
#define PERSON_H
#include <iostream>
#include <vector>

class Person {
public:
  Person(std::string f_name, std::string l_name, int b_year);

  void ChangeFirstName(int year, const std::string& first_name);
  void ChangeLastName(int year, const std::string& last_name);
  std::string GetFullName(int year);
  std::string GetFullNameWithHistory(int year);

private:
  // приватные поля
  std::vector<std::string> first_name;
  std::vector<std::string> last_name;
  //int birth_year;
  std::vector<int> year;


};

#endif // PERSON_H
