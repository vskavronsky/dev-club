#include "BerserkerState.h"

#define NOMAGICDAM 0

BerserkerState::BerserkerState(const std::string& name, int hitPoints, int damage) : State(name, hitPoints, damage) {}

BerserkerState::~BerserkerState() {}

void BerserkerState::takeMagicDamage(int dmg) {
    dmg *= NOMAGICDAM;
}
