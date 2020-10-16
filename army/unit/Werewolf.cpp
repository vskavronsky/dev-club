#include "Werewolf.h"

Werewolf::Werewolf(const std::string& name, int hitPoints, int damage) : Unit(name, hitPoints, damage) {
    this->ability = new DefaultAbility(this);
    this->state = new WerewolfState(name, hitPoints, damage);
}

Werewolf::~Werewolf() {}

void Werewolf::scrabble(Unit* enemy) {
    dynamic_cast<WerewolfState*>(this->state)->scrabble(enemy);
}

void Werewolf::transformToWolf() {
    dynamic_cast<WerewolfState*>(this->state)->transformToWolf();
}

std::ostream& operator<<(std::ostream& out, const Werewolf* werewolf) {
    return out << (Unit*)werewolf;
}
