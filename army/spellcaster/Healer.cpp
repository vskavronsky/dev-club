#include "Healer.h"

Healer::Healer(const std::string& name, int hitPoints, int damage, int mana):
    SpellCaster(name, hitPoints, damage, mana, false) {
        this->magicAbility = new MagicAbility(this, new Heal("Heal", 50, 50));
}

Healer::~Healer() {}

std::ostream& operator<<(std::ostream& out, const Healer* healer) {
    return out << (SpellCaster*)healer;
}
