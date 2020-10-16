#include "HandOfDeath.h"

#define PART 2

HandOfDeath::HandOfDeath(const std::string& name, int actionPoints, int cost) : Spell(name, actionPoints, cost) {}

HandOfDeath::~HandOfDeath() {}

void HandOfDeath::action(SpellCaster* owner, Unit* target) {
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

std::ostream& operator<<(std::ostream& out, const HandOfDeath* handOfDeath) {
    return out << (Spell*)handOfDeath;
}
