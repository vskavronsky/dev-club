#ifndef UNIT_H
#define UNIT_H

#include "../state/State.h"
#include "../ability/Ability.h"
#include "../interface/Observer.h"
#include "../interface/Observerable.h"

class Ability;

class Unit : public Observer, public Observerable {
    protected:
        State* state;
        Ability* ability;
        
    public:
        Unit(const std::string& name = "John", int hitPoints = 250, int damage = 40);
        virtual ~Unit();

        virtual void ensureIsAlive();

        const std::string& getName() const;
        int getHitPoints() const;
        int getHitPointsLimit() const;
        int getDamage() const;

        State* getState() const;
        Ability* getAbility() const;

        void setState(State* state);
        void setAbility(Ability* ability);

        void addHitPoints(int hp);
        void takeDamage(int dmg);
        virtual void takeMagicDamage(int dmg);

        virtual void attack(Unit* enemy);
        virtual void counterAttack(Unit* enemy);

        bool isUndead() const;
        void turnUndead();
};

std::ostream& operator<<(std::ostream& out, const Unit* unit);

#endif // UNIT_H
