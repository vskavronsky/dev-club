#ifndef WARLOCK_H
#define WARLOCK_H

#include "SpellCaster.h"
#include "../spell/Lightning.h"
#include "../unit/Demon.h"

class Warlock : public SpellCaster {
    public:
        Warlock(const std::string& name = "Amara", int hitPoints = 150, int damage = 25, int mana = 500);
        virtual ~Warlock();

        Demon* summonDemon();

};

std::ostream& operator<<(std::ostream& out, const Warlock* warlock);

#endif // WARLOCK_H
