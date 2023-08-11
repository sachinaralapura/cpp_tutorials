/*
Given a base class pointer, carPtr, the statement
    Example: carPtr->display();
should output all the data members of the object currently being referenced.

In C++, "virtual" methods are used to implement polymorphic classes. Calling a "virtual" method
makes the compiler execute a version of the method suitable for the object
in question, when the object is accessed by a pointer or a reference to the base class!

■ Declaring "Virtual" Methods
    The "virtual" keyword is used to declare a "virtual" method in a base class.
        Example: "virtual" void display() const;
    -A "virtual" method does not need to be redefined in the derived class. The derived class
    then inherits the "virtual" method from the base class.
    -However, it is common practice for the derived class to define its own version of the "virtual" method,
    -Creating a proprietary version of a "virtual" method should have same signature and return value as base class virtual method
    -can omit the "virtual" keyword in derived class redefination
    -constructors cannot have a virtual declaration

■ DESTROYING DYNAMICALLY ALLOCATED OBJECTS
    -Dynamically created objects in a class hierarchy are normally handled by a base class
     pointer. When such an object reaches the end of its lifetime, the memory occupied by the object
     must be released by a delete statement.
     When memory is released, the destructor for an object is automatically called. If multiple
     constructors were called to create the object, the corresponding destructors are called in
     reverse order. What does this mean for objects in derived classes? The destructor of the
     derived class is called first and then the destructor of the base class executed.
     If you use a base class pointer to manage an object, the appropriate virtual methods of
     the derived class are called. However, non-virtual methods will always execute the base
     class version.
     -A class used as a base class for other classes should always have a virtual destructor defined.

■ VIRTUAL METHOD TABLE
    ■ Static Binding
        -When a non-virtual method is called, the address of the function is known at time of compilation.
        The address is inserted directly into the machine code. This is also referred to as "static" or "early binding".
            If a virtual method is called via an object’s name, the appropriate version of this
        method is also known at time of compilation. So this is also a case of "early binding".
    ■  Dynamic Binding
        However, if a virtual method is called by a pointer or reference, the function that will be executed
        when the program is run is unknown at time of compilation. The statement
            _____________________________
           | Example: carPtr->display(); |
           |_____________________________|

        could execute different versions of the display() method, depending on the objectcurrently referenced
        by the pointer. The compiler is therefore forced to create machine code that does not
        form an association with a particular function until the program is run.
        This is referred to as late or "dynamic binding."

    ■ VMT
        -Dynamic binding is supported internally by virtual method tables (or VMT for short). A VMT is created
        for each class with at least one virtual method—that is, an array with the addresses of the virtual methods
        in the current class.

■ DYNAMIC CASTS
    -Given that "carPtr" is a pointer to the base class "Car", which is currently pointing to a "PassCar" type, the statement
        Example: Truck * truckPtr = static_cast<Truck*>(carPtr);
    will not cause a compiler error. But the following statement,
            truckPtr->setAxles(10);
    could cause the program to crash.

    ■ The dynamic_cast<> Operator
        You can use the cast operator dynamic_cast<> to perform safe downcasting in polymorphic classes.
        At runtime the operator checks whether the required conversion is valid or not.

        Given a pointer carPtr to the base class Car, the statement
            Example: Truck* truckPtr = dynamic_cast<Truck*>(carPtr);
        performs a downcast to the derived Truck class, provided the pointer carPtr really identifies a Truck type object.
        If this is not so, the dynamic_cast<Truck> operator will return a NULL pointer.

*/

#include <iostream>
#include <cstring>
using namespace std;
class Car
{
public:
    Car() { cout << "constructor of base class " << endl; }
    virtual ~Car() { cout << "destructor of base class" << endl; }
    virtual void honk() { cout << "rom rom bhaio" << endl; }
};

//------------------------------------------------------------------

class SportCar : public Car
{
private:
    char *name;

public:
    SportCar(const char *n)
    {
        name = new char[strlen(n) + 1];
        strcpy(name, n);
        cout << "constructor of derived class " << endl;
    }

    ~SportCar()
    {
        cout << "destructor of derived class " << endl;
        delete[] name;
    } // implicit virtual
    void honk() { cout << " system paad beenge" << endl; }
};