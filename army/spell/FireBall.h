#ifndef FIRE_BALL_H
#define FIRE_BALL_H

#include "Spell.h"
#include "../spellcaster/Priest.h"

class FireBall : public Spell {
    public:
        FireBall(const std::string& name, int actionPoints, int cost);
        virtual ~FireBall();
        
        virtual void action(SpellCaster* owner, Unit* target);

};

std::ostream& operator<<(std::ostream& out, const FireBall* fireball);

#endif // FIRE_BALL_H
