#include "Unit.h"

using namespace std;

void Unit::ensureIsAlive() {
    if ( this->hitPoints == 0 ) {
        throw UnitIsDead();
    }
}

Unit::Unit(const string& name, int hp, int dmg) {
    if ( hp < 0 ) {
        hp = 0;
    }
    if ( dmg < 0 ) {
        dmg = 0;
    }
    this->name = name;
    this->hitPointsLimit = hp;
    this->hitPoints = hp;
    this->damage = dmg;
}

Unit::~Unit() {
    
}

int Unit::getDamage() const {
    return this->damage;
}

int Unit::getHitPoints() const {
    return this->hitPoints;
}

int Unit::getHitPointsLimit() const {
    return this->hitPointsLimit;
}

const string& Unit::getName() const {
    return this->name;
}

void Unit::addHitPoints(int hp) {
    this->ensureIsAlive();
    
    if ( hp < 0 ) {
        hp = 0;
    }
    if ( this->hitPoints + hp > this->hitPointsLimit ) {
        this->hitPoints = this->hitPointsLimit;
        return;
    }
    this->hitPoints += hp;
}

void Unit::takeDamage(int dmg) {
    this->ensureIsAlive();
    
    if ( dmg < 0 ) {
        dmg = 0;
    }
    if ( this->hitPoints < dmg ) {
        this->hitPoints = 0;
        return;
    }
    this->hitPoints -= dmg;
}

void Unit::attack(Unit& enemy) {
    this->ensureIsAlive();
    enemy.takeDamage(this->damage);
    enemy.counterAttack(*this);
}

void Unit::counterAttack(Unit& enemy) {
    this->ensureIsAlive();
    enemy.takeDamage(this->damage / 2);
}

ostream& operator<<(ostream& out, const Unit& unit) {
    out << "Characteristics of the warrior:\n"
        << "Name - " << unit.getName() << ".\n"
        << "Max hit points - " << unit.getHitPointsLimit() << ".\n"
        << "Hit points - " << unit.getHitPoints() << ".\n"
        << "Damage - " << unit.getDamage() << ".";
        
    return out;
}
