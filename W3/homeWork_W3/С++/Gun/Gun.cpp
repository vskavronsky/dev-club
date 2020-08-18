#include "Gun.h"

#define BULLET 1 
#define SHOOT 1

using namespace std;

Gun::Gun(const string& model, int capacity) {
    this->amount = 0;
    this->capacity = capacity;
    this->isReady = false;
    this->model = model;
    this->totalShots = 0;
}

Gun::~Gun() {
    
}

int Gun::getAmount() const {
    return this->amount;    
}

int Gun::getCapacity() const {
    return this->capacity;
}

bool Gun::ready() const {
    return this->isReady;
}

const string& Gun::getModel() const {
    return this->model;
}

int Gun::getTotalShots() const {
    return this->totalShots;
}

void Gun::prepare() {
    this->isReady = !this->isReady;
}

void Gun::reload() {
    if ( this->capacity <= 0 ) {
        cout << "You entered incorrect magazine capacity!" << endl;
        return;
    }
    this->amount = this->capacity;
}

void Gun::shoot() {
    if ( !this->ready() ) {
        throw NotReady();
    }
    if ( this->amount == 0 ) {
        throw OutOfRounds();
    }
    cout << "Bang!" << endl;
    this->amount -= BULLET;
    this->totalShots += SHOOT;
}

ostream& operator<<(ostream& out, const Gun& gun) {
    out << "Characteristics of the gun:\n" 
        << "The gun model - " << gun.getModel() << ".\n"
        << "Ready to shoot - " << gun.ready() << ".\n"
        << "Bullets quantity - " << gun.getAmount() << ".\n"
        << "Magazine capacity - " << gun.getCapacity() << ".\n"
        << "Total shots - " << gun.getTotalShots() << ".";
        
        return out;   
}
