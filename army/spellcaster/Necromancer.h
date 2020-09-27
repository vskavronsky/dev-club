#ifndef NECROMANCER_H
#define NECROMANCER_H

#include "SpellCaster.h"
#include "../spell/HandOfDeath.h"

class Necromancer : public SpellCaster {
    public:
        Necromancer(const std::string& name = "Billie", int hitPoints = 150, int damage = 25, int mana = 500);
        virtual ~Necromancer();

        virtual void ensureIsAlive();
        virtual void attack(Unit* enemy);
        virtual void counterAttack(Unit* enemy);
        virtual void cast(Unit* enemy);
        virtual void update(Observerable* victim);

};

std::ostream& operator<<(std::ostream& out, const Necromancer* necromancer);

#endif // NECROMANCER_H
