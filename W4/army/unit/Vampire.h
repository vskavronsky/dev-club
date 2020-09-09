#ifndef VAMPIRE_H
#define VAMPIRE_H

#include "Unit.h"
#include "../ability/DefaultAbility.h"

class Vampire : public Unit {
    public:
        Vampire(const std::string& name, int hitPoints, int damage);
        virtual ~Vampire();

        virtual void bite(Unit* victim);
};

std::ostream& operator<<(std::ostream& out, const Vampire* vampire);

#endif // VAMPIRE_H
