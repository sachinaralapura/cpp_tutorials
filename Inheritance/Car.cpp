#include "Inheritance.h"
Car baseCar;
passengerCar car1(4, 5, 25, 5, 1233L, "Maruti", "Suzuki Swift", "1.2L K12B petrol", "Red");
passengerCar car2(5, 7, 30, 4, 1234L, "Hyundai", "Creta", "1.5L Nu petrol", "Black");

int main(int argc, char const *argv[])
{
    // car1.Car::display();
    cout << "--------- Maruti car-----------------" << endl;
    car1.display();
    cout << "----------Hyundai ----------------" << endl;
    car2.display();

    baseCar = car2;
    cout << "--------- implicit assignment-----------------" << endl;
    baseCar.display();

    Car *carPtr;
    carPtr = &car2;
    cout << "-------------------- explicit convertion ---------------" << endl;
    static_cast<passengerCar *>(carPtr)->display();
    return 0;
}
