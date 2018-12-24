#include <iostream>
#include <string>

using namespace std;

class Person
{
public:
    Person(string f_name, string l_name, int id) : first_name(f_name),
        last_name(l_name), unic_id(id)
    {
        cout << "ctor" << endl;
    }

    ~Person()
    {
        cout << "dtor" << endl;
    }

    string getName() const;
    int getUnicId() const;
private:
    string first_name;
    string last_name;
    int unic_id;
};

string Person::getName() const
{
    return first_name + " " + last_name;
}

int Person::getUnicId() const
{
    return unic_id;
}

int main()
{
    {
        Person pr("rrrr", "xxxx", 0);
        cout << pr.getName();
        cout << endl;
        cout << pr.getUnicId();
        cout << endl;
    }

    Person pr("qqq", "www", 0);
    cout << pr.getName();
    cout << endl;
    cout << pr.getUnicId();
    cout << endl;


    return 0;
}
