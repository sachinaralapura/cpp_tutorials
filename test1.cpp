/*
#include <iostream>
#include <iomanip>
#include <cmath>
#define PI 3.142;
#define HEADER
#define HEADER (cout << " ***** Sine Function Table *****\n\n");
#define PRINT(x) (cout << x << endl);

using namespace std;

int main(){
    int x = 22;
    HEADER;
    for(int x = 1;x < 11 ; x++)
        PRINT(x);
    cout << setw(20) << setfill('-') <<  x << endl;
}

*/
// ball1.cpp
// Simulates a bouncing ball
// ---------------------------------------------------
#include <iostream>
#include <string>
using namespace std;
#define DELAY 10000000L  // Output delay
#define CLS (cout << "\033[2J]") // Clear screen
#define LOCATE(z,s) (cout <<"\033["<< z <<';'<< s <<'H')   // Position the cursor in row z and column s
int main()
{
int x = 2, y = 3, dx = 1, speed = 0;
string floor(79, '-'),
header = "**** JUMPING BALL ****";
CLS;
LOCATE(1,25);
LOCATE(25,1);
cout << header;
cout << floor;
while(true)
// Let the ball "always" bounce
{
// Terminate by interrupt key (^C)
LOCATE(y,x); 
cout << 'o' << endl; // Show the ball
for( long wait = 0; wait < DELAY; ++wait)
;
if(x == 1 || x == 79) dx = -dx;
// Bounce off
// a wall?
if( y == 24 )
// On the floor?
{
speed = - speed;
if( speed == 0 ) speed = -7;
// Restart
}
speed += 1;
// Acceleration = 1
LOCATE(y,x); cout << ' ';
// Clear output
y += speed; x += dx;
// New Position
}
return 1;
}
