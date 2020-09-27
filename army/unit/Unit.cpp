#include "Unit.h"

Unit::Unit(const std::string& name, int hitPoints, int damage):
    state(new State(name, hitPoints, damage)) {}

Unit::~Unit() {
    delete(this->state);
    delete(this->ability);
}

void Unit::ensureIsAlive() {
    if ( this->getHitPoints() == 0 ) {
        this->notifyObserver();
    }
    this->state->ensureIsAlive();
}

const std::string& Unit::getName() const {
    return this->state->getName();
}

int Unit::getHitPoints() const {
    return this->state->getHitPoints();
}

int Unit::getHitPointsLimit() const {
    return this->state->getHitPointsLimit();
}

int Unit::getDamage() const {
    return this->state->getDamage();
}

State* Unit::getState() const {
    return this->state;
}

Ability* Unit::getAbility() const {
    return this->ability;
}

void Unit::setState(State* state) {
    this->state = state;
}

void Unit::setAbility(Ability* ability) {
    this->ability = ability;
}

void Unit::addHitPoints(int hp) {
    this->state->addHitPoints(hp);
}

void Unit::takeDamage(int dmg) {
    this->state->takeDamage(dmg);
}

void Unit::takeMagicDamage(int dmg) {
    this->state->takeMagicDamage(dmg);
}

void Unit::attack(Unit* enemy) {
    this->ability->attack(enemy);
}

void Unit::counterAttack(Unit* enemy) {
    this->ability->counterAttack(enemy);
}

bool Unit::isUndead() const {
    return this->state->isUndead();
}

void Unit::turnUndead() {
    this->state->turnUndead();
}

std::ostream& operator<<(std::ostream& out, const Unit* unit) {
    out << "Characteristics of the warrior:\n"
        << "Name - " << unit->getName() << ".\n"
        << "Max hit points - " << unit->getHitPointsLimit() << ".\n"
        << "Hit points - " << unit->getHitPoints() << ".\n"
        << "Damage - " << unit->getDamage() << ".";
        
    return out;
}
