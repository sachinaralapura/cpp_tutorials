#include <iostream>
#include <string>
using namespace std;
class MistBorn
{
public:
    string allomancy;
    int age;
    string name;

public:
    MistBorn(const string &name, int age, const string &allomancy);
    ~MistBorn();
    void setName(const string &name);
    string getName() const;
};

MistBorn::MistBorn(const string &name, int age, const string &allomancy)
{
    this->name = name;
    this->age = age;
    this->allomancy = allomancy;
}

MistBorn::~MistBorn()
{
}

void MistBorn::setName(const string &name)
{
    this->name = name;
}

string MistBorn::getName() const {
    return this->name;
}
int main()
{
    MistBorn mistbornArr[10] = {
        MistBorn("Mistborn 1", 20, "Allomancy 1"),
        MistBorn("Mistborn 2", 22, "Allomancy 2"),
        MistBorn("Mistborn 3", 25, "Allomancy 3"),
        MistBorn("Mistborn 4", 28, "Allomancy 4"),
        MistBorn("Mistborn 5", 30, "Allomancy 5"),
        MistBorn("Mistborn 6", 32, "Allomancy 6"),
        MistBorn("Mistborn 7", 35, "Allomancy 7"),
        MistBorn("Mistborn 8", 38, "Allomancy 8"),
        MistBorn("Mistborn 9", 40, "Allomancy 9"),
        MistBorn("Mistborn 10", 42, "Allomancy 10")};

    const MistBorn *ptrMist;
    for (ptrMist = mistbornArr; ptrMist < mistbornArr + 10; ptrMist++)
    {
        cout << "Name : " << ptrMist->name << " age : " << (*ptrMist).age << " allomancy : " << ptrMist->allomancy << endl;
        cout << "----------------------------------------------------------\n";
    }

    // MistBorn Vin("vin",21,"Mistborn");  // c
    // const MistBorn *ptrVin ;
    // ptrVin = mistbornArr;            
    // ptrVin->getName();
}