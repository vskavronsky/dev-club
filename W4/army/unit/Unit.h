#ifndef UNIT_H
#define UNIT_H

#include "../state/State.h"
#include "../ability/Ability.h"

class Ability;

class Unit {
    protected:
        State* state;
        Ability* ability;
        
    public:
        Unit(const std::string& name, int hitPoints, int damage);
        virtual ~Unit();

        void ensureIsAlive();

        const std::string& getName() const;
        int getHitPoints() const;
        int getHitPointsLimit() const;
        int getDamage() const;

        void addHitPoints(int hp);
        void takeDamage(int dmg);
        void takeMagicDamage(int dmg);

        virtual void attack(Unit* enemy);
        virtual void counterAttack(Unit* enemy);

        bool isUndead() const;
        void turnUndead();
};

std::ostream& operator<<(std::ostream& out, const Unit* unit);

#endif // UNIT_H
