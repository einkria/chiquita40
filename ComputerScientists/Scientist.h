#ifndef SCIENTIST_H
#define SCIENTIST_H
#include <string>
#include <iostream>

using namespace std;


class Scientist
{
private:
    string _name;
    string _birthDate;
    string _deathDate;
    string _gender;
public:
    Scientist();
    Scientist(string n, string bd, string dd, string g);
    string getName() const;
    string getBirthDate() const;
    string getDeathDate() const;
    string getGender() const;
    friend ostream& operator << (ostream& out, const Scientist s);

};

#endif // SCIENTIST_H