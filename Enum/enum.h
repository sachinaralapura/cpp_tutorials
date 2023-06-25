/*An enumeration is a user-definable, integral type. An enumeration is defined using the
enum keyword. A range of values and a name for these values are also defined at the
same time.

    Example: enum Shape{ Line, Rectangle, Ellipse};

This statement defines the enumerated type Shape. The names quoted in the list iden-
tify integral constants. Their values can be deduced from the list order. The first constant
has a value of 0, and each subsequent constant has a value that is one higher than its
predecessor.

However, you can also define the values of the constants explicitly.

    Example: enum Bound { Lower = -100, Upper = 100};

You can leave out the type name, if you only need to define the constants.

Example: enum { OFF, OUT=0, ON, IN=1 };
*/
#include <iostream>
using namespace std;

class Lights
{
public:
    enum State
    {
        off,
        red,
        green,
        amber
    };

private:
    State state;

public:
    Lights(State s = off) : state(s) {}

    State getState() const { return state; }
    // set state of the light and print
    void setState(State s)
    {
        switch (s)
        {
        case off:
            cout << "OFF" << endl;
            break;
        case red:
            cout << "RED" << endl;
            break;
        case green:
            cout << "GREEN" << endl;
            break;
        case amber:
            cout << "AMBER" << endl;
            break;
        default:
            return;
            break;
        }
        state = s;
    }
};

// int main(){
//     cout << "Some statements with objects "<< "of type Lights!\n";
//     Lights A1 , A2(Lights::amber);
//     Lights::State as;
//     as = A2.getState();
//     A1.setState(as);
// }