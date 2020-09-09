#include "Priest.h"

Priest::Priest(const std::string& name, int hitPoints, int damage, int mana):
    SpellCaster(name, hitPoints, damage, mana, false, true) {
        this->magicAbility = new MagicAbility(this, new Blessing("Blessing", 100, 100));
}

Priest::~Priest() {}

std::ostream& operator<<(std::ostream& out, const Priest* priest) {
    return out << (SpellCaster*)priest;
}
