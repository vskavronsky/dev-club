#ifndef VAMPIRE_H
#define VAMPIRE_H

#include "Unit.h"
#include "../ability/VampireAbility.h"

class Vampire : public Unit {
    public:
        Vampire(const std::string& name = "Dean", int hitPoints = 250, int damage = 40);
        virtual ~Vampire();

        virtual void bite(Unit* enemy);

};

std::ostream& operator<<(std::ostream& out, const Vampire* vampire);

#endif // VAMPIRE_H
