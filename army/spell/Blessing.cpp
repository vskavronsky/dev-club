#include "Blessing.h"

#define PART 2

Blessing::Blessing(const std::string& name, int actionPoints, int cost) : Spell(name, actionPoints, cost) {}

Blessing::~Blessing() {}

void Blessing::action(SpellCaster* owner, Unit* target) {
    bool isAlive = target->getHitPoints() > 0;

    if ( isAlive ) {
        if ( typeid(*owner) == typeid(Priest) ) {
            if ( target->isUndead() ) {
                throw InvalidAddHitPointsException("Priest cannot heal undead!");
            }
        }

        owner->spendMana(this->cost);
        if ( !owner->isBattleMagician() ) {
            target->addHitPoints(this->actionPoints);
        } else {
            target->addHitPoints(this->actionPoints / PART);
        }
    } else {
        target->ensureIsAlive();
    }
}

std::ostream& operator<<(std::ostream& out, const Blessing* blessing) {
    return out << (Spell*)blessing;
}
