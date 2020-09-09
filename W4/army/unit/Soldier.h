#ifndef SOLDIER_H
#define SOLDIER_H

#include "Unit.h"
#include "../ability/DefaultAbility.h"

class Soldier : public Unit {
    public:
        Soldier(const std::string& name, int hitPoints, int damage);
        virtual ~Soldier();
};

std::ostream& operator<<(std::ostream& out, const Soldier* soldier);

#endif // SOLDIER_H
