#include "Spell.h"

Spell::Spell(const std::string& name, int actionPoints, int cost):
    name(name), actionPoints(actionPoints), cost(cost) {}

Spell::~Spell() {}

const std::string& Spell::getName() const {
    return this->name;
}

int Spell::getActionPoints() const {
    return this->actionPoints;
}

int Spell::getCost() const {
    return this->cost;
}

std::ostream& operator<<(std::ostream& out, const Spell* spell) {
    out << "Characteristics of the spell:\n"
        << "Spell name - " << spell->getName() << ".\n"
        << "Spell damage - " << spell->getActionPoints() << ".\n"
        << "Spell cost - " << spell->getCost() << ".";
        
    return out;
}
