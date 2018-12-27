/*
# Задача 2.

Реализуйте класс для человека, поддерживающий историю изменений человеком своих фамилии и имени.
```cpp
class Person {
public:
  void ChangeFirstName(int year, const string& first_name) {
    // добавить факт изменения имени на first_name в год year
  }
  void ChangeLastName(int year, const string& last_name) {
    // добавить факт изменения фамилии на last_name в год year
  }
  string GetFullName(int year) {
    // получить имя и фамилию по состоянию на конец года year
  }
private:
  // приватные поля
};
*/
/*
Считайте, что в каждый год может произойти не более одного изменения фамилии и не более одного изменения имени.
При этом с течением времени могут открываться всё новые факты из прошлого человека,
поэтому года́ в последовательных вызовах методов *ChangeLastName* и *ChangeFirstName* не обязаны возрастать.

Гарантируется, что все имена и фамилии непусты.

Строка, возвращаемая методом *GetFullName*, должна содержать разделённые одним пробелом имя и фамилию человека по состоянию на конец данного года.

- Если к данному году не случилось ни одного изменения фамилии и имени, верните строку "Incognito".
- Если к данному году случилось изменение фамилии, но не было ни одного изменения имени, верните "last_name with unknown first name".
- Если к данному году случилось изменение имени, но не было ни одного изменения фамилии, верните "first_name with unknown last name".

**Пример:**

 ```cpp
  person.ChangeFirstName(1965, "Polina");
  person.ChangeLastName(1967, "Sergeeva");
  for (int year : {1900, 1965, 1990}) {
    cout << person.GetFullName(year) << endl;
  }

  person.ChangeFirstName(1970, "Appolinaria");
  for (int year : {1969, 1970}) {
    cout << person.GetFullName(year) << endl;
  }

  person.ChangeLastName(1968, "Volkova");
  for (int year : {1969, 1970}) {
    cout << person.GetFullName(year) << endl;
  }

  return 0;
}

**Вывод:**

Incognito
Polina with unknown last name
Polina Sergeeva
Polina Sergeeva
Appolinaria Sergeeva
Polina Volkova
Appolinaria Volkova
*/

/*
Дополните класс Person конструктором, позволяющим задать имя и фамилию человека при рождении, а также сам год рождения. Класс не должен иметь конструктора по умолчанию.

При получении на вход года, который меньше года рождения:

- методы *GetFullName* и *GetFullNameWithHistory* должны отдавать "No person";
- методы ChangeFirstName и ChangeLastName должны игнорировать запрос.

Кроме того, необходимо объявить константными все методы, которые по сути ими являются.
```cpp
int main() {
  Person person("Polina", "Sergeeva", 1960);
  for (int year : {1959, 1960}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }

  person.ChangeFirstName(1965, "Appolinaria");
  person.ChangeLastName(1967, "Ivanova");
  for (int year : {1965, 1967}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }

  return 0;
}
```
**Вывод:**
```cpp
No person
Polina Sergeeva
Appolinaria (Polina) Sergeeva
Appolinaria (Polina) Ivanova (Sergeeva)
```
*/
#include <iostream>
#include <memory>
#include "person.h"


int main()
{
    {
        //Person person("", "", 1960);
        // на такой вариант ругается: main.cpp:110: ошибка: no member named 'make_unique' in namespace 'std'
        // Eсли без std:: то вот так: main.cpp:110: ошибка: use of undeclared identifier 'make_unique'
        //std::unique_ptr<Person> person = std::make_unique<Person>();
        std::unique_ptr<Person> person(new Person("", "", 1960));
        person->ChangeFirstName(1965, "Polina");
        person->ChangeLastName(1967, "Sergeeva");
        for (int year : {1900, 1961, 1965, 1990}) {
          std::cout << person->GetFullName(year) << std::endl;
        }

        person->ChangeFirstName(1970, "Appolinaria");
        for (int year : {1969, 1970}) {
          std::cout << person->GetFullName(year) << std::endl;
        }

        person->ChangeLastName(1968, "Volkova");
        for (int year : {1969, 1970}) {
          std::cout << person->GetFullName(year) << std::endl;
        }
    }

    std::cout << "===============================" << std::endl;

    std::unique_ptr<Person> person(new Person("Polina", "Sergeeva", 1960));
    for (int year : {1959, 1960}) {
        std::cout << person->GetFullNameWithHistory(year) << std::endl;
    }

    person->ChangeFirstName(1965, "Appolinaria");
    person->ChangeLastName(1967, "Ivanova");
    for (int year : {1965, 1967}) {
        std::cout << person->GetFullNameWithHistory(year) << std::endl;
    }

    return 0;
}
