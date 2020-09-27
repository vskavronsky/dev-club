#include "Rogue.h"

Rogue::Rogue(const std::string& name, int hitPoints, int damage) : Unit(name, hitPoints, damage) {
    this->ability = new RogueAbility(this);
}

Rogue::~Rogue() {}

std::ostream& operator<<(std::ostream& out, const Rogue* rogue) {
    return out << (Unit*)rogue;
}
