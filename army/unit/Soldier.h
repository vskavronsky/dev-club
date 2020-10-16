#ifndef SOLDIER_H
#define SOLDIER_H

#include "Unit.h"
#include "../ability/DefaultAbility.h"

class Soldier : public Unit {
    public:
        Soldier(const std::string& name = "Arthur", int hitPoints = 250, int damage = 40);
        virtual ~Soldier();

};

std::ostream& operator<<(std::ostream& out, const Soldier* soldier);

#endif // SOLDIER_H
