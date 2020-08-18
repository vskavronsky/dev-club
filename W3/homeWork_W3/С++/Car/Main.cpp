#include "Car.h"

using namespace std;

int main() {
    Point x(-10, -80);
    
    Car car(5000, 20, x, "Toyota");
    
    // car.refill(10);
    // cout << "Filled - " << car.getFuelAmount() << endl;
    // car.refill(80);
    // cout << "Filled - " << car.getFuelAmount() << endl;
    car.refill(6000);
    cout << "Filled - " << car.getFuelAmount() << endl;
    // car.refill(1002.83);
    // cout << "Filled - " << car.getFuelAmount() << endl;
    cout << car << endl;
    car.drive(20, 100);
    cout << car << endl;
    
    return 0;
}
