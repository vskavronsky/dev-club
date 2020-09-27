#ifndef ROGUE_H
#define ROGUE_H

#include "Unit.h"
#include "../ability/RogueAbility.h"

class Rogue : public Unit {
    public:
        Rogue(const std::string& name = "Ruby", int hitPoints = 250, int damage = 40);
        virtual ~Rogue();

};

std::ostream& operator<<(std::ostream& out, const Rogue* rogue);

#endif // ROGUE_H
