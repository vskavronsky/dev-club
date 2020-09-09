#include "Heal.h"

Heal::Heal(const std::string& name, int actionPoints, int cost) : Spell(name, actionPoints, cost) {}

Heal::~Heal() {}

void Heal::action(SpellCaster* owner, Unit* target) {
    int coeff = 2;
    if ( owner->isPriest() ) {
        if ( target->isUndead() ) {
            throw InvalidAddHitPointsException();
        }
    }

    owner->spendMana(this->cost);
    if ( !owner->isBattleMagician() ) {
        target->addHitPoints(this->actionPoints);
    } else {
        target->addHitPoints(this->actionPoints / coeff);
    }
}

std::ostream& operator<<(std::ostream& out, const Heal* heal) {
    return out << (Spell*)heal;
}
