#ifndef BERSERKER_H
#define BERSERKER_H

#include "Unit.h"
#include "../ability/DefaultAbility.h"
#include "../state/BerserkerState.h"

class Berserker : public Unit {
    public:
        Berserker(const std::string& name = "Bobby", int hitPoints = 250, int damage = 40);
        virtual ~Berserker();

};

std::ostream& operator<<(std::ostream& out, const Berserker* berserker);

#endif // BERSERKER_H
