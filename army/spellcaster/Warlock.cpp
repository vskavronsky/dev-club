#include "Warlock.h"

#define PORTION 3

Warlock::Warlock(const std::string& name, int hitPoints, int damage, int mana):
    SpellCaster(name, hitPoints, damage, mana, true) {
        this->magicAbility = new MagicAbility(this, new Lightning("Lightning", 70, 70));
}

Warlock::~Warlock() {}

Demon* Warlock::summonDemon() {
    Demon* demon = new Demon();
    return demon;
}

std::ostream& operator<<(std::ostream& out, const Warlock* warlock) {
    return out << (SpellCaster*)warlock;
}
