#include "SpellCaster.h"

SpellCaster::SpellCaster(const std::string& name, int hitPoints, int damage, int mana, bool battleMagician, bool priest)
    : Unit(name, hitPoints, damage), magicState(new MagicState(mana, battleMagician, priest)) {
        this->ability = new DefaultAbility(this);
    }

SpellCaster::~SpellCaster() {
    delete(this->magicState);
    delete(this->magicAbility);
}

int SpellCaster::getMana() const {
    return this->magicState->getMana();
}

int SpellCaster::getManaLimit() const {
    return this->magicState->getManaLimit();
}

bool SpellCaster::isBattleMagician() const {
    return this->magicState->isBattleMagician();
}

bool SpellCaster::isPriest() const {
    return this->magicState->isPriest();
}

void SpellCaster::addMana(int extra) {
    this->magicState->addMana(extra);
}

void SpellCaster::spendMana(int cost) {
    this->magicState->spendMana(cost);
}

void SpellCaster::getSpell() const {
    this->magicAbility->getSpell();
}

void SpellCaster::getSpellList() const {
    this->magicAbility->getSpellList();
}

void SpellCaster::changeSpell(Spells newSpell) {
    this->magicAbility->changeSpell(newSpell);
}

void SpellCaster::cast(Unit* enemy) {
    this->magicAbility->cast(enemy);
}

std::ostream& operator<<(std::ostream& out, const SpellCaster* spellCaster) {
    out << "Characteristics of the spellCaster:\n"
        << "Name - " << spellCaster->getName() << ".\n"
        << "Max hit points - " << spellCaster->getHitPointsLimit() << ".\n"
        << "Hit points - " << spellCaster->getHitPoints() << ".\n"
        << "Max mana points - " << spellCaster->getManaLimit() << ".\n"
        << "Mana points - " << spellCaster->getMana() << ".\n"
        << "Physical Damage - " << spellCaster->getDamage() << ".";
        
    return out;
}
