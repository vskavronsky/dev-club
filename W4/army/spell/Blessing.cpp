#include "Blessing.h"

Blessing::Blessing(const std::string& name, int actionPoints, int cost) : Spell(name, actionPoints, cost) {}

Blessing::~Blessing() {}

void Blessing::action(SpellCaster* owner, Unit* target) {
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

std::ostream& operator<<(std::ostream& out, const Blessing* blessing) {
    return out << (Spell*)blessing;
}
