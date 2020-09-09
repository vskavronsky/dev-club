#ifndef NECROMANCER_H
#define NECROMANCER_H

#include "SpellCaster.h"
#include "../spell/HandOfDeath.h"

class Necromancer : public SpellCaster {
    public:
        Necromancer(const std::string& name, int hitPoints, int damage, int mana);
        virtual ~Necromancer();
};

std::ostream& operator<<(std::ostream& out, const Necromancer* necromancer);

#endif // NECROMANCER_H
