#include "VampireAbility.h"

#define PORTION 10
#define PART 2

VampireAbility::VampireAbility(Unit* owner) : Ability(owner) {}

VampireAbility::~VampireAbility() {}

void VampireAbility::attack(Unit* enemy) {
    this->owner->ensureIsAlive();
    enemy->takeDamage(this->owner->getDamage());
    enemy->counterAttack(this->owner);
    this->owner->addHitPoints(this->owner->getHitPointsLimit() / PORTION);
}

void VampireAbility::counterAttack(Unit* enemy) {
    this->owner->ensureIsAlive();
    enemy->takeDamage(this->owner->getDamage() / PART);
    this->owner->addHitPoints(this->owner->getHitPointsLimit() / PORTION);
}

void VampireAbility::bite(Unit *enemy) {
    State& tempState = *(enemy->getState());
    if ( typeid(tempState) == typeid(WerewolfState) ) {
        throw CanNotTurnException("Werewolf cannot be turned into vampire!");
    }
    delete enemy->getAbility();
    enemy->setAbility(new VampireAbility(enemy));
}
