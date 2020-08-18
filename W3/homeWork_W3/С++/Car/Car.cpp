#include "Car.h"

using namespace std;

Car::Car(double capacity, double consumption, const Point& location, const string& model) {
    this->fuelAmount = 0;
    this->fuelCapacity = capacity;
    this->fuelConsumption = consumption;
    this->location = location;
    this->model = model;
}

Car::~Car() {
    
}

double Car::getFuelAmount() const {
    return this->fuelAmount;    
}

double Car::getFuelCapacity() const {
    return this->fuelCapacity;    
}

double Car::getFuelConsumption() const {
    return this->fuelConsumption;
}

const Point& Car::getLocation() const {
    return this->location;
}

const string& Car::getModel() const {
    return this->model;
}

void Car::drive(const Point& destination) {
    double neededFuel;
    
    if ( this->fuelConsumption <= 0 ) {
        cout << "You entered incorrect fuel consumption!" << endl;
        return;
    }
    neededFuel = this->location.distance(destination) * this->fuelConsumption;
    
    try {
        if ( this->fuelAmount == 0 ) {
            throw OutOfFuel();
        }
        if ( this->fuelAmount < neededFuel ) {
            cout << "Can't move! Needed fuel for travel is " << neededFuel << " liters." << endl;
            return;
        }
        
        this->fuelAmount -= neededFuel;
        this->fuelCapacity -= this->fuelAmount;
        this->location = destination;
    }
    catch (const OutOfFuel& exception) {
        cout << "Your fuel tank is empty! Needed fuel for travel is " << neededFuel << " liters." << endl;
    }
}

void Car::drive(double x, double y) {
    this->drive(Point(x, y));
}

void Car::refill(double fuel) {
    try {
        if ( this->fuelCapacity <= 0 ) {
            cout << "You entered incorrect tank capacity!" << endl;
            return;
        }
        if ( this->fuelAmount + fuel > this->fuelCapacity ) {
            this->fuelAmount = this->fuelCapacity;
            throw ToMuchFuel();
        } else if ( fuel < 0 ) {
            this->fuelAmount = 0;
            return;
        }   
        this->fuelAmount += fuel;
    }
    catch (const ToMuchFuel& exception) {
        cout << "To much fuel! Your fuel tank is full." << endl;
    }
}

ostream& operator<<(ostream& out, const Car& car) {
    out << "Characteristics of the car:\n"
        << "The model of car - " << car.getModel() << ".\n"
        << "The car location - " << car.getLocation() << ".\n"
        << "Fuel amount - " << car.getFuelAmount() << " liters.\n"
        << "Tank capacity - " << car.getFuelCapacity() << " liters.\n"
        << "Fuel consumption - " << car.getFuelConsumption() << " liters.";
    
    return out;
}
