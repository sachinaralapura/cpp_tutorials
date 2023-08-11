#include "poly.h"

int main(){
    Car* carptr = new SportCar("supra");
    Car* gtr = new Car();
    gtr->honk();        
    
    carptr->honk();
    delete carptr;
}