#ifndef SPELLBOOK_H
#define SPELLBOOK_H

#include <map>
#include "SpellEnum.h"

class Spell;
class Blessing;
class FireBall;
class HandOfDeath;
class Heal;
class Lightning;

class SpellBook {
    protected:
        std::map<Spells, Spell*> spellList;
        
    public:
        SpellBook();
        virtual ~SpellBook();
        
        void getSpellList() const;
        Spell* changeSpell(Spells newSpell);
    
};

#endif // SPELLBOOK_H
