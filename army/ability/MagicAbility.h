#ifndef MAGIC_ABILITY_H
#define MAGIC_ABILITY_H

#include "../spell/Spell.h"
#include "../spell/SpellBook.h"
#include "../spellcaster/SpellCaster.h"

class SpellCaster;

class MagicAbility {
    protected:
        SpellCaster* owner;
        Spell* spell;
        SpellBook* spellbook;

    public:
        MagicAbility(SpellCaster* owner, Spell* spell);
        virtual ~MagicAbility();
        
        void getSpell() const;
        void getSpellList() const;
        
        void changeSpell(Spells newSpell);
        virtual void cast(Unit* enemy);

};

#endif // MAGIC_ABILITY_H
