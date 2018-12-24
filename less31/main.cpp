#include <iostream>
#include <string>

using namespace std;


class Person
{
    Person(string f_name, string l_name, int id) :
        first_name(f_name),
        last_name(l_name),
        unic_id(id)
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
};

class SuperPerson : public Person
{
public:
    SuperPerson(string f_name, string l_name, int unic_id, string s_name):
        Person(f_name, l_name, unic_id),
        super_name(s_name)
    {
        cout << "ctor super" << endl;
    }
    ~SuperPerson()
    {
        cout << "dtor super" << endl;
    }
    string getsName() const;
private:
    string super_name;
};

string SuperPerson::getsName() const
{
    return super_name;
}

int main(int argc, char *argv[])
{

    return 0;
}
