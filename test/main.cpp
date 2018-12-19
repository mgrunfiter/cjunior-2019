#include <QCoreApplication>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <limits>
#include <chrono>

using namespace std;
using namespace std::chrono;

auto finish = steady_clock::now();
struct Person
{
    string f_name;
    string l_name;
    int age;
};

void printPersonListSize(vector<Person> &p_list)
{
    cout << "Size " << p_list.size() << endl;
}

vector<Person> createPersonList(int list_size)
{
    vector<Person> list;
    for (int i = 0; i < list_size; i++)
    {
        Person person;
        person.age = i;
        person.f_name = "vasya" + to_string(i);
        person.l_name = "pupkin" + to_string(i);
        list.push_back(person);
        cout << "f_name " << person.f_name << endl;
        cout << "l_name " << person.l_name << endl;
     }
return list;
}

int main()
{
//   auto start = steady_clock::now();
//   vector<Person> my_list = createPersonList(100000);
//   auto finish = steady_clock::now();
//   auto time_s = duration_cast<seconds>(finish - start).count();
//   cout << time_s << " сек" << endl;
//   return 0;

   auto start = steady_clock::now();
   vector<Person> my_list = createPersonList(100000);
   auto finish = steady_clock::now();
   auto ms = duration_cast<seconds>(finish - start).count();
   cout << ms << " sek" << endl;

   start = steady_clock::now();
   printPersonListSize(my_list);
   finish = steady_clock::now();
   ms = duration_cast<milliseconds>(finish - start).count();
   cout << ms << " ms" << endl;
   return 0;
}
