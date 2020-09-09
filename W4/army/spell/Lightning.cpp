#include "Lightning.h"

Lightning::Lightning(const std::string& name, int actionPoints, int cost) : Spell(name, actionPoints, cost) {}

Lightning::~Lightning() {}

void Lightning::action(SpellCaster* owner, Unit* target) {
    int coeff = 2;

    owner->spendMana(this->cost);
    if ( owner->isBattleMagician() ) {
        target->takeMagicDamage(this->actionPoints);
    } else {
        if ( owner->isPriest() ) {
            if ( target->isUndead() ) {
                target->takeMagicDamage(this->actionPoints * coeff);
            }
        }
        target->takeMagicDamage(this->actionPoints / coeff);
    }
}

std::ostream& operator<<(std::ostream& out, const Lightning* lightning) {
    return out << (Spell*)lightning;
}
