#include "Demon.h"
#include "../spellcaster/Warlock.h"

Demon::Demon(const std::string& name, int hitPoints, int damage) : Soldier(name, hitPoints, damage) {}

Demon::~Demon() {}

void Demon::attack(Unit *enemy) {
    if ( typeid(*enemy) == typeid(Warlock) ) {
        throw  CanNotAttackOwnerException("Demon cannot attack his master!");
    }
    Soldier::attack(enemy);
}
