#ifndef WEREWOLF_H
#define WEREWOLF_H

#include "Unit.h"
#include "../ability/DefaultAbility.h"
#include "../state/WerewolfState.h"

class Werewolf : public Unit {
    public:
        Werewolf(const std::string& name = "Sam", int hitPoints = 250, int damage = 40);
        virtual ~Werewolf();

        virtual void scrabble(Unit* enemy);
        virtual void transformToWolf();

};

std::ostream& operator<<(std::ostream& out, const Werewolf* werewolf);

#endif // WEREWOLF_H
