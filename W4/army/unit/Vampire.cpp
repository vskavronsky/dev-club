#include "Vampire.h"

Vampire::Vampire(const std::string& name, int hitPoints, int damage) : Unit(name, hitPoints, damage) {
    this->ability = new DefaultAbility(this);
    turnUndead();
}

Vampire::~Vampire() {}

void Vampire::bite(Unit *victim) {
    delete victim;
    victim = NULL;
    victim = new Vampire("Greg", 50, 10);
}

std::ostream& operator<<(std::ostream& out, const Vampire* vampire) {
    return out << (Unit*)vampire;
}
