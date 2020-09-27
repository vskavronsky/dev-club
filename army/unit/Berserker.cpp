#include "Berserker.h"

Berserker::Berserker(const std::string& name, int hitPoints, int damage) : Unit(name, hitPoints, damage) {
    this->ability = new DefaultAbility(this);
    this->state = new BerserkerState(name, hitPoints, damage);
}

Berserker::~Berserker() {}

std::ostream& operator<<(std::ostream& out, const Berserker* berserker) {
    return out << (Unit*)berserker;
}
