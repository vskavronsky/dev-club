#ifndef STATE_H
#define STATE_H

#include <iostream>
#include "../exceptions.h"

class State {
    protected:
        std::string name;
        int hitPoints;
        int hitPointsLimit;
        int damage;

        bool undead;

        void _takeDamage(int dmg);

    public:
        State(const std::string& name, int hitPoints, int damage);
        virtual ~State();

        void ensureIsAlive();

        const std::string& getName() const;
        int getHitPoints() const;
        int getHitPointsLimit() const;
        int getDamage() const;

        void addHitPoints(int hp);
        void takeDamage(int dmg);
        void takeMagicDamage(int dmg);

        bool isUndead() const;
        void turnUndead();
};

#endif // STATE_H
