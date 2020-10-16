#ifndef BERSERKERSTATE_H
#define BERSERKERSTATE_H

#include "State.h"

class BerserkerState : public State {
    public:
        BerserkerState(const std::string& name, int hitPoints, int damage);
        virtual ~BerserkerState();

        virtual void takeMagicDamage(int dmg);

};

#endif // BERSERKERSTATE_H
