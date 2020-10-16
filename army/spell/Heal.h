#ifndef HEAL_H
#define HEAL_H

#include "Spell.h"
#include "../spellcaster/Priest.h"

class Heal : public Spell {
    public:
        Heal(const std::string& name, int actionPoints, int cost);
        virtual ~Heal();
        
        virtual void action(SpellCaster* owner, Unit* target);

};

std::ostream& operator<<(std::ostream& out, const Heal* heal);

#endif // HEAL_H
