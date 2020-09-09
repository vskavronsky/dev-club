#ifndef WARLOCK_H
#define WARLOCK_H

#include "SpellCaster.h"
#include "../spell/Lightning.h"

class Warlock : public SpellCaster {
    public:
        Warlock(const std::string& name, int hitPoints, int damage, int mana);
        virtual ~Warlock();
};

std::ostream& operator<<(std::ostream& out, const Warlock* warlock);

#endif // WARLOCK_H
