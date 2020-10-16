#include "Lightning.h"

#define PART 2

Lightning::Lightning(const std::string& name, int actionPoints, int cost) : Spell(name, actionPoints, cost) {}

Lightning::~Lightning() {}

void Lightning::action(SpellCaster* owner, Unit* target) {
    bool isAlive = target->getHitPoints() > 0;

    if ( isAlive ) {
        owner->spendMana(this->cost);

        if ( owner->isBattleMagician() ) {
            target->takeMagicDamage(this->actionPoints);
        } else {
            if ( typeid(*owner) == typeid(Priest) ) {
                if ( target->isUndead() ) {
                    target->takeMagicDamage(this->actionPoints * PART);
                    return;
                }
            }
            target->takeMagicDamage(this->actionPoints / PART);
        }
    } else {
        target->ensureIsAlive();
    }
}

std::ostream& operator<<(std::ostream& out, const Lightning* lightning) {
    return out << (Spell*)lightning;
}
