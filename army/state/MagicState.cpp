#include "MagicState.h"

MagicState::MagicState(int mana, bool battleMagician) {
    if ( mana < 0 ) {
        mana = 0;
    }

    this->mana = mana;
    this->manaLimit = mana;
    this->battleMagician = battleMagician;
}

MagicState::~MagicState() {}

int MagicState::getMana() const {
    return this->mana;
}

int MagicState::getManaLimit() const {
    return this->manaLimit;
}

bool MagicState::isBattleMagician() const {
    return this->battleMagician;
}

void MagicState::addMana(int extra) {
    int total = this->mana + extra;
    if ( total > this->manaLimit ) {
        this->mana = this->manaLimit;
        return;
    }
    this->mana = total;
}

void MagicState::spendMana(int cost) {
    if ( cost > this->mana ) {
        throw OutOfManaException("Not enough mana for cast!");
    }
    this->mana -= cost;
}
