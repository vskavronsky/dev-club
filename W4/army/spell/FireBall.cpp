#include "FireBall.h"

FireBall::FireBall(const std::string& name, int actionPoints, int cost) : Spell(name, actionPoints, cost) {}

FireBall::~FireBall() {}

void FireBall::action(SpellCaster* owner, Unit* target) {
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

std::ostream& operator<<(std::ostream& out, const FireBall* fireball) {
    return out << (Spell*)fireball;
}
