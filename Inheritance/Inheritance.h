/*
Inheritance allows new classes to be constructed on the basis of existing classes. The new
derived class “inherits” the data and methods of the so-called base class. But you can add
more characteristics and functionality to the new class.

    example : To differentiate between vehicle types, various classes are derived from the base class
            Car, such as PassCar, which is used to represent passenger-carrying vehicles. This class
            has additional attributes, such as the number of seats, type, sunroof (yes/no), and various
            additional operations.
 ______________________
|   ■  Is Relationship |
-----------------------
    - An object of the PassCar type "is" a special object of the Car class.
    - we can say that the derived class establishes an "is" relationship to the base class.
    - "is" relation is different then "has" relationship ,
            ex: An Account object "has" a string object to represent the name of the account holder

■ Data Abstraction and Reusability
    data abstaction : general characterstics and abilites can be handled by base , specialization can
                      be handled by derived class.
        re-usable   : perform new tasks ,  the base class implementation need not be known.
 _________________
| ■ Derived class |
|_________________|

    When you define a derived class, the base class, the additional data members and methods,
    and the access control to the base class are defined.

    ■ Access to Public Members in the Base Class
       _________________________________________
      |  class C : public B{                    |
      |      private:                           |
      |          //---------||------------      |
      |      public:                            |
      |          //-----------|| -----------    |
      |  }                                      |
      |_________________________________________|

      - Access privileges to the base "class B" are designated by the "public" keyword that precedes the B
      - all the public members in base "class B" are publicly available in the derived "class C".
      - Thus, objects of the derived class can call the public methods of the base class.

    ■ Access to Private Members of the Base Class
        The private members of the base class are protected in all cases. That is,
            ■the methods of the derived class cannot access the private members of the base class.
        Imagine the consequences if this were not so: you would be able to hack access to the
        base class by simply defining a derived class, thus undermining any protection offered by
        data encapsulation.
        Methods belonging to derived classes only have indirect access to the private data
        members of the base class. They use access methods in the public declaration of the
        base class for this purpose.

    ■ Direct and Indirect Base Classes
        The derived class C can itself be a base class for a further class, D. This allows for class
        hierarchies. Class B then becomes an indirect base class for class D.


    ■ Name Lookup
        ■  the compiler looks for the name of the method called in the derived class first
        ■  if the name cannot be found, the compiler walks one step up the tree and looks for a public method with that name.


■ Redefinition
    There are two options for the names of data members or methods in derived classes:
        - The name does not occur in the base class → no redefinition.
        - The name already exists in the base class → redefinition.
    Redefining members in a derived class has no effect on the base class.
    ■ if a member is redefined in a derived class, it will mask the corresponding member in the base class.
    ■ When a method is redefined, the signature and the return type of the method can be changed.
    ■ However, a redefinition does not overload functions since the derived class has a different scope.
    ■ redefining and overloading are different

■ Access to the Members in the Base Class
    If the method was declared in the public section of the base class, you can call it to redefine a method.
    The range :: operator is used to access the base class method.

■ constructor call
    - As the derived class contains all the members of the base class, the base sub-object must also be created and initialized.
    - base class constructor  is called for this task.
    - the base class constructor is called first ,then the derived class constructor is called.
    - 'Base Initializer' is used to call the constructor of base class in derived class.

■ Destructor call
    - When an object is destroyed, the destructor of the derived class is first called, followed by
      the destructor of the base class. The reverse order of the constructor calls applies.
    - The base class destructor need not be called explicitly as it
      is executed implicitly.

■ PROTECTED MEMBERS
    -To allow methods and friend functions access to the sheltered members of a base class , Proteceted access control is introduced
    - A member declared protected is sheltered from external access just like a private member.
      That means, a protected member is inaccessible for base class objects
      and any classes derived from the base class. However, in contrast to a private member,
      methods and friend functions of derived classes can access the member.

===================================Type Conversion in Class Hierarchies ====================================

■ Implicit Conversion
    - Objects of the derived class type  become special objects of the base class
    - It is possible to assign an object of a derived class to an object of the base class.
      This causes an implicit type conversion to a base class type.

      Implicit type conversion in class hierarchies occurs in assignments to
        ■ base class objects
        ■ pointers or references to the base class.

      Additionally, a similar kind of implicit type conversion takes place for the arguments of function calls.
        Example: bool compare( Car& , Car& );
            function call : compare(bmw , mahindra)
     when you attempt to assign a base class object to an object of a derived class , error!.

  ■ A pointer of the type “pointer to base class,” or base class pointer for short,
    can reference an object of a derived class type.
        Example: Car* carPtr = &Maruti;
  ■ a base class pointer can only access the public interface of the base class.
        ∴ carPtr->getNumberOfDoors();  // is ERROR
  ■ A reference of the type “reference to base class” can point to an object of a derived class.
    The reference will address only the generic part of the object in this case.
    ∴ Car& carRef = Maruti;
      carRef.display(); // outPut base class
      carRef.getNumberOfDoors()  // is ERROR

■ EXPLICIT TYPE CONVERSIONS
    - Type conversions that walk up a class hierarchy, or "upcasts", are always possible and safe.
    - Type conversions that involve walking down the tree, or downcasts, can only be performed
         explicitly by means of a cast construction.the static_cast< > operator are available for this task,
    Example: Car* carPtr = &Maruti;
            ( (PassCar*) carPtr )->display(); // display() of derived class

    - The operator "static_cast<type>(expression)" converts the expression to the target type type.
    Example : static_cast<PassCar*>(carPtr)->display();


*/

// Definition of baseclass Car and of the derived class PassCar
// ------------------------------------------------------------
#include <iostream>
#include <string>
using namespace std;

class Car
{
private:
    long nr;
    string producer;
    string model;
    string engine;
    string color;

protected:
    int secret; // this is directly accessable to derived class methods

public:
    Car(long n = 0L, const string &prod = "", const string &mod = "", const string &eng = "", const string &col = "") // constructor
    {
        this->nr = n;
        this->producer = prod;
        this->model = mod;
        this->engine = eng;
        this->color = col;
    }
    //------------------- getters --------------------------
    long getNr() const { return nr; };
    const string &getProducer() const { return producer; }
    const string &getModel() const { return model; }
    const string &getEngine() const { return engine; }
    const string &getColor() const { return color; }
    // ---------------------- setters -------------------
    void setNr(long nr) { this->nr = nr; }
    void setProducer(const string &prod) { producer = prod; }
    void setModel(const string &mod) { model = mod; }
    void setEngine(const string &eng) { engine = eng; }
    void setColor(const string &col) { color = col; }
    // -------------- display ----------------------------
    friend ostream &operator<<(ostream &os, const Car &c);
    void display() const;
};

void Car::display() const
{
    cout << "NR " << getNr() << endl
         << "producer " << getProducer() << endl
         << "Model " << getModel() << endl
         << "Engine " << getEngine() << endl
         << "Color " << getColor() << endl;
}

//=========================================================================================================================

class passengerCar : public Car
{
private:
    long numberOfDoors;
    int numberOfSeats;
    float milage;
    int safetyRating;

public:
    passengerCar(long numberOfDoors = 4, int numberOfSeats = 5, float milage = 25, int safetyRating = 5,
                 long n = 0L, const string &prod = "", const string &mod = "", const string &eng = "", const string &col = ""); // constructor
    // ------------------------ getters -----------------------------------
    long getNumberOfDoors() const { return numberOfDoors; };
    int getNumberOfSeats() const { return numberOfSeats; }
    float getMilage() const { return milage; }
    int getSafetyRating() const { return safetyRating; }
    // ------------------------------ setters ------------------------------
    void setNumberOfDoors(long numberOfDoors) { this->numberOfDoors = numberOfDoors; }
    void setNumberOfSeats(int numberOfSeats) { this->numberOfSeats = numberOfSeats; }
    void setFuelEfficiency(float fuelEfficiency) { this->milage = milage; }
    void setSafetyRating(int safetyRating) { this->safetyRating = safetyRating; }
    friend ostream &operator<<(ostream &os, const passengerCar &passcar);
    void display() const; // redefining members
};

//-----------------------------------------------------------------------------------------------------------------------------

passengerCar::passengerCar(long numberOfDoors, int numberOfSeats, float milage, int safetyRating,
                           long n, const string &prod, const string &mod, const string &eng,
                           const string &col) : Car(n, prod, mod, eng, col)
{
    this->numberOfDoors = numberOfDoors;
    this->numberOfSeats = numberOfSeats;
    this->milage = milage;
    this->safetyRating = safetyRating;
}

void passengerCar::display() const
{
    Car::display();
    // cout << secret << endl;
    cout << "number of Door " << getNumberOfDoors() << endl
         << "number of seats " << getNumberOfSeats() << endl
         << "Milage " << getMilage() << endl
         << "safety Rating " << getSafetyRating() << endl;
}