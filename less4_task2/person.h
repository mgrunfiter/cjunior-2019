#ifndef PERSON_H
#define PERSON_H
#include <iostream>
#include <vector>

struct sNames {
   std::string first_name;
   std::string last_name;
   int year;
};

class Person {
public:
  Person(std::string f_name, std::string l_name, int b_year);

  void ChangeFirstName(int year, const std::string& first_name);
  void ChangeLastName(int year, const std::string& last_name);
  std::string GetFullName(int year);
  std::string GetFullNameWithHistory(int year);

private:
  //ФИО в год рождения
  sNames Names;
  // История изменения имени и фамилии по годам
  std::vector<sNames> vNames;

protected:
  //было ли изменение имени в этом году?
  bool FirstNameChanged(int year);
  //было ли изменение фамилии в этом году?
  bool LastNameChanged(int year);
  // в этом году вообще что-то менялось?
  // Возвращает число >= 0 - индекс в векторе vNames если да
  // и -1 если нет.
  int YearFound(int year);
  // сортировка вектора
  void SortNames();
};

#endif // PERSON_H
