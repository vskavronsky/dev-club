#include "Ability.h"

#define PART 2

Ability::Ability(Unit* owner): owner(owner) {}

Ability::~Ability() {}

void Ability::attack(Unit* enemy) {
    this->owner->ensureIsAlive();
    enemy->takeDamage(this->owner->getDamage());
    enemy->counterAttack(this->owner);
}

void Ability::counterAttack(Unit* enemy) {
    this->owner->ensureIsAlive();
    enemy->takeDamage(this->owner->getDamage() / PART);
}
