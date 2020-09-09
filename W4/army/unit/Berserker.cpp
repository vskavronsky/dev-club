#include "Berserker.h"

Berserker::Berserker(const std::string& name, int hitPoints, int damage) : Unit(name, hitPoints, damage) {
    this->ability = new DefaultAbility(this);
}

Berserker::~Berserker() {}

void Berserker::takeMagicDamage(int dmg) {
    dmg *= 0;
}

std::ostream& operator<<(std::ostream& out, const Berserker* berserker) {
    return out << (Unit*)berserker;
}
