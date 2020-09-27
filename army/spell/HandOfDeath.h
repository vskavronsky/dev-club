#ifndef HAND_OF_DEATH_H
#define HAND_OF_DEATH_H

#include "Spell.h"
#include "../spellcaster/Priest.h"

class HandOfDeath : public Spell {
    public:
        HandOfDeath(const std::string& name, int actionPoints, int cost);
        virtual ~HandOfDeath();
        
        virtual void action(SpellCaster* owner, Unit* target);

};

std::ostream& operator<<(std::ostream& out, const HandOfDeath* handOfDeath);

#endif // HAND_OF_DEATH_H
