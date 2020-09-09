#include "Necromancer.h"

Necromancer::Necromancer(const std::string& name, int hitPoints, int damage, int mana):
    SpellCaster(name, hitPoints, damage, mana, true, false) {
        this->magicAbility = new MagicAbility(this, new HandOfDeath("HandOfDeath", 200, 200));
        turnUndead();
}

Necromancer::~Necromancer() {}

std::ostream& operator<<(std::ostream& out, const Necromancer* necromancer) {
    return out << (SpellCaster*)necromancer;
}
