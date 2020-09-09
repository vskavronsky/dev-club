#ifndef BLESSING_H
#define BLESSING_H

#include "Spell.h"

class Blessing : public Spell {
    public:
        Blessing(const std::string& name, int actionPoints, int cost);
        virtual ~Blessing();
        
        virtual void action(SpellCaster* owner, Unit* target);
};

std::ostream& operator<<(std::ostream& out, const Blessing* blessing);

#endif // BLESSING_H
