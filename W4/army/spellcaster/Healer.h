#ifndef HEALER_H
#define HEALER_H

#include "SpellCaster.h"
#include "../spell/Heal.h"

class Healer : public SpellCaster {
    public:
        Healer(const std::string& name, int hitPoints, int damage, int mana);
        virtual ~Healer();
};

std::ostream& operator<<(std::ostream& out, const Healer* healer);

#endif // HEALER_H
