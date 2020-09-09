#include "MagicAbility.h"

MagicAbility::MagicAbility(SpellCaster* owner, Spell* spell)
    : owner(owner), spell(spell) {
        this->spellbook = new SpellBook();
    }

MagicAbility::~MagicAbility() {
    delete(this->spell);
}

void MagicAbility::getSpell() const {
    std::cout << this->spell << std::endl;
}

void MagicAbility::getSpellList() const {
    this->spellbook->getSpellList();
}

void MagicAbility::changeSpell(Spells newSpell) {
    delete(this->spell);
    this->spell = this->spellbook->changeSpell(newSpell);
}

void MagicAbility::cast(Unit* enemy) {
    this->owner->ensureIsAlive();
    this->spell->action(this->owner, enemy);
}
