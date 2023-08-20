#include "HomeCar.h"

int main(int argc, char const *argv[])
{
    HomeCar *hc = new HomeCar(12, 23, "v8", 332, 2, "old");
    cout << (*hc).Car::getNr();
    cout << hc->getWheels();
    return 0;
}
