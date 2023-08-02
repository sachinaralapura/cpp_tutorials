
// To overload an operator, you just define an appropriate operator function. The operator
// function describes the actions to be performed by the operator. The name of an operator
// function must begin with the operator keyword followed by the operator symbol.

// An "operator function" can be defined as a global function or as a class method. Generally
// , operator functions are defined as methods

// Operator Functions as Methods
//     If you define the "operator function" of a binary operator as a method, the left operand will
//      always be an object of the class in question.
//      The second, right operand is passed as an argument to the method.
//   example : bool operator<( const DayTime& t) const;

// Difference between 'Operator function' as Member Functions and Global Functions
// ==>>  When an operator function is implemented as a member function, the leftmost(or only)
//       operand must be an object(or a reference to an object) of the operator's class.
//       If the left operand must be an object of a different class or a fundamental type,
//       this operator function must be implemented as a global function

//==>>  The operands for a global operator function are passed as arguments to that function.

//==>>  'operator function' as Member functions use the 'this' pointer implicitly to obtain one of their class object arguments
//      (the left operand for binary operators). Arguments for both operands of a binary operator must
//      be explicitly listed in a global function call.

//==>>   However, a global function cannot access the private members of the class.

//==>>  A global operator function can be declared as a “friend” of the class to allow it access
//      to the private members of that class.

//-------------------------------------- Friend function ------------------------------------------

//          >If functions or individual classes are used in conjunction with another class, you may
//      want to grant them access to the private members of that class. This is made possible
//      by a friend declaration
//          >The friend keyword must precede the function prototype in the class definition.

//         _____________________________________________________________
//        |  Example: class A                                           |
//        |                {                                            |
//        |                 friend void globFunc( A* objPtr);           |
//        |                 friend int B::elFunc( const A& objRef);     |
//        |                };                                           |
//        |_____________________________________________________________|

//          Here the global function globFunc() and the method elFunc() of class B are
//        declared as friend functions of class A. This allows them direct access to the private
//        members of class A. Since these functions are not methods of class A, the 'this' pointer is
//        not available to them. To resolve this issue, you will generally pass the object the func-
//        tion needs to process as an argument.

// -------------------------------------------- Friend Class -----------------------------------------
//          you can also make entire classes “friends” of another class. All the methods in this “friend” class automatically become
//          friend functions in the class containing the friend declaration.
//         _____________________________________________________________
//        |  Example: class Result                                      |
//        |               {                                             |
//        |                  . . .                                      |
//        |                  friend class ControlPoint;                 |
//        |                };                                           |
//        |_____________________________________________________________|

// ------------------------------- Type conversion for classes ---------------------------------------
//          a constructor with only one parameter is referred to as a conversion constructor.
//          The copy constructor is an exception to this rule: it
//          creates an object of the same class and does not perform type conversion.
//          The standard string class contains a constructor that creates a string object
//              from a C string, for example.
//                      ______________________________________________
//                     |                                              |
//                     | Example: string::string( const char* );      |
//                     |         string str = string("c - string");   |
//                     |______________________________________________|

// ------------------------------------------- Defining Conversion Functions --------------------------------
//              If you need to convert an object of the current class to another type, you must define a
//              conversion function to do so.
//              A conversion function is always implemented as a method of the current class.
//              Its name is made up of the 'operator' keyword and the target type to convert to.
//               _____________________________________________
//              |                                             |
//              |  Example: operator int(void) const;         |
//              |_____________________________________________|

//              The previous statement declares a conversion function where the target type is 'int'

// ----------------------------------- ambiguities in type conversions ------------------------------------

//              The Rupee class contains a conversion constructor that converts a double value to
//              rupee. This means that the following statement is valid for two objects.
//                  retail = wholesale + 46.9; // 46.9 is converted to Rupee implicity;
//
//              If you now additionally implement the conversion function
//               __________________
//              |operator double() |
//              |__________________|
//              that converts a Rupee to a double value,the previous statement can no longer be compiled.
//              because two possible conversion can be performed , hence ambigious
#include <iostream>
#include <string>

using namespace std;

class Rupee
{
private:
    long Data;

public:
    Rupee()
    {
        Data = 0;
        cout << "default constructor called " << endl;
    };
    /*explicit*/ Rupee(double); // a constructor with only one parameter is referred to as a conversion constructor.
                                // The copy constructor is an exception to aboves rule
    Rupee(int rupee, int paise = 0);
    ~Rupee(){};

    // get and set methods
    long getData() const { return Data; }
    long getWhole() const { return Data / 100; }
    int getPaise() const { return Data % 100; }
    double getAsDouble() const { return (double)Data / 100; }
    string asString() const;
    void setData(int);
    void print(ostream &) const;

    // ----------------- operator functions -----------------------

    Rupee operator-() const; /// unary negation
    // Rupee operator+(const Rupee &rupee2) const;  // 'operator function' of the operator + is Implemented as "Global operator function"
    Rupee operator-(const Rupee &rupee2) const;
    Rupee operator+=(const Rupee &rupee2);
    Rupee operator-=(const Rupee &rupee2);

    //-------------------- friend functions ---------------------------

    friend Rupee operator*(const Rupee &e1, const Rupee &e2); // overRiding operator using 'friend function'
    friend Rupee operator/(const Rupee &e1, const Rupee &);
    // friend Rupee operator*(const Rupee& e1, double x);

    // ------------------------ Friend Class --------------------------
    friend class Ledger; // every method of ledger class is friend of Rupee class;

    // ------------------------------------- conversion functions ------------------------------
    //  For conversion from Rupees to double:

    // operator double() const { return (double)Data/100.0;} // this would be ambigious
};

// ------------------------------------ Global operator function ---------------------------

inline Rupee operator+(const Rupee &e1, const Rupee &e2)
{
    Rupee temp(e1); // global 'operator function' are passed the object of class
    temp += e2;     // this function cannot access the Private members of the class,
    return temp;    // if we declare this function as friend in class definition it can access.
}

// -------------------------- friend function definition --------------------------

inline Rupee operator*(const Rupee &e1, const Rupee &e2)
{
    // long x=e1.Data;
    // private members of class are availabe to this function
    Rupee temp((double)(e1.Data * e2.Data)); // copy constructor
    return temp;
}

inline Rupee operator/(const Rupee &e1, const Rupee &e2)
{
    Rupee temp((double)e1.Data / e2.Data);
    return temp;
}
