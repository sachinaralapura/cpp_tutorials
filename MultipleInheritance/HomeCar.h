/*
 _____                              _____
| Car |                            | Car |
|_____|.....                  ..... ------
            |                 |
         ___|______         __|__
        | PassCar |        | Van |
               |              |
               |.....   ......|
                    |   |
                   _|___|_
                  |  SUV  |
                  '-------'

-A class can be derived from several classes that have a common base class, however.
    This class is then referred to as a multiple indirect base class.
■ Ambiguity
    - An object of the SUV class thus contains the members of Car twice. Access to members
      of the Car class results in ambiguity.

    To resolve ambiguity of this kind, you can use the scope resolution operator to determine which base class is meant.
        Example: cout << motorHome.Home::getNr();
                 cout << mySUV.PassCar::getProd();



■ VIRTUAL BASE CLASSES

you can define multiply-derived classes that will contain only one instance of an indirect base class.
C++ uses virtual base classes to do this.
    A direct base class is declared virtual when a derived class is defined. You can use the virtual keyword,
 which directly precedes the name of the base class.A virtual base class takes effect in cases of multiple inheritance

■ INITIALIZING VIRTUAL BASE CLASSES
    - When an object is created for a multiply-derived class, the constructors of the base classes are called first.
    - The constructors of the virtual base classes are called first, followed by the constructors of non-virtual
      base classes in the order defined in the inheritance graph.
      The constructor of the virtual base class nearest the top of the inheritance graph is
      executed first. This does not necessarily mean the top level of the class hierarchy, since a
      virtual base class can be derived from a non-virtual base class.
    - If the base classes PassCar and Van also contained base initializers for the virtual base class Car, these
      would be ignored too.
    - If the constructor for the last derived class does not contain a base initializer, the default constructor is executed
      for each virtual base class. Whatever happens, a default constructor must then exist in every virtual base class!
*/

#include <iostream>
using namespace std;
class Car
{
private:
    int Nr;
    int wheels;
    string engine;

public:
    Car(int nr, int wheels, const string &engine) : Nr(nr), wheels(wheels), engine(engine) {}
    int getWheels() const { return wheels; }
    int getNr() const { return Nr; }
};  

class Home
{
private:
    int HomeNumber;
    int doors;
    string type;

public:
    Home(int HomeNo, int door, const string &type) : HomeNumber(HomeNo), doors(door), type(type) {}
    int getDoors() const { return doors; }
    int getNr() const { return HomeNumber; }
};

class HomeCar : public Car, private Home
{

public:
    HomeCar(int nr, int wheels, const string &engine, int HomeNo, int door, const string &type) : Car(nr, wheels, engine), Home(HomeNo, door, type) {}
};

//================================================================================
