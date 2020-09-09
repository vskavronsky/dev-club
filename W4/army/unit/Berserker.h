#ifndef BERSERKER_H
#define BERSERKER_H

#include "Unit.h"
#include "../ability/DefaultAbility.h"

class Berserker : public Unit {
    public:
        Berserker(const std::string& name, int hitPoints, int damage);
        virtual ~Berserker();

        virtual void takeMagicDamage(int dmg);
};

std::ostream& operator<<(std::ostream& out, const Berserker* berserker);

#endif // BERSERKER_H
