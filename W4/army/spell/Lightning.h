#ifndef LIGHTNING_H
#define LIGHTNING_H

#include "Spell.h"

class Lightning : public Spell {
    public:
        Lightning(const std::string& name, int actionPoints, int cost);
        virtual ~Lightning();
        
        virtual void action(SpellCaster* owner, Unit* target);
};

std::ostream& operator<<(std::ostream& out, const Lightning* lightning);

#endif // LIGHTNING_H
