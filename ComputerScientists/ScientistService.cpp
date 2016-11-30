#include "ScientistService.h"

ScientistService::ScientistService()
{
    createScientists();
}

vector<Scientist> ScientistService::getScientists()
{
    return _scientists;
}

void ScientistService::ScientistsOrderByName()
{
    NameComparison cmp;
    std::sort(_scientists.begin(), _scientists.end(), cmp);
}

void ScientistService::ScientistsOrderByDoB()
{
    DoBComparison cmp;
    std::sort(_scientists.begin(), _scientists.end(), cmp);
}

void ScientistService::ScientistsOrderByDoD()
{
    DoDComparison cmp;
    std::sort(_scientists.begin(), _scientists.end(), cmp);
}

void ScientistService::ScientistsOrderByGender()
{
    GenderComparison cmp;
    std::sort(_scientists.begin(), _scientists.end(), cmp);
}

Scientist *ScientistService::findScientistByName(string name)
{
    int n = findScientistName(name);
    if(n != -1){
        return &_scientists.at(n);
    }
    return nullptr;
}

void ScientistService::addScientist(string n, string bd, string dd, string g)
{
    Scientist *s1 = findScientistByName(n);
    if(s1 == nullptr){
        string s2;
        constructString(s2, n, bd, dd, g);
       _data.addScientist(s2);
       Scientist sc(n, bd, dd, g);
       _scientists.push_back(sc);
    }
}

void ScientistService::deleteScientist(string name)
{
    int n = findScientistName(name);
    if(n != -1){
        _scientists.erase(_scientists.begin()+n);
        string s;
        for(size_t i = 0; i < size(); i++)
        {
            Scientist sc = _scientists.at(i);
            string n = sc.getName();
            string bd = sc.getBirthDate();
            string dd = sc.getDeathDate();
            string g = sc.getGender();
            constructString(s, n, bd, dd, g);
            if(i != size()-1)
            {
               s.push_back('\n');
            }
        }
        _data.deleteScientist(s);
    }
}
//Private
int ScientistService::findScientistName(string name)
{
    Scientist s;

    for(unsigned int i = 0; i < size(); i++){
        s = _scientists.at(i);
        if(s.getName() == name){
            return i;
        }
    }
    return -1;
}

void ScientistService::createScientists()
{
    vector<string> list = _data.getData();
    int count = 1;
    string name, dob, dod, g;
    for(size_t i = 0; i < list.size(); i++){
        if(count == 1){
            name = list.at(i);
        }
        if(count == 2){
            name+= list.at(i);
        }
        if(count == 3){
            dob = list.at(i);
        }
        if(count == 4){
            dod = list.at(i);
        }
        if(count == 5){
            g = list.at(i);
            Scientist sc(name, dob, dod, g);
            _scientists.push_back(sc);
            count = 0;
        }
        count++;
    }
}

void ScientistService::constructString(string& s, string name, string dob, string dod, string g)
{
    s+=name;
    s.push_back('\t');
    s+=dob;
    s.push_back('\t');
    s+=dod;
    s.push_back('\t');
    s+=g;
}

size_t ScientistService::size()
{
    return _scientists.size();
}