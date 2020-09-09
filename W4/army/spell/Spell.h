#ifndef SPELL_H
#define SPELL_H

#include <iostream>
#include "../unit/Unit.h"
#include "../spellcaster/SpellCaster.h"

class SpellCaster;

class Spell {
    protected:
        std::string name;
        int actionPoints;
        int cost;

    public:
        Spell(const std::string& name, int actionPoints, int cost);
        virtual ~Spell();
        
        const std::string& getName() const;
        int getActionPoints() const;
        int getCost() const;

        virtual void action(SpellCaster* owner, Unit* target) = 0;
};

std::ostream& operator<<(std::ostream& out, const Spell* spell);

#endif // SPELL_H
