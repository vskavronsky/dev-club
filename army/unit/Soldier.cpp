#include "Soldier.h"

Soldier::Soldier(const std::string& name, int hitPoints, int damage) : Unit(name, hitPoints, damage) {
    this->ability = new DefaultAbility(this);
}

Soldier::~Soldier() {}

std::ostream& operator<<(std::ostream& out, const Soldier* soldier) {
    return out << (Unit*)soldier;
}
