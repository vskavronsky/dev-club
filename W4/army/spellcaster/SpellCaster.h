#ifndef SPELL_CASTER_H
#define SPELL_CASTER_H

#include "../unit/Unit.h"
#include "../ability/MagicAbility.h"
#include "../state/MagicState.h"
#include "../ability/DefaultAbility.h"
#include "../spell/SpellEnum.h"

class MagicAbility;

class SpellCaster: public Unit {
    protected:
        MagicState* magicState;
        MagicAbility* magicAbility;

    public:
        SpellCaster(const std::string& name, int hitPoints, int damage, int mana, bool battleMagician, bool priest);
        virtual ~SpellCaster();

        int getMana() const;
        int getManaLimit() const;
        bool isBattleMagician() const;
        bool isPriest() const;

        void addMana(int extra);
        void spendMana(int cost);
        
        void getSpell() const;
        void getSpellList() const;
        
        void changeSpell(Spells newSpell);
        virtual void cast(Unit* enemy);

};

std::ostream& operator<<(std::ostream& out, const SpellCaster* spellCaster);

#endif // SPELL_CASTER_H
