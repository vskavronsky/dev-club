#ifndef WEREWOLFSTATE_H
#define WEREWOLFSTATE_H

#include "State.h"
#include "../ability/VampireAbility.h"

class WerewolfState : public State {
    public:
        WerewolfState(const std::string& name = "Sam", int hitPoints = 200, int damage = 30);
        virtual ~WerewolfState();

        virtual void takeMagicDamage(int dmg);
        virtual void scrabble(Unit* enemy);
        virtual void transformToWolf();

};

#endif // WEREWOLFSTATE_H
