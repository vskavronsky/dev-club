#ifndef WEREWOLF_H
#define WEREWOLF_H

#include "Unit.h"
#include "../ability/DefaultAbility.h"

class Werewolf : Unit {
    public:
        Werewolf(const std::string& name, int hitPoints, int damage);
        virtual ~Werewolf();
};

std::ostream& operator<<(std::ostream& out, const Werewolf* werewolf);

#endif // WEREWOLF_H
