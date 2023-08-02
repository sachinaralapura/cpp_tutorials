#include "Rupee.h"

Rupee::Rupee(double rupee)
{
    rupee *= 100.0;
    Data = (long)(rupee >= 0.0 ? rupee + 0.5 : rupee - 0.5);
}

Rupee::Rupee(int rupee, int paise)
{
    Data = 100 * (long)rupee + paise;
}

string Rupee::asString() const
{
    return to_string(Data);
}

void Rupee::setData(int data)
{
    this->Data = data;
}

void Rupee::print(ostream &os) const
{
    os << "₹ " << getWhole() << "." << abs(getPaise()) << endl;
}

Rupee Rupee::operator-() const
{ // negation unary
    Rupee temp;
    temp.Data = -Data;
    return temp;
}
Rupee Rupee::operator-(const Rupee &rupee2) const
{
    Rupee temp;
    temp.Data = this->Data + rupee2.Data;
    return temp;
}

// Rupee Rupee::operator+(const Rupee &rupee2) const
// { // addition binary operator
//     Rupee temp;
//     temp.Data = this->Data + rupee2.Data;
//     return temp;
// }

Rupee Rupee::operator+=(const Rupee &rupee2)
{
    this->Data += rupee2.Data;
    return *this;
}

Rupee Rupee::operator-=(const Rupee &rupee2)
{
    this->Data -= rupee2.Data;
    return *this;
}

// ---------------------------- overloading shift-operators ( global operator function) -----------------------------

ostream &operator<<(ostream &os, const Rupee &rup)
{
    os << "-----------------------------------\n"
       << endl;
    os << rup.getWhole() << " Rupees" << endl;
    os << rup.getPaise() << " paise" << endl;
    return os;
}

istream &operator>>(istream &is, Rupee &e)
{
    cout << "Rupees amount (Format ...x,xx): ";
    int rupee = 0, paise = 0;
    char c = 0;
    if (!(is >> rupee >> c >> paise)) // Input.
        return is;
    if ((c != ',' && c != '.') || paise >= 100)
        is.setstate(ios::failbit); // Error?
    else                           // Yes => Set
        e = Rupee(rupee, paise);   // fail bit.
    return is;                     // No => Accept
                                   // value.
}
// To allow these functions to access the private members of the Euro class, you can add a friend declaration within the class
