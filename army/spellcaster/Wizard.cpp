#include "Wizard.h"

Wizard::Wizard(const std::string& name, int hitPoints, int damage, int mana):
    SpellCaster(name, hitPoints, damage, mana, true) {
        this->magicAbility = new MagicAbility(this, new FireBall("FireBall", 30, 30));
}

Wizard::~Wizard() {}

std::ostream& operator<<(std::ostream& out, const Wizard* wizard) {
    return out << (SpellCaster*)wizard;    
}
