#include "Werewolf.h"

Werewolf::Werewolf(const std::string& name, int hitPoints, int damage) : Unit(name, hitPoints, damage) {
    this->ability = new DefaultAbility(this);
}

Werewolf::~Werewolf() {}

std::ostream& operator<<(std::ostream& out, const Werewolf* werewolf) {
    return out << (Unit*)werewolf;
}
