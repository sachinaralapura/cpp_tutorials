#include <iostream>
using namespace std;

enum State{
    off,
    red,
    green,
    amber
};

State state = red;
int main(){
    cout << state << endl;
    cout << amber << endl;
    return 0;
}