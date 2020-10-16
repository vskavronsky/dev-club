#include "State.h"

#define DEAD 0

State::State(const std::string& name, int hitPoints, int damage) {
    if ( hitPoints < 0 ) {
        hitPoints = 0;
    }
    if ( damage < 0 ) {
        damage = 0;
    }

    this->name = name;
    this->hitPoints = hitPoints;
    this->hitPointsLimit = hitPoints;
    this->damage = damage;
    this->undead = false;
    this->transformed = false;
}

State::~State() {}

void State::ensureIsAlive() {
    if ( this->hitPoints == 0 ) {
        throw OutOfHitPointsException(this->getName(), " is dead. Game over!");
    }
}

const std::string& State::getName() const {
    return this->name;
}

int State::getHitPoints() const {
    return this->hitPoints;
}

int State::getHitPointsLimit() const {
    return this->hitPointsLimit;
}

int State::getDamage() const {
    return this->damage;
}

void State::addHitPoints(int hp) {
    this->ensureIsAlive();

    int total = this->hitPoints + hp;
    if ( total > this->hitPointsLimit ) {
        this->hitPoints = this->hitPointsLimit;
        return;
    }
    this->hitPoints = total;
}

void State::_takeDamage(int dmg) {
    this->ensureIsAlive();

    if ( dmg > this->hitPoints ) {
        this->hitPoints = DEAD;
        return;
    }
    this->hitPoints -= dmg;
}

void State::takeDamage(int dmg) {
    this->_takeDamage(dmg);
}

void State::takeMagicDamage(int dmg) {
    this->_takeDamage(dmg);
}

bool State::isUndead() const {
    return this->undead;
}

void State::turnUndead() {
    this->undead = true;
}

bool State::isTransformed() const {
    return this->transformed;
}

void State::setTransformed(bool state) {
    this->transformed = state;
}
