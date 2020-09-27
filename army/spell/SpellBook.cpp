#include "SpellBook.h"
#include "FireBall.h"
#include "Lightning.h"
#include "HandOfDeath.h"
#include "Heal.h"
#include "Blessing.h"

SpellBook::SpellBook() {
     this->spellList.emplace(FIRE_BALL, new FireBall("FireBall", 30, 30));
     this->spellList.emplace(LIGHTNING, new Lightning("Lightning", 70, 70));
     this->spellList.emplace(HAND_OF_DEATH, new HandOfDeath("HandOfDeath", 100, 100));
     this->spellList.emplace(HEAL, new Heal("Heal", 50, 50));
     this->spellList.emplace(BLESSING, new Blessing("Blessing", 110, 110));
}

SpellBook::~SpellBook() {
    this->spellList.clear();
}

void SpellBook::getSpellList() const {
    Spell* list;
    std::map<Spells, Spell*>::const_iterator it;
    
    for ( it = this->spellList.cbegin(); it != this->spellList.cend(); it++ ) {
        list = it->second;
        std::cout << list << std::endl;
        delete list;
    }
}

Spell* SpellBook::changeSpell(Spells newSpell) {
    std::map<Spells, Spell*>::iterator it = this->spellList.find(newSpell);
    return it->second;
}
