#include "Necromancer.h"

#define PORTION 10

Necromancer::Necromancer(const std::string& name, int hitPoints, int damage, int mana):
    SpellCaster(name, hitPoints, damage, mana, true) {
        this->magicAbility = new MagicAbility(this, new HandOfDeath("HandOfDeath", 100, 100));
        turnUndead();
}

Necromancer::~Necromancer() {}

void Necromancer::ensureIsAlive() {
    if ( this->getHitPoints() == 0 ) {
        this->notifyObserverable();
    }
    SpellCaster::ensureIsAlive();
}

void Necromancer::attack(Unit* enemy) {
    SpellCaster::attack(enemy);
    this->addObserverable(enemy);
    enemy->addObserver(this);
}

void Necromancer::counterAttack(Unit* enemy) {
    SpellCaster::counterAttack(enemy);
    this->addObserverable(enemy);
    enemy->addObserver(this);
}

void Necromancer::cast(Unit* enemy) {
    SpellCaster::cast(enemy);
    this->addObserverable(enemy);
    enemy->addObserver(this);
}

void Necromancer::update(Observerable* victim) {
    this->addHitPoints(this->getHitPointsLimit() / PORTION);
    Observer::update(victim);
}

std::ostream& operator<<(std::ostream& out, const Necromancer* necromancer) {
    return out << (SpellCaster*)necromancer;
}
