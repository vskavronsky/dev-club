#include "Vampire.h"

Vampire::Vampire(const std::string& name, int hitPoints, int damage) : Unit(name, hitPoints, damage) {
    this->ability = new VampireAbility(this);
    turnUndead();
}

Vampire::~Vampire() {}

void Vampire::bite(Unit* enemy) {
    dynamic_cast<VampireAbility*>(this->ability)->bite(enemy);
}

std::ostream& operator<<(std::ostream& out, const Vampire* vampire) {
    return out << (Unit*)vampire;
}
