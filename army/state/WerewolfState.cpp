#include "WerewolfState.h"

#define INCREASE 1.5

WerewolfState::WerewolfState(const std::string& name, int hitPoints, int damage) : State(name, hitPoints, damage) {}

WerewolfState::~WerewolfState() {}

void WerewolfState::takeMagicDamage(int dmg) {
    if ( State::isTransformed() ) {
        State::takeMagicDamage(dmg * INCREASE);
    } else {
        State::takeMagicDamage(dmg);
    }
}

void WerewolfState::scrabble(Unit* enemy) {
    Ability& tempAbility = *(enemy->getAbility());
    if ( typeid(tempAbility) == typeid(VampireAbility) ) {
        throw CanNotTurnException("Vampire cannot be turned into werewolf!");
    }
    delete enemy->getState();
    enemy->setState(new WerewolfState());
}

void WerewolfState::transformToWolf() {
    if ( State::isTransformed() ) {
        throw CanNotTransformException("Werewolf in a wolf state now!");
    } else {
        State::setTransformed(true);
        this->hitPointsLimit *= INCREASE;
        this->hitPoints *= INCREASE;
        this->damage *= INCREASE;
    }
}
