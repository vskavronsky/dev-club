#include "Warlock.h"

Warlock::Warlock(const std::string& name, int hitPoints, int damage, int mana):
    SpellCaster(name, hitPoints, damage, mana, true, false) {
        this->magicAbility = new MagicAbility(this, new Lightning("Lightning", 70, 70));
}

Warlock::~Warlock() {}

std::ostream& operator<<(std::ostream& out, const Warlock* warlock) {
    return out << (SpellCaster*)warlock;
}
