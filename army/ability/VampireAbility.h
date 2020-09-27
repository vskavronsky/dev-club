#ifndef VAMPIREABILITY_H
#define VAMPIREABILITY_H

#include "Ability.h"
#include "../state/WerewolfState.h"

class VampireAbility : public Ability {
    public:
        VampireAbility(Unit* owner);
        virtual ~VampireAbility();

        virtual void attack(Unit* enemy);
        virtual void counterAttack(Unit* enemy);
        virtual void bite(Unit* enemy);

};

#endif // VAMPIREABILITY_H
